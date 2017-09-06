#ifndef __DMA_H
#define __DMA_H

#define USART1_DR_Base 0x40013804
#define SENDBUFF_SIZE 5000

#include "stm32f10x.h"
static void NVIC_DMA1_Config(void);
void DMA_Config(void);

#endif /* __DMA_H */
