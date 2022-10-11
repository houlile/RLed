#include "stm32f10x.h"

//----------------APB2使能时钟寄存器 ---------------------
#define RCC_APB2ENR		*((unsigned volatile int*)0x40021018)
//----------------GPIOA配置寄存器 -----------------------
#define GPIOA_CRL		*((unsigned volatile int*)0x40010800)
#define	GPIOA_ODR		*((unsigned volatile int*)0x4001080C)
//----------------GPIOB配置寄存器 -----------------------
#define GPIOB_CRH		*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ODR		*((unsigned volatile int*)0x40010C0C)
	
//----------------GPIOC配置寄存器 -----------------------

#define GPIOC_CRH		*((unsigned volatile int*)0x40011004)
#define	GPIOC_ODR		*((unsigned volatile int*)0x4001100C)


//延时函数
 void Delay()
 {
   u32 i=0;
   for(;i<8000000;i++);
 }
 
 int main(void)
 {	
	RCC_APB2ENR|=1<<2|1<<3|1<<4;			//APB2-GPIOA、GPIOB、GPIOC外设时钟使能	
	

	 
		
	 
		GPIOA_CRL&=0xFF0FFFFF;		//设置位 清零	
		GPIOA_CRL|=0x00200000;		//PA5推挽输出，把第23、22、21、20变为0010
		GPIOA_ODR&=(0<<4);			//设置初始灯为灭
	
		GPIOB_CRH&=0xFFFFFF0F;		//设置位 清零	
		GPIOB_CRH|=0x00000020;		//PB9推挽输出，把第7、6、5、4变为0010
	 	GPIOB_ODR&=(0<<5);			//设置初始灯为灭
	 
	 
		GPIOC_CRH&=0xF0FFFFFF;		//设置位 清零	
		GPIOC_CRH|=0x02000000;		//PC14推挽输出，把第27、26、25、24变为0010
	  GPIOC_ODR&=(0<<14);			//设置初始灯为灭

	while(1)
		{
		//A灯
		GPIOA_ODR|=1<<5;		//PB5高电平
	 	Delay();
		GPIOA_ODR&=(0<<5);		//PB5低电平,因为是置0，所以用按位与
	Delay();
		
		//B灯
		GPIOB_ODR|=1<<9;		//PB9高电平
	 	Delay();
		GPIOB_ODR&=(0<<9);		//PB5低电平,因为是置0，所以用按位与
	  Delay();

		
		
		//C灯
		GPIOC_ODR|=1<<14;		//PB14高电平
	 	Delay();
		GPIOC_ODR&=(0<<14);		//PB5低电平,因为是置0，所以用按位与
	  Delay();

		
		}
}
