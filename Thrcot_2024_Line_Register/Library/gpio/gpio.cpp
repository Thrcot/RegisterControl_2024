/*
 * gpio.cpp
 *
 *  Created on: Dec 11, 2024
 *      Author: neoki
 */

#include <gpio/gpio.h>

static bool __is_portA_enable = false;
static bool __is_portB_enable = false;
static bool __is_portF_enable = false;

void GPIO_Port_Mode_Set(PortNum_t __portNum, uint32_t __mode)
{
	switch (__portNum) {
		case PORTA:
			if (__is_portA_enable == false) {
				RCC -> AHBENR |= (1U << 17);
				__is_portA_enable = true;
			}
			break;

		case PORTB:
			if (__is_portA_enable == false) {
				RCC -> AHBENR |= (1U << 18);
			}
			break;

		case PORTF:
			if (__is_portF_enable == false) {
				RCC -> AHBENR |= (1U << 22);
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

	switch (__port) {
		case 0x00:
			if (__is_portA_enable == false) {
				RCC -> AHBENR |= (1U << 17);
				__is_portA_enable = true;
			}
			break;


		case 0x01:
			if (__is_portB_enable == false) {
				RCC -> AHBENR |= (1U << 18);
				__is_portB_enable = true;
			}
			break;

		case 0x05:
			if (__is_portF_enable == false) {
				RCC -> AHBENR |= (1U << 22);
				__is_portF_enable = true;
			}
			break;

		default:
			break;
	}

	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> MODER &= (~(0b11U << (__pin * 2)));
	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> MODER |= (__mode << (__pin * 2));
}
