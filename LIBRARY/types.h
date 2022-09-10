



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f128;
 
	
typedef struct
{
	u8 ID;
	u16 salary;
	u16 bonus;
	u16 deduction;
	
}employee;


typedef struct grades
{
	u16 ID;
	u16 math;
	u16 language;
	u16 physics;
	u16 chemistry;
	
}student;

typedef struct
{
	u16 ID;
	student grade10;
	
}Class;

typedef struct
{
	u8  ID;
	employee employees[10];
	
}department;

typedef union
{
	struct
	{
		u8 B0:1;
		u8 B1:1;
		u8 B2:1;
		u8 B3:1;
		u8 B4:1;
		u8 B5:1;
		u8 B6:1;
		u8 B7:1;
		
	}Bit;
	
	u8 Byte;
}Register;

typedef enum
{
	OK,
	TRUE,
	FALSE,
	SUCCESS,
	FAIL,
	ERROR,
	NULL_PTR,
	DIV_BY_ZERO,
	
}STATUS;


typedef struct node
{
	u8 name[15];
	u16 age;
	char gender;
	u16 ID;
	
	struct node *next;
}node;









