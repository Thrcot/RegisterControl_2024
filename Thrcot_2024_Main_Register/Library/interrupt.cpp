/*
 * interrupt.cpp
 *
 *  Created on: Dec 8, 2024
 *      Author: neoki
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "timer.h"

uint32_t __delay_ms = 0;

void SysTick_Handler(void)
{
	__delay_ms++;
}
