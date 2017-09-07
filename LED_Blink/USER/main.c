#include "main.h"

int delay_time = 500;
extern uint8_t SendBuff[SENDBUFF_SIZE];
extern __IO uint16_t ADC_ConvertedValue;

int main(void)
{
	u32 c=11;
	u32 i;
	float ADC_ConvertedValueLocal;
	float ResistorVal;
	LED_GPIO_Config();
	Key_GPIO_Config();
	EXTI_PB56_Config();
	USART1_Config();
	DMA_Config();
	ADC1_Volt_Init();
	delay(1);
	
	for(i=0; i<SENDBUFF_SIZE; i++)
	{
		SendBuff[i] = 0xff;
	}
	USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
	while(1)
	{
		delay(10);
		ADC_ConvertedValueLocal = (float) ADC_ConvertedValue/4096*3.3;
		ResistorVal = 3.3/ADC_ConvertedValueLocal*10 - 10;
		printf("Voltage = %f V \r\n", ADC_ConvertedValueLocal);
		printf("Resistor = %f K \r\n", ResistorVal);
		if(Key_Scan(GPIOB, GPIO_Pin_0))\
		{
			printf("\r\n this is a printf demo \r\n");
			//USART_SendData(USART1, 'A');
			//while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
			while(1)
			{
				if(c & 0x80)
				{
					c = ((c - 0x80)<<1) + 0x01;
				}
				else
					c = c<<1;
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

				delay(delay_time);
				if(Key_Scan(GPIOB, GPIO_Pin_7))
					break;
				/*if(Key_Scan(GPIOB, GPIO_Pin_5))
					delay_time += 100;
				if(Key_Scan(GPIOB, GPIO_Pin_6))
				{
					delay_time -= 100;
					if(delay_time < 100)
						delay_time = 100;
				}*/
			}
		}
		if(Key_Scan(GPIOB, GPIO_Pin_1))
			while(1)
			{
				if(c & 0x01)
				{
					c =  (c>>1) + 0x80;
				}
				else
					c = c>>1;
				
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
				
				delay(delay_time);
				if(Key_Scan(GPIOB, GPIO_Pin_7))
					break;
				
				/*if(Key_Scan(GPIOB, GPIO_Pin_5))
					delay_time += 100;
				if(Key_Scan(GPIOB, GPIO_Pin_6))
				{
					delay_time -= 100;
					if(delay_time < 100)
						delay_time = 100;
				}*/
			}
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
