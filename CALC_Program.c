#include "Library/types.h"
#include "CALC_Interface.h"




u8 left_operand[4]={'a','a','a','a'};
u8 right_operand[4]={'a','a','a','a'};

void CALC_Fill_Left_Operand(u8 num)
{
		if(left_operand[0]=='a')
			{
				left_operand[0]=num;
			}
		else if(left_operand[1]=='a')
			{
				left_operand[1]=num;
			}
		else if(left_operand[2]=='a')
			{
				left_operand[2]=num;
			}
		else if(left_operand[3]=='a')
			{
				left_operand[3]=num;
			}
}

void CALC_Fill_Right_Operand(u8 num)
{
		if(right_operand[0]=='a')
			{
				right_operand[0]=num;
			}
		else if(right_operand[1]=='a')
			{
				right_operand[1]=num;
			}
		else if(right_operand[2]=='a')
			{
				right_operand[2]=num;
			}
		else if(right_operand[3]=='a')
			{
				right_operand[3]=num;
			}
}

u16 CALC_Left_Array_To_Num()
{
			u16 left_num;

			if(left_operand[0]=='a')
				{
					left_num=left_operand[0];
				}
			else if(left_operand[1]=='a')
				{
					left_num=left_operand[0];
				}
			else if(left_operand[2]=='a')
				{
					left_num=(left_operand[0]*10)+(left_operand[1]);
				}
			else if(left_operand[3]=='a')
				{
					left_num=(left_operand[0]*100)+(left_operand[1]*10)+(left_operand[2]);
				}
			else
				{
					left_num=(left_operand[0]*1000)+(left_operand[1]*100)+(left_operand[2]*10)+(left_operand[3]);
				}

			return left_num;
}

u16 CALC_Right_Array_To_Num()
{
			u16 right_num;

			if(right_operand[1]=='a')
				{
					right_num=right_operand[0];
				}
			else if(right_operand[2]=='a')
				{
					right_num=(right_operand[0]*10)+(right_operand[1]);
				}
			else if(right_operand[3]=='a')
				{
					right_num=(right_operand[0]*100)+(right_operand[1]*10)+(right_operand[2]);
				}
			else
				{
					right_num=(right_operand[0]*1000)+(right_operand[1]*100)+(right_operand[2]*10)+(right_operand[3]);
				}

			return right_num;
}

void CALC_Clear_Operands()
{
	for(u8 i=0;i<4;i++)
	{
		left_operand[i]='a';
		right_operand[i]='a';
	}
}




void reverse(u8* str, u8 len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
u8 IntToStr(u32 x, u8 str[], u8 d)
{
	u8 i = 0;

	if(x==0)
		str[i++]='0';

	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

// Converts a floating-point/double number to a string.
void CALC_floatToString(f32 n, u8* res, u8 afterpoint)
{
	// Extract integer part
	u32 ipart = n;

	// Extract floating part
	f32 fpart = n - (f32)ipart;

	// convert integer part to string
	u8 i = IntToStr(ipart, res, 0);

	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot

		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007


		fpart = fpart * CALC_power(10, afterpoint) ;

		IntToStr((u32)fpart, res + i + 1, afterpoint);
	}
}

u32 CALC_power(u8 x, u8 y)
{
	u32 power = 1, i;

	for (i = 1; i <= y; ++i) {
		power = power * x;
	}

	return power;
}
