/*
 * usart.h
 *
 *  Created on: Dec 8, 2024
 *      Author: neoki
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"
#include <system.h>

typedef enum {
	USART_1		= 1,
	USART_2,
	USART_3,
	UART_4,
	UART_5,
	USART_6
} USART_t;

class USART {
	public:
		USART(USART_t usart_channel, uint32_t baudrate);
		bool Transmit(uint8_t* tx_buf, uint32_t data_size, uint32_t timeout);
		bool Receive(uint8_t* rx_buf, uint32_t data_size, uint32_t timeout);

	private:
		USART_TypeDef* channel;
		uint32_t APBx_freq;
};

#endif /* UART_H_ */
