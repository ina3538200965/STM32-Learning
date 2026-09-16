#include "stm32f10x.h"
#include "delay.h"         

int main(void)
{
	//1.开启GPIOC时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	//2.初始化PC13，推挽输出
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//LED
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//LED状态
	//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET); 
	
	while(1)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET); 
		
		Delay(100);
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET); 
		
		Delay(100);
	}
