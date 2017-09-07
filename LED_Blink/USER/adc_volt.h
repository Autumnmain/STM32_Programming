#ifndef __ADC_VOLT_H
#define __ADC_VOLT_H

#define ADC1_DR_Address ((u32)0x40012400 + 0x4c)

#include "stm32f10x.h"
void ADC1_Volt_Init(void);
static void ADC1_GPIO_Config(void);
static void ADC1_Mode_Config(void);

#endif /* __ADC_VOLT_H */
