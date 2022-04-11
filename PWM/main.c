#include<reg52.h>
#include<intrins.h>
sbit PWM = P3^7;
unsigned char count = 0;
unsigned char times1 ;


void delay1s(void)
{
	unsigned char a,b,c;
	for(c=167;c>0;c--)
		for(b=171;b>0;b--)
			for(a=16;a>0;a--);
	_nop_();
}

void times0_Init()
{
	TMOD &= 0x00;
	TMOD |= 0x01;
	
	TH0 = 0xff;
	TL0 = 0xa4;
	
	ET0 = 1;
	TR0 = 1;
	EA=1;
}

void Time0_Init() interrupt 1
{
	TR0 = 0;
	TH0 = 0xff;
	TL0 = 0xa4;
	
	if(count <= times1)
	{
		PWM = 1;
	}
	else
	{
		PWM =0;
	}
	count++;
	if(count >= 200)
	{
		count = 0;
	}
	TR0 = 1;		
}

void main()
{
	Times0_Init();
	while(1)
	{
		times1 = 5;
		count = 1;
		delay1s();
		times1 = 15;
		count = 0;
		delay1s();
	}
}