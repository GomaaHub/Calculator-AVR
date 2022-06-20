/*
 * LCD_Interface.h
 *
 *  Created on: Apr 9, 2022
 *      Author: Ahmad
 */



#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*******************************************PUBLIC MACROS******************************************/

		//Replace all characters with ASCI

#define LCD_ENTRYMODE			0x04
#define LCD_DISPOFF				0x08
#define LCD_DISPON_CURSON		0x0E
#define LCD_FUNCRESET			0x30
#define LCD_FUNCSET_8BIT		0x38
#define LCD_SETCURSOR			0x80
#define LCD_DISPON_CURSBLINK	0x0F
#define LCD_DISPON_CURSOFF		0x0C

/******************************************CONTROL LCD MACROS*****************************************/

#define LCD_INCREMENT			1
#define LCD_DECREMENT			0
#define LCD_SHIFT				1
#define LCD_NO_SHIFT			0
#define LCD_DISPLAY_ON			1
#define LCD_DISPLAY_OFF			0
#define LCD_CURSOR_ON			1
#define LCD_CURSOR_OFF			0
#define LCD_CURSOR_BLINK_ON		1
#define LCD_CURSOR_BLINK_OFF	0
#define LCD_MOVE_CURSOR			1
#define LCD_MOVE_SHIFT			0
#define LCD_MOVE_RIGHT			1
#define LCD_MOVE_LEFT			0
#define LCD_LENGTH_8BIT			1
#define LCD_LENGTH_4BIT			0
#define LCD_2_LINE				1
#define LCD_1_LINE				0
#define LCD_FONT_5_10			1
#define LCD_FONT_5_8			0

/*******************************************PUBLIC FUNCTIONS******************************************/

void LCD_Init(void);
void LCD_SendCMD(u8 u8cmd);
void LCD_Print_Char(u8 u8char);
void LCD_Print_String(u8* pu8str);
void LCD_GoToXY(u8 x, u8 y);
void LCD_CreateNewChar(u8 *pattern,s8 CGlocation);
void LCD_GoToCGRAM(u8 pos);
void LCD_Clock(void);
void LCD_CLEAR(void);
void LCD_HOME(void);
void LCD_ENTRY_MODE_SET(u8 INC_OR_DEC, u8 SHIFT);
void LCD_DISPLAY_CONTROL(u8 DISPLAY_ON_OFF, u8 CURSOR_ON_OFF, u8 BLINK_ON_OFF);
void LCD_CURSOR_DISPLAY_SHIFT (u8 CURSOR_SHIFT, u8 RIGHT_LEFT);
void LCD_FUNCTION_SET(u8 DATA_LENGTH, u8 DISPLAY_LINES, u8 FONT_TYPE);
void LCD_Print_Integer (u32 num);


#endif /* LCD_INTERFACE_H_ */
