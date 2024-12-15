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

void GPIO_Pin_OutType_Set(PinNum_t __pinNum, OutType_t __out_mode)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = (uint8_t)__pinNum & 0x0F;

	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> OTYPER &= (~(1U << __pin));
	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> OTYPER |= (__out_mode << __pin);
}

void GPIO_Pin_OutSpeed_Set(PinNum_t __pinNum, OutSpeed_t __out_speed)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = (uint8_t)__pinNum & 0x0F;

	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> OSPEEDR &= (~(0b11U << (__pin * 2)));
	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> OSPEEDR |= (__out_speed << (__pin * 2));
}

void GPIO_Pin_Pull_Set(PinNum_t __pinNum, Pull_t __pull_state)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = (uint8_t)__pinNum & 0x0F;

	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> PUPDR &= (~(0b11U << (__pin * 2)));
	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> PUPDR |= (__pull_state << (__pin * 2));
}

void GPIO_Pin_AF_Set(PinNum_t __pinNum, AFx_t __AFNum)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = (uint8_t)__pinNum & 0x0F;

	if (__pin <= 7) {
		((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> AFR[0] &= (~(0b1111U << (__pin * 4)));
		((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> AFR[0] |= (__AFNum << (__pin * 4));
	} else {
		((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> AFR[1] &= (~(0b1111U << ((__pin - 8) * 4)));
		((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> AFR[1] |= (__AFNum << ((__pin - 8) * 4));
	}
}
