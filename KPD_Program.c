#include "LIBRARY/types.h"
#include "DIO_Interface.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"
#include <avr/delay.h>


static u8 kpd_arr[4][4]={{'1','2','3','*'},
						 {'4','5','6','/'},
						 {'7','8','9','+'},
						 {'=','0','C','-'}};

u8 KPD_GET_KEY_PRESSED(void)
{
	u8 pressed_key = NOT_PRESSED;
	u8 col,row;

	for (col=0;col<4;col++)
	{
		DIO_SetPinValue(KPD_PORT,col,DIO_LOW);
		for(row=4;row<8;row++)
		{
			if(DIO_GetPinValue(KPD_PORT,row)==DIO_LOW)
			{
				while(DIO_GetPinValue(KPD_PORT,row)==DIO_LOW);
				_delay_ms(50);

				pressed_key=kpd_arr[row-4][col];
			}
		}
		DIO_SetPinValue(KPD_PORT,col,DIO_HIGH);
	}

	return pressed_key;
}
