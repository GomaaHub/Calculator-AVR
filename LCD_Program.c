#include "LIBRARY/types.h"
#include "LIBRARY/bit_math.h"
#include <avr/delay.h>
#include <math.h>
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"

static u8 position_tracker = 0;		// Start X Position
static u8 line_tracker = 0;			// Start Y Position

void LCD_CLEAR(void)
{
	LCD_SendCMD(0x01);
	_delay_ms(1);

	position_tracker=0;
	line_tracker=0;
}

void LCD_HOME(void)
{
	LCD_SendCMD(0x02);
}

void LCD_ENTRY_MODE_SET(u8 INC_OR_DEC, u8 SHIFT)
{
	INC_OR_DEC = (INC_OR_DEC << 1) & 0x02;
	SHIFT = SHIFT & 0x01;

	LCD_SendCMD(0x04 | INC_OR_DEC | SHIFT);
}

void LCD_DISPLAY_CONTROL(u8 DISPLAY_ON_OFF, u8 CURSOR_ON_OFF, u8 BLINK_ON_OFF)
{
	DISPLAY_ON_OFF = (DISPLAY_ON_OFF << 2) & 0x04;
	CURSOR_ON_OFF = (CURSOR_ON_OFF << 1) & 0x02;
	BLINK_ON_OFF = BLINK_ON_OFF & 0x01;

	LCD_SendCMD(0x08 | DISPLAY_ON_OFF | CURSOR_ON_OFF | BLINK_ON_OFF);
}

void LCD_CURSOR_DISPLAY_SHIFT (u8 CURSOR_SHIFT, u8 RIGHT_LEFT)
{
	CURSOR_SHIFT = (CURSOR_SHIFT << 3) & 0x08;
	RIGHT_LEFT = (RIGHT_LEFT << 2) & 0x04;

	LCD_SendCMD(0x10 | CURSOR_SHIFT | RIGHT_LEFT);
}

void LCD_FUNCTION_SET(u8 DATA_LENGTH, u8 DISPLAY_LINES, u8 FONT_TYPE)
{
	DATA_LENGTH = (DATA_LENGTH << 4) & 0x10;
	DISPLAY_LINES = (DISPLAY_LINES << 3) & 0x08;
	FONT_TYPE = (FONT_TYPE << 4) & 0x04;

	LCD_SendCMD(0x20 | DATA_LENGTH | DISPLAY_LINES | FONT_TYPE);
}

void LCD_Clock(void)
{
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(1);
	// Clear E pin
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(1);
}



void LCD_Init(void)
{
#if 	LCD_MODE == 0

		_delay_ms(30);

		DIO_SetPortValue(LCD_DATA_PORT,0x38);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(1);

		DIO_SetPortValue(LCD_DATA_PORT,0x0E);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(1);

		DIO_SetPortValue(LCD_DATA_PORT,0x01);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(1);

		DIO_SetPortValue(LCD_DATA_PORT,0x06);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(2);

#else if LCD_MODE == 1

		_delay_ms(30);

		DIO_SetPortValue(LCD_DATA_PORT,0x20);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		DIO_SetPortValue(LCD_DATA_PORT,0x20);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		DIO_SetPortValue(LCD_DATA_PORT,0x80);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(1);

		DIO_SetPortValue(LCD_DATA_PORT,0x00);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		DIO_SetPortValue(LCD_DATA_PORT,0xE0);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(1);

		DIO_SetPortValue(LCD_DATA_PORT,0x00);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		DIO_SetPortValue(LCD_DATA_PORT,0x10);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(1);

		DIO_SetPortValue(LCD_DATA_PORT,0x00);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		DIO_SetPortValue(LCD_DATA_PORT,0x60);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

		DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		LCD_Clock();

		_delay_ms(1);

		#endif
}


void LCD_SendCMD(u8 cmd)
{
#if LCD_MODE == 0

	DIO_SetPortValue(LCD_DATA_PORT,cmd);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);


	LCD_Clock();

#else if LCD_MODE == 1

	u8 cmd1;

	cmd1 = cmd & (0xF0);

	DIO_SetPortValue(LCD_DATA_PORT,cmd1);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	LCD_Clock();

	cmd1 = ((cmd<<4) & (0xF0));

	DIO_SetPortValue(LCD_DATA_PORT,cmd1);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	LCD_Clock();

	#endif
}


void LCD_Print_Char(u8 u8char)
{
#if LCD_MODE == 0

	if(position_tracker>15)
		{
			if(line_tracker > 0)
			{
				LCD_GoToXY(0,0);
				line_tracker=0;
			}
			else
			{
				line_tracker++;
				LCD_GoToXY(0,1);
			}
			position_tracker = 0;
		}

	DIO_SetPortValue(LCD_DATA_PORT,u8char);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	LCD_Clock();

	position_tracker++;

#else if LCD_MODE == 1

	u8 u8char1;

	if(position_tracker>15)
			{
				if(line_tracker > 0)
				{
					LCD_GoToXY(0,0);
					line_tracker=0;
				}
				else
				{
					line_tracker++;
					LCD_GoToXY(0,1);
				}
				position_tracker = 0;
			}

	u8char1 = u8char & (0xF0);

	DIO_SetPortValue(LCD_DATA_PORT,u8char1);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	LCD_Clock();

	u8char1=((u8char<<4)&(0xF0));

	DIO_SetPortValue(LCD_DATA_PORT,u8char1);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	LCD_Clock();

	position_tracker++;

	#endif
}

void LCD_Print_String(u8* pu8str)
{

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);

	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);


	for(u8 i=0;(*pu8str)!='\0';i++)
	{
		LCD_Print_Char(*pu8str);
		pu8str++;
	}

}
void LCD_GoToXY(u8 x, u8 y)
{

	position_tracker=x;
	line_tracker=y;

	if(y==1)
	{
		x+=0x40;
	}

	LCD_SendCMD( 0x80 | x);
}

void LCD_GoTo_CGRAM(u8 address)
{
	LCD_SendCMD( 0x40 | address);
}




void LCD_CreateNewChar(u8 *pattern,s8 CGlocation)
{
	u8 i;
	CGlocation=(CGlocation & 0x07) << 3;

	LCD_GoTo_CGRAM(CGlocation);

	for(i=0;i<8;i++)
	{
		LCD_Print_Char(pattern[i]);
	}

}


void LCD_Print_Integer (u32 num)
{
	u8 i=0,c=0;
	u8 integer[8]={'q','q','q','q','q','q','q','q'};

	if(num==0)
	{
		LCD_Print_Char('0');
	}
	else
	{
	while(num!=0)
	{
		integer[i]=(num%10);
		num=num/10;
		i++;
	}


	for(i=7;i>=0;i--)
	{
		if(integer[i]=='q')
		{
			c++;
			continue;
		}

		if(c==0||c==1)
		{
			if(i==5||i==2)
				LCD_Print_Char(',');
		}

		if(c==2||c==3||c==4)
		{
			if(i==2)
				LCD_Print_Char(',');
		}
		LCD_Print_Char(integer[i]+'0');

		if(i==0)
			break;
	}
	}
}

