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
#include "timer_toolbox.h"
#include "applications.h"


/* Global variables */

vulong AppStack_svr[APPSTACKSIZE/4];
vulong AppStack_irq[APPSTACKSIZE/4];
int t[8];

void general_init();

/* main */
int main(void)
{
	const char s[] = "Les fleurs d'oranger au parfum d'orient.\n\t\tCette douleur que j'ai en mangeant de l'origan.\rtest";
	general_init();
	clear_screen();

	jeuDeReaction();

	fb_set_pixel(50, 50, 3);
	fb_set_pixel(51, 50, 3);
	fb_set_pixel(50, 51, 3);
	fb_set_pixel(51, 51, 3);


	fb_print_char('K', 100, 100, 15);
	fb_print_char('F', 100, 300, 15);

	fb_print_string((uchar*)s, 700, 200, 15);

	// allumer led 0
	uchar module = 5;
	ClearOutput(module, 0xffffffff);
	// dont forget to change makefile

	while(1){
		if(SWIsPressed(1)){
			SetLed(1);
			start_timer();	// �tape 4
		}
		else
			ResetLed(1);

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

	// pour etape 2 - GPIO
	GPIO_init();

	// pour etape 3 - interruption
	interrupt_init();

	// pour �tape 4 - timer
	timer_init();
}
