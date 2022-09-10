#include "LIBRARY/types.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LIBRARY/bit_math.h"




void DIO_SetPinValue(u8 PORT_ID,u8 PIN_ID,u8 value)
{
	if((PORT_ID <= DIO_PORTD) && (PIN_ID <= DIO_PIN7))
	{
		if(value == DIO_HIGH)
		{
			switch(PORT_ID)
			{
				case DIO_PORTA:	SET_BIT(PORTA_REG,PIN_ID); break;
				case DIO_PORTB:	SET_BIT(PORTB_REG,PIN_ID); break;
				case DIO_PORTC:	SET_BIT(PORTC_REG,PIN_ID); break;
				case DIO_PORTD:	SET_BIT(PORTD_REG,PIN_ID); break;
				default: break;
			}
		}
		else if(value == DIO_LOW)
		{
			switch(PORT_ID)
			{
				case DIO_PORTA:	CLR_BIT(PORTA_REG,PIN_ID); break;
				case DIO_PORTB:	CLR_BIT(PORTB_REG,PIN_ID); break;
				case DIO_PORTC:	CLR_BIT(PORTC_REG,PIN_ID); break;
				case DIO_PORTD:	CLR_BIT(PORTD_REG,PIN_ID); break;

			}
		}
		else
		{
			// Report Error!
		}
	}
}



void DIO_SetPinDirection(u8 PORT_ID,u8 PIN_ID,u8 dir)
{
	if((PORT_ID <= DIO_PORTD) && (PIN_ID <= DIO_PIN7))
		{
			if(dir == DIO_OUTPUT)
			{
				switch(PORT_ID)
				{
					case DIO_PORTA:	SET_BIT(DDRA_REG,PIN_ID); break;
					case DIO_PORTB:	SET_BIT(DDRB_REG,PIN_ID); break;
					case DIO_PORTC:	SET_BIT(DDRC_REG,PIN_ID); break;
					case DIO_PORTD:	SET_BIT(DDRD_REG,PIN_ID); break;
					default: break;
				}
			}
			else if(dir == DIO_INPUT)
			{
				switch(PORT_ID)
				{
					case DIO_PORTA:	CLR_BIT(DDRA_REG,PIN_ID); break;
					case DIO_PORTB:	CLR_BIT(DDRB_REG,PIN_ID); break;
					case DIO_PORTC:	CLR_BIT(DDRC_REG,PIN_ID); break;
					case DIO_PORTD:	CLR_BIT(DDRD_REG,PIN_ID); break;
				}
			}
			else
			{
				// Report Error!
			}
		}
}



void DIO_SetPortValue(u8 PORT_ID,u8 value)
{
	if(PORT_ID <= DIO_PORTD)
	{
		switch(PORT_ID)
		{
			case DIO_PORTA:	PORTA_REG = value; break;
			case DIO_PORTB:	PORTB_REG = value; break;
			case DIO_PORTC:	PORTC_REG = value; break;
			case DIO_PORTD:	PORTD_REG = value; break;
		}
	}
	else
	{
		// Report Error!
	}
}



void DIO_SetPortDirection(u8 PORT_ID,u8 dir)
{
	if(PORT_ID <= DIO_PORTD)
		{
			switch(PORT_ID)
			{
				case DIO_PORTA:	DDRA_REG = dir; break;
				case DIO_PORTB:	DDRB_REG = dir; break;
				case DIO_PORTC:	DDRC_REG = dir; break;
				case DIO_PORTD:	DDRD_REG = dir; break;

			}
		}
		else
		{
			// Report Error!
		}
}



u8 DIO_GetPinValue(u8 PORT_ID,u8 PIN_ID)
{
	u8 return_value = 255;

	if((PORT_ID <= DIO_PORTD) && (PIN_ID <= DIO_PIN7))
	{
		switch(PORT_ID)
		{
			case DIO_PORTA:	return_value = GET_BIT(PINA_REG,PIN_ID); break;
			case DIO_PORTB:	return_value = GET_BIT(PINB_REG,PIN_ID); break;
			case DIO_PORTC:	return_value = GET_BIT(PINC_REG,PIN_ID); break;
			case DIO_PORTD:	return_value = GET_BIT(PIND_REG,PIN_ID); break;
		}
	}
	else
	{
			//Report Error!
	}

	return return_value;

	}



