/*
 * clock.h
 *
 *  Created on: Dec 7, 2024
 *      Author: neoki
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "stm32f4xx.h"

extern uint32_t __delay_ms;

static inline void RCC_PLL_Init(void)
{
	RCC -> PLLCFGR &= (~(0b111111U << 0));
	RCC -> PLLCFGR |= (8U << 0);
	RCC -> PLLCFGR &= (~(0b111111111U << 6));
	RCC -> PLLCFGR |= (360U << 6);
	RCC -> PLLCFGR |= (1U << 22);

	RCC -> CFGR &= (~(0b111U << 10));
	RCC -> CFGR |= (0b101U << 10);
	RCC -> CFGR &= (~(0b111U << 13));
	RCC -> CFGR |= (0b100U << 13);

	FLASH -> ACR &= (~(0b1111 << 0));
	FLASH -> ACR |= (5U << 0);

	RCC -> CR |= (1U << 16);
	while (!(RCC -> CR & (1 << 17)));

	RCC -> CR |= (1U << 24);
	while (!(RCC -> CR & (1U << 25)));

	RCC -> CFGR &= (~(0b11U << 0));
	RCC -> CFGR |= (0b10U << 0);
	while (!(RCC -> CFGR & (0b10 << 2)));
}

static inline void SysTick_Init(void)
{
	SysTick -> CTRL |= (1 << 2);
}

static inline void delay_ms(uint32_t ms)
{
	SysTick -> LOAD = 180000 - 1;
	SysTick -> VAL = 0;
	SysTick -> CTRL |= (1 << 0);

	for (uint32_t i = 0; i < ms; i++) {
		while (!(SysTick -> CTRL & (1 << 16)));
	}

	SysTick -> CTRL &= (~(1 << 0));
}

static inline void delay_us(uint32_t us)
{
	SysTick -> LOAD = 180 - 1;
	SysTick -> VAL = 0;
	SysTick -> CTRL |= (1 << 0);

	for (uint32_t i = 0; i < us; i++) {
		while (!(SysTick -> CTRL & (1 << 16)));
	}

	SysTick -> CTRL &= (~(1 << 16));
}

#endif /* SYSTEM_H_ */
