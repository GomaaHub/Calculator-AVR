/*
 * CALC_Interface.h
 *
 *  Created on: Apr 17, 2022
 *      Author: Ahmad
 */

#ifndef CALC_INTERFACE_H_
#define CALC_INTERFACE_H_

void CALC_Fill_Left_Operand(u8 num);
void CALC_Fill_Right_Operand(u8 num);
void CALC_Clear_Operands();

u32 CALC_power(u8 x, u8 y);
void CALC_floatToString(f32 n, u8* res, u8 afterpoint);
void reverse(u8* str, u8 len);
u8 IntToStr(u32 x, u8 str[], u8 d);


u16 CALC_Left_Array_To_Num();
u16 CALC_Right_Array_To_Num();

#endif /* CALC_INTERFACE_H_ */
