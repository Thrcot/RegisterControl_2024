#ifndef INC_PERIPHERAL_INIT_H_
#define INC_PERIPHERAL_INIT_H_

#include "stm32f4xx.h"

void RCC_Init(void);

void TIM14_Init(void);

void GPIOA_Init(void);
void GPIOB_Init(void);
void GPIOC_Init(void);
void GPIOD_Init(void);

void USART2_Init(void);

#endif /* INC_PERIPHERAL_INIT_H_ */
