/*
 * i2c.cpp
 *
 *  Created on: Dec 15, 2024
 *      Author: neoki
 */

#include <i2c/i2c.h>

I2C::I2C(I2C_t __channel, uint32_t __i2c_freq, PinNum_t __pin1, PinNum_t __pin2)
{
	GPIO_Pin_Mode_Set(__pin1, AF);
	GPIO_Pin_Mode_Set(__pin2, AF);

	GPIO_Pin_OutType_Set(__pin1, OPEN_DRAIN);
	GPIO_Pin_OutType_Set(__pin2, OPEN_DRAIN);

	GPIO_Pin_OutSpeed_Set(__pin1, HIGH_SPEED);
	GPIO_Pin_OutSpeed_Set(__pin2, HIGH_SPEED);

	GPIO_Pin_AF_Set(__pin1, AF4);
	GPIO_Pin_AF_Set(__pin2, AF4);

	i2c_ch = __channel;

	switch (__channel) {
		case I2C_1:
			RCC -> APB1ENR |= (1U << 21);

			channel = I2C1;
			break;

		case I2C_2:
			RCC -> APB1ENR |= (1U << 22);

			channel = I2C2;
			break;

		case I2C_3:
			RCC -> APB1ENR |= (1U << 23);

			channel = I2C3;
			break;

		default:
			break;
	}

	channel -> CR1 |= (1U << 15);
	channel -> CR1 &= (~(1U << 15));
	channel -> CR1 &= (~(1U << 0));

	channel -> CR2 &= (~(0b111111 << 0));
	channel -> CR2 |= 45;

	channel -> CCR &= (~(0xFFFU << 0));
	if (__i2c_freq <= 100000) {
		channel -> CCR |= 45000000 / (2 * __i2c_freq);

		channel -> TRISE |= 45;
	} else {
		channel -> CCR |= (1U << 15);
		channel -> CCR |= 45000000 / (3 * __i2c_freq);

		channel -> TRISE |= 15;
	}

	channel -> CR1 |= (1 << 0);
}

bool I2C::MasterTransmit(uint8_t __address, uint8_t* __data, uint32_t __size, uint32_t __timeout)
{
	uint8_t tmp;

	__delay_ms = 0;
	SysTick -> LOAD = 180000 - 1;
	SysTick -> VAL = 0;
	SysTick -> CTRL |= (1U << 1);
	SysTick -> CTRL |= (1U << 0);

	while (channel -> SR2 & (1U << 1)) {
		if (__delay_ms > __timeout) {
			SysTick -> CTRL &= (~(1U << 0));
			SysTick -> CTRL &= (~(1U << 1));
			__delay_ms = 0;

			return false;
		}
	}

	channel -> CR1 |= (1U << 8);
	while (!(channel -> SR1 & (1U << 0))) {
		if (__delay_ms > __timeout) {
			SysTick -> CTRL &= (~(1U << 0));
			SysTick -> CTRL &= (~(1U << 1));
			__delay_ms = 0;

			return false;
		}
	}

	channel -> DR = (__address << 1) | 0;
	while (!(channel -> SR1 & (1U << 1))) {
		if (__delay_ms > __timeout) {
			SysTick -> CTRL &= (~(1U << 0));
			SysTick -> CTRL &= (~(1U << 1));
			__delay_ms = 0;

			return false;
		}
	}

	tmp = (channel -> SR1 | channel -> SR2);
	(void)(tmp);

	for (uint32_t i = 0; i < __size; i++) {
		while (!(channel -> SR1 & (1U << 7))) {
			if (__delay_ms > __timeout) {
				SysTick -> CTRL &= (~(1U << 0));
				SysTick -> CTRL &= (~(1U << 1));
				__delay_ms = 0;

				return false;
			}
		}

		channel -> DR = __data[i];
	}

	while (!(channel -> SR1 & (1U << 2))) {
		if (__delay_ms > __timeout) {
			SysTick -> CTRL &= (~(1U << 0));
			SysTick -> CTRL &= (~(1U << 1));
			__delay_ms = 0;

			return false;
		}
	}

	channel -> CR1 |= (1U << 9);

	SysTick -> CTRL &= (~(1U << 0));
	SysTick -> CTRL &= (~(1U << 1));
	__delay_ms = 0;

	return true;
}
