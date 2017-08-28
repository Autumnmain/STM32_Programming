#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"
#include "main.h"

#define LED_ON(A,PIN) GPIO_ResetBits(A,PIN)
#define LED_OFF(A,PIN) GPIO_SetBits(A,PIN)

void LED_GPIO_Config(void);
void Key_GPIO_Config(void);
u8 Key_Scan(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);

#endif /* __LED_H */
