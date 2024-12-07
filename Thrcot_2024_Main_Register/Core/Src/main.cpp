#include <stdint.h>

#include "stm32f4xx.h"
#include <clock.h>
#include <timer.h>
#include <usart/usart.h>

USART Camera(UART_5, 115200);

int main(void)
{
	RCC_PLL_Init();
	SysTick_Init();

	RCC -> AHB1ENR |= (1U << 2);
	RCC -> AHB1ENR |= (1U << 3);

	GPIOC -> MODER &= (~(1U << 24));
	GPIOC -> MODER |= (1U << 25);

	GPIOC -> AFR[1] &= (~(1U << 16));
	GPIOC -> AFR[1] &= (~(1U << 17));
	GPIOC -> AFR[1] &= (~(1U << 18));
	GPIOC -> AFR[1] |= (1U << 19);

	GPIOD -> MODER &= (~(1U << 4));
	GPIOD -> MODER |= (1U << 5);

	GPIOD -> AFR[0] &= (~(1U << 8));
	GPIOD -> AFR[0] &= (~(1U << 9));
	GPIOD -> AFR[0] &= (~(1U << 10));
	GPIOD -> AFR[0] |= (1U << 11);

	while (1)
	{
		uint8_t message[] = "Hello!\n\r";

		Camera.Transmit(message, sizeof(message), 1000);
		delay_ms(1000);
	}

	return 0;
}
