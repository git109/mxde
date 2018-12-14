/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: lcd.c
 *
 * Author: $author$
 *   Date: 10/26/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "platform_boot.h"
#include "atmega128.h"

#define LCD_CMD_REG				0x00

#	define LCD_CLEAR_DISPLAY_CMD			(1 << 0)

#	define LCD_HOME_CURSOR_CMD				(1 << 1)

#	define LCD_SET_ENTRY_MODE_CMD	 		(1 << 2)
#		define	LCD_DISPLAY_SHIFT_ON 	(1<<0)
#		define	LCD_DISPLAY_SHIFT_OFF 	(1<<0)
#		define  LCD_MODE_INC		 	(1<<1)
#		define  LCD_MODE_DEC		 	(0<<1)

#	define LCD_DISPLAY_ON_OFF_CMD	 		(1 << 3)
#		define	LCD_BLINK_OFF			(0<<0)
#		define	LCD_BLINK_ON			(1<<0)
#		define	LCD_CURSOR_OFF			(0<<1)
#		define	LCD_CURSOR_ON			(1<<1)
#		define	LCD_DISPLAY_OFF			(0<<2)
#		define	LCD_DISPLAY_ON			(1<<2)

#	define LCD_CURSOR_OR_DISPLAY_SHIFT_CMD	(1 << 4)
#		define	LCD_MOVE_LEFT			(0<<2)
#		define 	LCD_MOVE_RIGHT			(1<<2)
#		define 	LCD_MOVE_CURSOR			(0<<3)
#		define	LCD_SHIFT_DISPLAY		(1<<3)

#	define LCD_FUNCTION_SET_CMD				(1 << 5)
#		define	LCD_FONT_5x7			(0<<2)
#		define	LCD_FONT_5x10			(1<<2)
#		define	LCD_1_LINE				(0<<3)
#		define	LCD_2_LINE				(1<<3)
#		define	LCD_4_BIT_INTERFACE		(0<<4)
#		define	LCD_8_BIT_INTERFACE		(1<<4)


#	define LCD_SET_CGRAM_ADDRESS_CMD		(1 << 6)
#		define	LCD_CGRAM_ADDRESS_MASK	0x3F

#	define LCD_SET_DDRAM_ADDRESS_CMD		(1 << 7)
#		define	LCD_DDRAM_ADDRESS_MASK	0x7F



#define LCD_STATUS_REG			0x01
#	define LCD_STATUS_BUSY	0x80

#define LCD_DATA_OUT_REG		0x02
#define LCD_DATA_IN_REG			0x03

#define lcdReg		((unsigned char *)0x4000)

void waitNotBusy()
{
	unsigned char status;
	
	while (((status = lcdReg[LCD_STATUS_REG]) & LCD_STATUS_BUSY) == LCD_STATUS_BUSY)
	{}
}

static const unsigned char LCDLineStart[] = {0x00, 0x40, 0x14, 0x54};

void setCursorLCD(int line, int position)
{
	unsigned char temp;
	waitNotBusy();
	temp = LCD_SET_DDRAM_ADDRESS_CMD | ((LCDLineStart[line] + position) & 0x7F);
	lcdReg[LCD_CMD_REG] =  temp ;
	waitNotBusy();
}

void homeCursorLCD( )
{
	waitNotBusy();
	lcdReg[LCD_CMD_REG] =  LCD_SET_DDRAM_ADDRESS_CMD ;
	waitNotBusy();
//	waitNotBusy();	
}

void clearDisplayLCD(void)
{
	waitNotBusy();
	lcdReg[LCD_CMD_REG] =  lcdReg[LCD_CMD_REG] = LCD_CLEAR_DISPLAY_CMD;		
	homeCursorLCD();
	waitNotBusy();
}

void putCharLCD(char theChar)
{
	// wait here rather than after is more efficient.
	waitNotBusy(); 
	lcdReg[LCD_DATA_OUT_REG] = theChar;
	waitNotBusy();
}

void putStringLCD(char* theString)
{
	int i;
	
	for (i=0;(theString[i] != '\0');i++)
	{
		putCharLCD(theString[i]);
	}
}

/**
 **********************************************************************
 * Function: lcd_initialize
 *
 *   Author: $author$
 *     Date: 10/26/2005
 **********************************************************************
 */
int lcd_initialize() 
{
    int result = 0;
	unsigned char temp;
	
	waitNotBusy();
	waitNotBusy();
	waitNotBusy();
	waitNotBusy();

	temp = (LCD_FUNCTION_SET_CMD | LCD_8_BIT_INTERFACE | LCD_2_LINE ) ;
	lcdReg[LCD_CMD_REG] = temp;

	// Set the font width and num lines
	waitNotBusy();
	waitNotBusy();

	temp = LCD_DISPLAY_ON_OFF_CMD;
	lcdReg[LCD_CMD_REG] = temp;
		
	// Clear the screen of any unwanted garbage.
	waitNotBusy();
	waitNotBusy();

	temp = LCD_CLEAR_DISPLAY_CMD;
	lcdReg[LCD_CMD_REG] = temp;

	// Set the font width and num lines
	waitNotBusy();
	waitNotBusy();
	
	temp = LCD_DISPLAY_ON_OFF_CMD | LCD_DISPLAY_ON ;
	lcdReg[LCD_CMD_REG] = temp;
	
	// Set the Cursor to the 
	waitNotBusy();
	waitNotBusy();
	temp = LCD_SET_ENTRY_MODE_CMD | LCD_MODE_INC;
	lcdReg[LCD_CMD_REG] = temp;

    putStringLCD("Hello");

    return result;
}

/**
 **********************************************************************
 * Function: lcd_finalize
 *
 *   Author: $author$
 *     Date: 10/26/2005
 **********************************************************************
 */
int lcd_finalize() 
{
    int result = 0;
    return result;
}

/**
 **********************************************************************
 * Function: platform_initialize
 *
 *   Author: $author$
 *     Date: 10/26/2005
 **********************************************************************
 */
int platform_initialize(void) 
{
    int result = 0;

#if defined(ATMEGA128) 
    MCUCR = (ATMEGA128_MCUCR_BM_SRE | ATMEGA128_MCUCR_BM_SRW10);
    XMCRA = ((ATMEGA128_XMCRA_SRL_BV_E000 << ATMEGA128_XMCRA_BS_SRL) & ATMEGA128_XMCRA_BM_SRL);
    XMCRB = (ATMEGA128_XMCRB_BM_XMBK);

    TWBR = 72;
    TWCR = ATMEGA128_TWCR_BM_TWEN;
#endif /* defined(ATMEGA128) */

    return result;
}

/**
 **********************************************************************
 * Function: platform_void_main
 *
 *   Author: $author$
 *     Date: 10/26/2005
 **********************************************************************
 */
void platform_void_main(void) 
{
    /* Initialize platform
     */
    platform_initialize();

    lcd_initialize();

    /* Forever...
     */
    while(1)
    {
    }
}

