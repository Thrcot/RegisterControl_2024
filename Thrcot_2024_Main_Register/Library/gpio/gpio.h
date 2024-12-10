/*
 * gpio.h
 *
 *  Created on: Dec 11, 2024
 *      Author: neoki
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "stm32f4xx.h"

typedef enum {
	PORTA	= 0,
	PORTB,
	PORTC,
	PORTD,
	PORTH	= 7
} PortNum_t;

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
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PB8,
	PB9,
	PB10,
	PB12	= 0x1C,
	PB13,
	PB14,
	PB15,
	PC0		= 0x20,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	PC8,
	PC9,
	PC10,
	PC11,
	PC12,
	PC13,
	PC14,
	PC15,
	PD2		= 0x32,
	PH0		= 0x70,
	PH1
} PinNum_t;

typedef enum {
	INPUT	= 0,
	OUTPUT,
	AF,
	ANALOG
} IOMode_t;

#define GPIOx_OFFSET	0x00000400
#define GPIOx_BASE(x)	(AHB1PERIPH_BASE + (GPIOx_OFFSET * x))

#define LOW				false
#define HIGH			true

void GPIO_Port_Mode_Set(PortNum_t __portNum, uint32_t __mode);
void GPIO_Pin_Mode_Set(PinNum_t __pinNum, IOMode_t __mode);

#endif /* GPIO_GPIO_H_ */
