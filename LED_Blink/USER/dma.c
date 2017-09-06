#include "dma.h"
uint8_t SendBuff[SENDBUFF_SIZE];

void DMA_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	
	/* Enable DMA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	NVIC_DMA1_Config();
	
	/* Set DMA source: memory and usart address */
	DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_DR_Base;
	/* Set memory address */
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)SendBuff;
	/* Set transmission direction */
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	/* Set memory size */
	DMA_InitStructure.DMA_MemoryDataSize = SENDBUFF_SIZE;
	/* Peripheral address increase disable */
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	/* Memory address increase enable */
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	/* Peripheral data unit */
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	/* Memory data unit */
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	/* DMA transfer mode */
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	/* Set priority */
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	/* Forbiden memory to memory transmission */
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	/* Set DMA1 channel 4 */
	DMA_Init(DMA1_Channel4, &DMA_InitStructure);
	/* Enable DMA1 Channel 4 */
	DMA_Cmd(DMA1_Channel4, ENABLE);
	/* Enable DMA1 interrupt */
	DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE);
}

static void NVIC_DMA1_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	/* Set preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
}
