/*
 * clock.h
 *
 *  Created on: Dec 7, 2024
 *      Author: neoki
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "stm32f4xx.h"

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

#endif /* CLOCK_H_ */
