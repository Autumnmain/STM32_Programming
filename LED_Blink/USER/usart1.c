#include "usart1.h"

void USART1_Config(void)
{
	/* Initialization structure for GPIO of usart PA9 = TX, PA10 = RX */
	GPIO_InitTypeDef GPIO_InitStructure;
	/* Initialization structure for USART */
	USART_InitTypeDef USART_InitStructure;
	
	/* Enable peripheral (usart) clock and GPIOA clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	/* Initialize GPIOA */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Initialize usart1 */
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE);
}


/* Orientation fputc function */
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (unsigned char) ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
	return ch;
}

/**
	* @brief	Change the data type from int to char
	* @author	Xiang Li
	*	@param	-value, the value, which will be transformed to char
	*	@param	-string, the char pointer
	* @param	-radix, = 10, means decimal
	*
	*	@retval	
	*/
static char *itoa (int value, char *string, int radix)
{
	int d;
	int flag = 0;
	char *ptr = string;
	
	/* This implementation only works for decimal numbers */
	if(radix != 10)
	{
		*ptr = 0;
		return string;
	}
	
	if(!value)
	{
		*(ptr++) = 0x30;
		*ptr = 0;
		return string;
	}
	
	/* Implementation for negative values */
	if (value < 0)
	{
		*(ptr++) = '-';
		value *= -1;
	}
	
	d = value/10000;
	if (d || flag)
	{
		*(ptr++) = d + 0x30;
		flag = 1;
		value -= d*10000;
	}
	d = value/1000;
	if (d || flag)
	{
		*(ptr++) = d + 0x30;
		flag = 1;
		value -= d*1000;
	}
	d = value/100;
	if (d || flag)
	{
		*(ptr++) = d + 0x30;
		flag = 1;
		value -= d*100;
	}
	d = value/10;
	if (d || flag)
	{
		*(ptr++) = d + 0x30;
		flag = 1;
		value -= d*10;
	}
	d = value;
	if (d || flag)
	{
		*(ptr++) = d + 0x30;
		flag = 1;
	}
	
	*ptr = 0;
	return string;
}

