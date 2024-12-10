/*
 * system.h
 *
 *  Created on: Dec 11, 2024
 *      Author: neoki
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "stm32f3xx.h"

extern uint32_t __ms_count;

static inline void RCC_PLL_Init(void)
{
	RCC -> CFGR &= (~(1 << 16));
	RCC -> CFGR |= (4 << 8);
	RCC -> CFGR |= (15 << 18);

	FLASH -> ACR |= (2 << 0);

	RCC -> CR |= (1 << 24);
	while (!(RCC -> CR & (1 << 25)));

	RCC -> CFGR |= (2 << 0);
	while ((RCC -> CFGR & (3 << 2)) != (2 << 2));
}

static inline void SysTick_Init(void)
{
	SysTick -> CTRL |= (1 << 2);
}

static inline void delay_ms(uint32_t __ms)
{
	SysTick -> LOAD = 64000 - 1;
	SysTick -> VAL = 0;
	SysTick -> CTRL |= (1 << 0);

	for (uint32_t i = 0; i < __ms; i++) {
		while (!(SysTick -> CTRL & (1 << 16)));
	}

	SysTick -> CTRL &= (~(1 << 0));
}

#endif /* SYSTEM_H_ */
