/*
 * gpio.h
 *
 *  Created on: Dec 11, 2024
 *      Author: neoki
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f3xx.h"

typedef enum {
	PORTA	= 0,
	PORTB,
	PORTF	= 5
}PortNum_t;

typedef enum {
	PA0		= 0x00,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA8,
	PA9,
	PA10,
	PA11,
	PA12,
	PA13,
	PA14,
	PA15,
	PB0		= 0x10,
	PB1,
	PB3		= 0x13,
	PB4,
	PB5,
	PB6,
	PB7,
	PF0		= 0x50,
	PF1
} PinNum_t;

typedef enum {
	INPUT	= 0,
	OUTPUT,
	AF,
	ANALOG
} IOMode_t;

#define GPIOx_OFFSET	0x00000400UL
#define GPIOx_BASE(x)	(AHB2PERIPH_BASE + (x * GPIOx_OFFSET))

#define LOW				false
#define HIGH			true

void GPIO_Port_Mode_Set(PortNum_t __portNum, uint32_t __mode);
void GPIO_Pin_Mode_Set(PinNum_t __pinNum, IOMode_t __mode);

static inline void GPIO_Pin_LOW(PinNum_t __pinNum)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = ((uint8_t)__pinNum & 0x0F);

	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> ODR &= (~(1U << __pin));
}

static inline void GPIO_Pin_HIGH(PinNum_t __pinNum)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = ((uint8_t)__pinNum & 0x0F);

	((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> ODR |= (1U << __pin);
}

static inline void GPIO_Pin_Write(PinNum_t __pinNum, bool __state)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = ((uint8_t)__pinNum & 0x0F);

	if (__state == false) {
		((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> ODR &= (~(1U << __pin));
	} else {
		((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> ODR |= (1U << __pin);
	}
}

static inline void GPIO_Port_Write(PortNum_t __portNum, uint16_t __state)
{
	((GPIO_TypeDef*)(GPIOx_BASE(__portNum))) -> ODR = __state;
}

static inline bool GPIO_Pin_Read(PinNum_t __pinNum)
{
	uint8_t __port = ((uint8_t)__pinNum & 0xF0) >> 4;
	uint8_t __pin  = ((uint8_t)__pinNum & 0x0F);
	bool __state = (((GPIO_TypeDef*)(GPIOx_BASE(__port))) -> IDR & (1U << __pin)) >> __pin;

	return __state;
}

static inline uint16_t GPIO_Port_Read(PortNum_t __portNum)
{
	return ((GPIO_TypeDef*)(GPIOx_BASE(__portNum))) -> IDR & 0xFFFF;
}

#endif /* GPIO_H_ */
