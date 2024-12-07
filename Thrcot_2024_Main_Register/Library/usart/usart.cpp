/*
 * usart.cpp
 *
 *  Created on: Dec 8, 2024
 *      Author: neoki
 */

#include <usart/usart.h>

USART::USART(USART_t usart_channel, uint32_t baudrate)
{
	switch (usart_channel) {
		case USART_1:
			RCC -> APB2ENR |= (1U << 4);

			channel = USART1;
			APBx_freq = 90000000;
			break;

		case USART_2:
			RCC -> APB1ENR |= (1U << 17);

			channel = USART2;
			APBx_freq = 45000000;
			break;

		case USART_3:
			RCC -> APB1ENR |= (1U << 18);

			channel = USART3;
			APBx_freq = 45000000;
			break;

		case UART_4:
			RCC -> APB1ENR |= (1U << 19);

			channel = UART4;
			APBx_freq = 45000000;
			break;

		case UART_5:
			RCC -> APB1ENR |= (1U << 20);

			channel = UART5;
			APBx_freq = 45000000;
			break;

		case USART_6:
			RCC -> APB2ENR |= (1U << 5);

			channel = USART6;
			APBx_freq = 90000000;
		default:
			break;
	}

	channel -> BRR = APBx_freq / baudrate;

	channel -> CR1 |= (1U << 2);
	channel -> CR1 |= (1U << 3);
	channel -> CR1 |= (1U << 13);
}

bool USART::Transmit(uint8_t* tx_buf, uint32_t data_size, uint32_t timeout)
{
	__delay_ms = 0;
	SysTick -> LOAD = 180000 - 1;
	SysTick -> VAL = 0;
	SysTick -> CTRL |= (1U << 1);
	SysTick -> CTRL |= (1U << 0);

	for (uint32_t i = 0; i < data_size; i++) {
		while (!(channel -> SR & (1U << 7))) {
			if (__delay_ms > timeout) {
				SysTick -> CTRL &= (~(1U << 0));
				SysTick -> CTRL &= (~(1U << 1));
				__delay_ms = 0;

				return false;
			}
		}

		channel -> DR = tx_buf[i];

		while (!(channel -> SR & (1U << 6)));
	}

	SysTick -> CTRL &= (~(1U << 0));
	SysTick -> CTRL &= (~(1U << 1));
	__delay_ms = 0;

	return true;
}
