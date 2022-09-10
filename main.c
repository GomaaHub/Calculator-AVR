#include "Library/types.h"
#include "include/DIO_Interface.h"
#include "include/LCD_Interface.h"
#include "include/KPD_Interface.h"
#include "include/KPD_Config.h"
#include <avr/delay.h>



void main(void)
{
	u8 key;
	u8 operation=0;
	s8 left_op_sign=1;
	s8 right_op_sign=1;
	u8 check_operand;
	s32 result;
	s32 left;
	s32 right;

	u8 float_result[20]={0};
	f32 result_div;

	DIO_SetPortDirection(DIO_PORTB,DIO_PORT_OUTPUT);

	DIO_SetPortDirection(KPD_PORT,0x0F);
	DIO_SetPortValue(KPD_PORT,0xF0);

	LCD_Init();
	LCD_CLEAR();

	LCD_DISPLAY_CONTROL(1,0,0);
	LCD_Print_String("Calculator v1.0");
	_delay_ms(1000);
	LCD_CLEAR();
	LCD_GoToXY(0,0);
	LCD_DISPLAY_CONTROL(1,1,1);



	while(1)
	{
		key=KPD_GET_KEY_PRESSED();
		if(key!=NOT_PRESSED)
		{
			switch(key)
			{
			case '0':
			{
				LCD_Print_Char('0');

				if(operation==0)
					CALC_Fill_Left_Operand(0);
				if(operation!=0)
					CALC_Fill_Right_Operand(0);

				break;
			}
			case '1':
			{
				LCD_Print_Char('1');
					if(operation==0)
						CALC_Fill_Left_Operand(1);
					if(operation!=0)
						CALC_Fill_Right_Operand(1);
								break;
			}
			case '2':
			{
				LCD_Print_Char('2');
				if(operation==0)
						CALC_Fill_Left_Operand(2);
				if(operation!=0)
						CALC_Fill_Right_Operand(2);
				break;
			}
			case '3':
			{
				LCD_Print_Char('3');
				if(operation==0)
									CALC_Fill_Left_Operand(3);
								if(operation!=0)
									CALC_Fill_Right_Operand(3);
				break;
			}
			case '4':
			{
				LCD_Print_Char('4');
				if(operation==0)
									CALC_Fill_Left_Operand(4);
								if(operation!=0)
									CALC_Fill_Right_Operand(4);
				break;
			}
			case '5':
			{
				LCD_Print_Char('5');
				if(operation==0)
									CALC_Fill_Left_Operand(5);
								if(operation!=0)
									CALC_Fill_Right_Operand(5);
				break;
			}
			case '6':
			{
				LCD_Print_Char('6');
				if(operation==0)
									CALC_Fill_Left_Operand(6);
								if(operation!=0)
									CALC_Fill_Right_Operand(6);
				break;
			}
			case '7':
			{
				LCD_Print_Char('7');
				if(operation==0)
									CALC_Fill_Left_Operand(7);
								if(operation!=0)
									CALC_Fill_Right_Operand(7);
				break;
			}
			case '8':
			{
				LCD_Print_Char('8');
				if(operation==0)
						CALC_Fill_Left_Operand(8);
				if(operation!=0)
						CALC_Fill_Right_Operand(8);
				break;
			}
			case '9':
			{
				LCD_Print_Char('9');
				if(operation==0)
						CALC_Fill_Left_Operand(9);
				if(operation!=0)
						CALC_Fill_Right_Operand(9);
				break;
			}
			case '+':
			{
				LCD_Print_Char('+');
				operation='+';
				break;
			}
			case '-':
			{
				LCD_Print_Char('-');

				check_operand=CALC_Left_Array_To_Num();

				if((check_operand!='a')&&(operation==0))
				{
					operation='-';
				}
				else if(check_operand=='a')
				{
					left_op_sign=-1;
				}
				else if((operation=='-') || (operation=='+')  || (operation=='*')  || (operation=='/'))
				{
					right_op_sign=-1;
				}
				break;
			}
			case '*':
			{
				LCD_Print_Char('*');
				operation='*';
				break;
			}
			case '/':
			{
				LCD_Print_Char('/');
				operation='/';
				break;
			}
			case 'C':
			{
				LCD_CLEAR();
				LCD_DISPLAY_CONTROL(1,0,0);
				LCD_GoToXY(0,0);
				LCD_Print_String("Clearing LCD...");
				_delay_ms(1000);
				LCD_CLEAR();
				LCD_GoToXY(0,0);
				LCD_DISPLAY_CONTROL(1,1,1);

				CALC_Clear_Operands();
				operation=0;
				left_op_sign=1;
				right_op_sign=1;

				break;
			}
			case '=':
			{

				switch(operation)
				{
					case '+':
					{
						left=CALC_Left_Array_To_Num();
						right=CALC_Right_Array_To_Num();
						left*=left_op_sign;
						right*=right_op_sign;
						result=(left+right);

						LCD_DISPLAY_CONTROL(1,0,0);
						LCD_GoToXY(0,1);
						LCD_Print_String("ANS:");
						if(result<0)
						{
							LCD_Print_Char('-');
							result*=(-1);
						}
						LCD_Print_Integer(result);

						break;
					}
					case '-':
					{
						left=CALC_Left_Array_To_Num();
						right=CALC_Right_Array_To_Num();
						left*=left_op_sign;
						right*=right_op_sign;
						result=(left-right);

						LCD_DISPLAY_CONTROL(1,0,0);
						LCD_GoToXY(0,1);
						LCD_Print_String("ANS:");
						if(result<0)
													{
														LCD_Print_Char('-');
														result*=(-1);
													}
						LCD_Print_Integer(result);

						break;
					}
					case '*':
					{
						left=CALC_Left_Array_To_Num();
						right=CALC_Right_Array_To_Num();
						left*=left_op_sign;
						right*=right_op_sign;

						result=(left*right);
						LCD_DISPLAY_CONTROL(1,0,0);
						LCD_GoToXY(0,1);
						LCD_Print_String("ANS:");
						if(result<0)
							{
								LCD_Print_Char('-');
								result*=(-1);
							}
						LCD_Print_Integer(result);

						break;
					}
					case '/':
					{
						left=CALC_Left_Array_To_Num();
						right=CALC_Right_Array_To_Num();
						left*=left_op_sign;
						right*=right_op_sign;

						if(right==0)
						{
							result='o';
							LCD_DISPLAY_CONTROL(1,0,0);
							LCD_GoToXY(0,1);
							LCD_Print_String("DIV BY ZERO!");
						}
						else
						{
							result_div=((f32)left/right);
							LCD_DISPLAY_CONTROL(1,0,0);
							LCD_GoToXY(0,1);
							LCD_Print_String("ANS:");

							if(result_div<0)
								{
									LCD_Print_Char('-');
										result_div*=(-1);
								}

							if((result_div-(u32)result_div)==0)
							{
								result=(u32)result_div;


								LCD_Print_Integer(result);
							}
							else
							{
								CALC_floatToString(result_div,float_result,3);

								LCD_Print_String(float_result);
							}
						}

						break;
					}
					case 0:
					{
						left=CALC_Left_Array_To_Num();
						left*=left_op_sign;

						result=left;
						LCD_DISPLAY_CONTROL(1,0,0);
						LCD_GoToXY(0,1);
						LCD_Print_String("ANS:");
						LCD_Print_Integer(result);
						break;
					}


				}

				CALC_Clear_Operands();
				operation=0;
				left_op_sign=1;
				right_op_sign=1;


				break;
			}
		}
		}
	}
}


