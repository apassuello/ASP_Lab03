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
#include <string.h>
#include <stdio.h>

#define FONT_WIDTH		8
#define FONT_HEIGHT 	16


ulong line_nb,current_y;
uchar lcd_line[CHAR_PER_LINE];

/* data buffer, size : 10 clusters, 1 cluster = 8 blocks of 512 B */
uchar buff[MAX_FILE_SIZE];


int create_file(char *file_name,uchar *data,ulong nbyte)
{

	return 0;
}





/* path is "" for the root directory */
void scan_files (char* path)
{
   
}

int read_file(char *file_name)
{

	clear_screen();
	fb_print_string((uchar *) "read_file : Function not implemented",20, 20, lcd_fg_color);

    return 0;
}


int print_file_info(char *file_name)
{

	clear_screen();
	fb_print_string((uchar *) "print_file_info : Function not implemented",20, 20, lcd_fg_color);

	return 0;
}

int run_app(char *file_name)
{

	clear_screen();
	fb_print_string((uchar *) "run_app : Function not implemented",20, 40, lcd_fg_color);

	return 0;
}
