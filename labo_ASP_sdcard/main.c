/*---------------------------------------------------------------------------------------
* But               : Petit programme pour etre charge dans le micro et affiche avec dump
* Auteur            : Evangelina LOLIVIER-EXLER
* Date              : 29.07.2008
* Version           : 1.0
* Fichier           : demo.c
*----------------------------------------------------------------------------------------*/
#include <stdio.h>

#include "cfg.h"
#include "stddefs.h"
#include "lcd_toolbox.h"
#include "lcd.h"
#include "init.h"
#include "gpio_toolbox.h"
#include "bits.h"
#include "sd_toolbox.h"
//#include "applications.h"


/* Global variables */

vulong AppStack_svr[APPSTACKSIZE/4];
vulong AppStack_irq[APPSTACKSIZE/4];
int t[8];

void general_init();

/* main */
int main(void)
{
	const char s[] = "Les fleurs d'oranger au parfum d'orient.\n\t\tCette douleur que j'ai en mangeant de l'origan.\rtest";


	fb_print_string((uchar*)s, 200, 100, 15);

	display_sd_info();

	while(1){
		/*if(SWIsPressed(1)){
			SetLed(1);
			start_timer();	// �tape 4
		}
		else
			ResetLed(1);*/

		//sprintf(s, "%d", timerValueWhenInterrupt);
		//fb_print_string(s, 200, 300, 15);
	}

	return(0);
}

void general_init()
{
	lcd_off();
	lcd_init();
	lcd_on();
	mmc1_init();

	// pour etape 2 - GPIO
	GPIO_init();
}
