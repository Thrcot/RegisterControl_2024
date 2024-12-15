/*
 * usart.h
 *
 *  Created on: Dec 8, 2024
 *      Author: neoki
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"
#include <gpio/gpio.h>
#include <system/system.h>

typedef enum {
	USART_1,
	USART_2,
	USART_3,
	UART_4,
	UART_5,
	USART_6
} USART_t;

class USART {
	public:
		USART(USART_t usart_channel, uint32_t baudrate);

		void pinSet(PinNum_t __pinNum1, PinNum_t __pinNum2);

		bool Transmit(uint8_t* tx_buf, uint32_t data_size, uint32_t timeout);
		bool Transmit(const char* tx_buf, uint32_t data_size, uint32_t timeout);

		bool Print(const char* __msg);
		bool Print(int8_t __num);
		bool Print(uint8_t __num);
		bool Print(int16_t __num);
		bool Print(uint16_t __num);
		bool Print(int32_t __num);
		bool Print(uint32_t __num);

		bool Println(const char* __msg);
		bool Println(int8_t __num);
		bool Println(uint8_t __num);
		bool Println(int16_t __num);
		bool Println(uint16_t __num);
		bool Println(int32_t __num);
		bool Println(uint32_t __num);

		bool Receive(uint8_t* rx_buf, uint32_t data_size, uint32_t timeout);


	private:
		USART_t	usart_ch;
		USART_TypeDef* channel;
};

#endif /* UART_H_ */
