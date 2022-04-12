#include <reg52.h>
#include <rc522.h>
#include <string.h>
unsigned char id_type[2];
unsigned char UID[4],i;

unsigned char UI0[4]={0x23,0x45,0x67,0x31};	   
unsigned char UI1[4]={0x7B,0xBF,0x55,0x1B};

sbit PWM = P3^1;//舵机
unsigned char count = 0;
unsigned char times1 ;

void init0()
{
	TMOD = 0x01; 	// 方式一
	TH0 = 0XFF;
	TL0 = 0XA4;
	TR0 = 1;       // 开启定时器0
	EA = 1;		   // 开启总中断
	ET0 = 1;       // 定时器0允许中断
}


void delay(unsigned char x)
{
	int a,b;
	for(a=0;a<x;a++) 
		for(b=0;b<1828;b++);
	
}
	
//串口初始化
void Init_uart()
{
	TMOD=0x20;
	TH1=TL1=0XFD;
	SCON=0X50;
	TR1=1;
}

//发送数据
void send_byte(dat)
{
	SBUF=dat;
	while(!TI);
	TI=0;
			
}

//初始化RC522
void Init_rc522()
{
	PcdReset();
	M500PcdConfigISOType('A');
	PcdAntennaOn();
}

//读卡
void READ_ID()
{
	while(1)
{
	if(PcdRequest(0X52,id_type)==MI_OK)
	{
		if(PcdAnticoll(UID)==MI_OK)
		{
			//if(strcmp(UID,UI0)==0||strcmp(UID,UI1)==0)
			//{
			for(i=0;i<4;i++)
			{	
				if(UID[i] != UI0[i] && UID[i] != UI1[i])
				{
					break;
				}
			}
			if(i == 4)
			{
				//send_byte(UID[0]);
				//send_byte(UID[1]);
				times1 = 5;
				count = 1;
				delay(15);
				times1 = 25;
				count = 0;
				delay(15);
				//send_byte(UID[i]);		
			//}
			//delay(100);
		 } 
	 }				
		}
	}
}





void main()
{
	init0();//舵机
	Init_uart();
	Init_rc522();
	READ_ID();
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


