/*
 * LCD_CONFIG.h
 *
 *  Created on: Apr 9, 2022
 *      Author: Ahmad
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define BIT_8					0
#define BIT_4					1


#define LCD_MODE				BIT_4
#define LCD_DATA_PORT			DIO_PORTB
#define LCD_CONTROL_PORT 		DIO_PORTB
#define LCD_RS_PIN				DIO_PIN2
#define LCD_RW_PIN				DIO_PIN1
#define LCD_E_PIN				DIO_PIN3

#endif /* LCD_CONFIG_H_ */
