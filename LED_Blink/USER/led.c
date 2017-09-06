#include "led.h"

void LED_GPIO_Config(void)
{
	/* Define a Initialization structure for GPIOB */
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Enable clock for peripheral GPIOB */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);
	
	/* Set GPIOB as output pull down pull up 50MHz */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | \
	 GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, GPIO_InitStructure.GPIO_Pin);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_InitStructure.GPIO_Pin);
}

void Key_GPIO_Config(void)
{
	/* Define a Initialization structure for GPIOB */
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Enable clock for peripheral GPIOB */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	/* Set GPIOB pin0 ~ pin7 as input mode */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |\
	 GPIO_Pin_4 |  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

u8 Key_Scan(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)
{
	/* Read input data */
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0)
	{
		/* Delay to eliminate valibration */
		delay(10);
		/* Wait for key release */
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0);
		return 1;
	}
	else
		return 0;
}
