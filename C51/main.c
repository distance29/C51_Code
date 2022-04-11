#include<reg51.h>

void delay(unsigned int x);

void main()
{
	unsigned char i,j;
	while(1)
	{
		i=0xff;
		P1=i;
		delay(100);
		for(j=0;j<8;j++)
		{
			i=i<<1;
			P1=i;
			delay(100);
		}
	}
}
void delay(unsigned int x)
{
	unsigned int i,j;
	for(i=x;i>0;i--)
		for(j=115;j>0;j--);
}


