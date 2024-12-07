/*
 * timer.h
 *
 *  Created on: Dec 7, 2024
 *      Author: neoki
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include <stdint.h>
#include "stm32f4xx.h"

extern uint32_t __delay_ms;

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

#endif /* TIMER_TIMER_H_ */
