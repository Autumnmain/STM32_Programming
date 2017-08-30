#include "exti.h"

void EXTI_PB56_Config(void)
{
	/* GPIO initialization structure */
	GPIO_InitTypeDef GPIO_InitStructure;
	/* EXTI intialization structure */
	EXTI_InitTypeDef EXTI_InitStructure;
	
	/* Enable peripheral clock for GPIO and its alternative fuction */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	
	/* Configure the NVIC(PB5) */
	NVIC_Configuration();
	
	/* Initialize the GPIO structure */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* Initialize the EXTI structure */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);
	EXTI_InitStructure.EXTI_Line = EXTI_Line5 | EXTI_Line6;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

static void NVIC_Configuration(void)
{
	/* Definition initialization structure */
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Select NVIC priority group */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/* Initialize NVIC structure */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
