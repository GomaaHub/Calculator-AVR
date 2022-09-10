
#define SET_BIT(reg,n) (reg |= (1<<n))
#define CLR_BIT(reg,n) (reg&=~(1<<n))
#define TOGG_BIT(reg,n) (reg^= (1<<n))
#define GET_BIT(reg,n) (reg>>n &1)
