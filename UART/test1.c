#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar a;

void init()
{
	TMOD = 0x20;
	TH1 = 0xfd;
	TL1 = 0xfd;
	PCON = 0x00;
	TR1 = 1;
	REN = 1;
	SM0 = 0;
	SM1 = 1;
	EA = 1;
	ES = 1;
}

void uart() interrupt 4
{
	a = SBUF;
	RI = 0;
	SBUF = a;
	while(!TI);
	TI = 0;
}

void main()
{
	init();
	while(1);
}