/*
 * DIO_INTERFACE.H
 *
 *  Created on: Apr 8, 2022
 *      Author: Ahmad
 */
//#include "LIBRARY/types.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/*******PUBLIC FUNCTIONS*******/

/*Description: API used to set pin val to digital high/low.				*/
/* Inputs:		u8 PORT_ID -> Index of port number (PORT A to PORT D)	*/
/* Inputs:		u8 PIN_ID -> Index of pin number (PIN 0 to PIN 7)		*/
/* Inputs:		u8 VALUE -> 0 or 1										*/
/* Output:		void
 *
 *
 * */

void DIO_SetPinValue(u8 PORT_ID,u8 PIN_ID,u8 value);
void DIO_SetPinDirection(u8 PORT_ID,u8 PIN_ID,u8 dir);
void DIO_SetPortValue(u8 PORT_ID,u8 value);
void DIO_SetPortDirection(u8 PORT_ID,u8 dir);

u8 DIO_GetPinValue(u8 PORT_ID,u8 PIN_ID);

/*******PUBLIC MACROS**********/

//PORT Definition:

#define DIO_PORTA 	0
#define DIO_PORTB 	1
#define DIO_PORTC 	2
#define DIO_PORTD 	3

//PINS Definition:

#define DIO_PIN0 	0
#define DIO_PIN1 	1
#define DIO_PIN2 	2
#define DIO_PIN3 	3
#define DIO_PIN4 	4
#define DIO_PIN5 	5
#define DIO_PIN6 	6
#define DIO_PIN7 	7

//PIN Direction:

#define DIO_INPUT 		0
#define DIO_OUTPUT 		1
#define DIO_PORT_INPUT 	0x00
#define DIO_PORT_OUTPUT 0xFF

//Digital Value Definition:

#define DIO_HIGH 		1
#define DIO_LOW  		0
#define DIO_PORT_LOW 	0x00
#define DIO_PORT_HIGH	0xFF



#endif /* DIO_INTERFACE_H_ */
