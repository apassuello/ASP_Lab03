/* ----------------------------------------------------------------------
  Institut ReDS - HEIG-VD Yverdon-les-Bains
 ------------------------------------------------------------------------

 Auteur : Evangelina LOLIVIER-EXLER
 Email  : evangelina.lolivier-exler@heig-vd.ch
 Date   : 17/09/2008
 Modified: 24/05/2012 REPTAR board adaptation
 Description : LCD toolbox
 -----------------------------------------------------------------------
*/

#include "stddefs.h"
#include "lcd.h"
#include "vga_lookup.h"
#include "fb_fonts.h"
#include "gpio.h"
#include "prcm.h"
#include "bits.h"

#define LINES_PER_SCREEN	(PIXELS_PER_COL/FONT_HEIGHT)


// globals to keep track of foreground, background colors and x,y position
uchar lcd_color_depth=16;	// 16 bits per pixel
uchar lcd_bg_color=3;		// 0 to 15, used as lookup into VGA color table
uchar lcd_fg_color=8;		// 0 to 15, used as lookup into VGA color table



//------------------------------------------------------------------------------
// Delay for some usecs. - Not accurate
// and no Cache
void udelay(int delay)
{
  volatile int i;
  for ( i = LOOPS_PER_USEC * delay; i ; i--)
	;
}



///--------------------------------------------------------------------------
// lcd_on
//
// This function turns on the DM3730 Display Controller
//
void lcd_on()
{

  // Enable the clocks to the DISPC
  // enable functional clock (will be enable with the LCD_on function)
  DSS_CM_REG(CM_FCLKEN)|=BIT0;
  // enable interfaces clocks (L3 and L4)  (will be enable with the LCD_on function)
  DSS_CM_REG(CM_ICLKEN)|=BIT0;

  // power up the LCD
  udelay(10000);
  // LCD output enable
  LCD_REG(control)|= BIT0;
  udelay(10000);

}

//--------------------------------------------------------------------------
// lcd_off
//
// This function turns off the DM3730 Display Controller
//
void lcd_off()
{
        // power down the LCD
        udelay(10000);
    
	// digital output disable
	LCD_REG(control)&=~BIT1;
	// LCD output disable
	LCD_REG(control)&=~BIT0;
	udelay(10000);
}




// ------------------------------------------------------------------
// get_pixel_add return the address of a pixel with respect to the frame buffer start address
ulong get_pixel_add (ulong X, ulong Y)
  {
	  
  }

// ------------------------------------------------------------------
// fb_set_pixel sets a pixel to the specified color (between 0 et 15).
void fb_set_pixel(ulong X, ulong Y, uchar color)
{
	

}



// ------------------------------------------------------------------
// fb_print_char prints a character at the specified location.
//
void fb_print_char(uchar cchar, ulong x, ulong y, uchar color)
{
    
}

// ------------------------------------------------------------------
// fb_print_string prints a string at the specified location.(30 characters max)
//
void fb_print_string(uchar *pcbuffer, ulong x, ulong y, uchar color)
{
   
}

// ------------------------------------------------------------------
//
// This function clear the screen
//
void clear_screen()
{
	
}






