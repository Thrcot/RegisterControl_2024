/*
 * gpio.cpp
 *
 *  Created on: Dec 11, 2024
 *      Author: neoki
 */

#include <gpio/gpio.h>

static bool __is_PA_enable = false;
static bool __is_PB_enable = false;
static bool __is_PC_enable = false;
static bool __is_PD_enable = false;
static bool __is_PH_enable = false;

void GPIO_Port_Mode_Set(PortNum_t __portNum, uint32_t __mode)
{
	switch (__portNum) {
		case PORTA:
			if (__is_PA_enable == false) {
				RCC -> AHB1ENR |= (1U << 0);
				__is_PA_enable = true;
			}
			break;

		case PORTB:
			if (__is_PB_enable == false) {
				RCC -> AHB1ENR |= (1U << 1);
				__is_PB_enable = true;
			}
			break;

		case PORTC:
			if (__is_PC_enable == false) {
				RCC -> AHB1ENR |= (1U << 2);
				__is_PC_enable = true;
			}
			break;

		case PORTD:
			if (__is_PD_enable == false) {
				RCC -> AHB1ENR |= (1U << 3);
				__is_PD_enable = true;
			}
			break;

		case PORTH:
			if (__is_PH_enable == false) {
				RCC -> AHB1ENR |= (1U << 7);
				__is_PH_enable = true;
			}
			break;

		default:
			break;
	}

	((GPIO_TypeDef*)(GPIOx_BASE(__portNum))) -> MODER = __mode;
}

void GPIO_Pin_Mode_Set(PinNum_t __pinNum, IOMode_t __mode)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = (uint8_t)__pinNum & 0x0F;

	switch ((PortNum_t)__port) {
		case PORTA:
			if (__is_PA_enable == false) {
				RCC -> AHB1ENR |= (1U << 0);
				__is_PA_enable = true;
			}
			break;

		case PORTB:
			if (__is_PB_enable == false) {
				RCC -> AHB1ENR |= (1U << 1);
				__is_PB_enable = true;
			}
			break;

		case PORTC:
			if (__is_PC_enable == false) {
				RCC -> AHB1ENR |= (1U << 2);
				__is_PC_enable = true;
			}
			break;

		case PORTD:
			if (__is_PD_enable == false) {
				RCC -> AHB1ENR |= (1U << 3);
				__is_PD_enable = true;
			}
			break;

		case PORTH:
			if (__is_PH_enable == false) {
				RCC -> AHB1ENR |= (1U << 7);
				__is_PH_enable = true;
			}
			break;

		default:
			break;
	}

	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> MODER &= (~(0b11U << (__pin * 2)));
	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> MODER |= (__mode << (__pin * 2));
}
