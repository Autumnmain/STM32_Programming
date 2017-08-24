#include "stm32f10x.h"
#include "led.h"

void delay(int);

int main(void)
{
	unsigned int c=7;
	LED_GPIO_Config();
	while(1)
	{
		if(c >= 0xE0)
		{
			c = (c&0xFF) + (c>>8);
		}
		if(c & 0x01)
			LED_ON(GPIOB, GPIO_Pin_8);
		else
			LED_OFF(GPIOB, GPIO_Pin_8);
		
		if(c & 0x02)
			LED_ON(GPIOB, GPIO_Pin_9);
		else
			LED_OFF(GPIOB, GPIO_Pin_9);	
		
		if(c & 0x04)
			LED_ON(GPIOB, GPIO_Pin_10);
		else
			LED_OFF(GPIOB, GPIO_Pin_10);
		
		if(c & 0x08)
			LED_ON(GPIOB, GPIO_Pin_11);
		else
			LED_OFF(GPIOB, GPIO_Pin_11);
		
		if(c & 0x10)
			LED_ON(GPIOB, GPIO_Pin_12);
		else
			LED_OFF(GPIOB, GPIO_Pin_12);
		
		if(c & 0x20)
			LED_ON(GPIOB, GPIO_Pin_13);
		else
			LED_OFF(GPIOB, GPIO_Pin_13);	
		
		if(c & 0x40)
			LED_ON(GPIOB, GPIO_Pin_15);
		else
			LED_OFF(GPIOB, GPIO_Pin_15);
		
		if(c & 0x80)
			LED_ON(GPIOB, GPIO_Pin_14);
		else
			LED_OFF(GPIOB, GPIO_Pin_14);
		
		c = c<<1;
		delay(5000);
	}
}

void delay(int n)
{
	int i;
	while(n--)
	{
		for(i=0;i<1000;i++);
	}
}
