/*
 * fat_toolbox.c
 *
 *  Created on: 12 nov. 2012
 *      Author: Evangelina Lolivier-Exler
 */

#include "stddefs.h"
#include "ff.h"
#include "lcd_toolbox.h"
#include "lcd.h"
#include "fat_toolbox.h"
#include "mmchs.h"
#include <string.h>
#include <stdio.h>

#define FONT_WIDTH		8
#define FONT_HEIGHT 	16


ulong line_nb,current_y;
uchar lcd_line[CHAR_PER_LINE];

/* data buffer, size : 10 clusters, 1 cluster = 8 blocks of 512 B */
uchar buffer[MAX_FILE_SIZE];


int create_file(char *file_name,uchar *data, ulong nbyte)
{
	if(nbyte > 8*SD_BLOCK_LENGTH) return 1;

	// File creation
	FIL file;
	f_open(&file, file_name, FA_CREATE_ALWAYS | FA_WRITE);


	// File write
	WORD nBytes = *(WORD*) nbyte, nWritten;
	f_write(&file, (void*) data, nBytes, &nWritten);

	f_close(&file);

	return 0;
}

int line = 300;

/* path is "" for the root directory */
void scan_files (char* path)
{
    FILINFO finfo;
    DIR dirs;
    int i;
	char str[100];

    if (f_opendir(&dirs, path) == FR_OK) {
        i = strlen(path);
        while ((f_readdir(&dirs, &finfo) == FR_OK) && finfo.fname[0]) {
            if (finfo.fattrib & AM_DIR) {
                sprintf(path+i, "/%s", &finfo.fname[0]);
                scan_files(path);
                *(path+i) = '\0';
            } else {
            	sprintf(str, "%s/%s\n", path, &finfo.fname[0]);
            	fb_print_string(str, 150, line, 15);
            	line += 16;
            }
        }
    }
}

int read_file(char *file_name)
{
	FIL fsrc;
	WORD nCharRed = 8*SD_BLOCK_LENGTH;
	char buffer[8*SD_BLOCK_LENGTH];
	int line = 20;

	clear_screen();

	// error if file doesn't exist
	f_open(&fsrc, file_name, FA_OPEN_EXISTING | FA_READ);

	while(nCharRed >= 8*SD_BLOCK_LENGTH){
		f_read(&fsrc, buffer, 8*SD_BLOCK_LENGTH, &nCharRed);
		buffer[nCharRed] = '\0';
		fb_print_string(buffer,20, line, lcd_fg_color);

		line += 16;
	}

	f_close(&fsrc);

    return 0;
}


int print_file_info(char *file_name)
{
	FILINFO filinfo;
	char str[100];

	f_stat(file_name, &filinfo);

	clear_screen();

	if(filinfo.fsize == 0){
		fb_print_string("Directory not supported",20, line, lcd_fg_color);
		return 1;
	}

	sprintf(str, "File name : %s", filinfo.fname);
	fb_print_string(str,20, 20, lcd_fg_color);

	sprintf(str, "File size : %d octet", filinfo.fsize);
	fb_print_string(str,20, 36, lcd_fg_color);

	// bit15:9 Year origin from 1980 (0..127)
	// bit8:5 Month (1..12)
	// bit4:0 Day (1..31)
	WORD date_unformatted = filinfo.fdate;
	WORD date_year = date_unformatted >> 9;
	WORD date_month = (date_unformatted & 0x1e0) >> 5;
	WORD date_day = date_unformatted & 0x1f;

	// bit15:11 Hour (0..23)
	// bit10:5 Minute (0..59)
	// bit4:0 Second / 2 (0..29)
	WORD time_unformatted = filinfo.ftime;
	WORD time_h = time_unformatted >> 11;
	WORD time_m = (time_unformatted & 0x7e0) >> 5;
	WORD time_s = time_unformatted & 0x1f;

	sprintf(str, "Last modification : %d/%d/%d %d:%d:%d", date_year + 1980, date_month, date_day,
		time_h, time_m, time_s);
	fb_print_string(str,20, 52, lcd_fg_color);

	sprintf(str, "%s : %s", "Read Only", filinfo.fattrib & 0x01 ? "yes" : "no");
	fb_print_string(str,20, 68, lcd_fg_color);

	sprintf(str, "%s : %s", "Hidden", filinfo.fattrib & 0x02 ? "yes" : "no");
	fb_print_string(str,20, 84, lcd_fg_color);

	sprintf(str, "%s : %s", "Sys.File", filinfo.fattrib & 0x04 ? "yes" : "no");
	fb_print_string(str,20,100, lcd_fg_color);

	sprintf(str, "%s : %s", "Vol.Label", filinfo.fattrib & 0x08 ? "yes" : "no");
	fb_print_string(str,20,116, lcd_fg_color);

	sprintf(str, "%s : %s", "SubDir", filinfo.fattrib & 0x10 ? "yes" : "no");
	fb_print_string(str,20,132, lcd_fg_color);

	sprintf(str, "%s : %s", "Archive", filinfo.fattrib & 0x20 ? "yes" : "no");
	fb_print_string(str,20,148, lcd_fg_color);
	
	return 0;
}

int run_app(char *file_name)
{

	clear_screen();
	fb_print_string((uchar *) "run_app : Function not implemented",20, 40, lcd_fg_color);

	return 0;
}

