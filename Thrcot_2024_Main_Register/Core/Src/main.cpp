#include "stm32f4xx.h"
#include <system.h>
#include <gpio/gpio.h>
#include <usart/usart.h>

#define DBG_LD1		PC13
#define DBG_LD2		PC15

USART Line(USART_2, 115200);

int main(void)
{
	RCC_PLL_Init();
	SysTick_Init();

	RCC -> AHB1ENR |= (1U << 0);

	GPIOA -> MODER &= (~(1 << 4));
	GPIOA -> MODER |= (1 << 5);
	GPIOA -> MODER &= (~(1 << 6));
	GPIOA -> MODER |= (1 << 7);

	GPIOA -> AFR[0] &= (~(0b1111 << 8));
	GPIOA -> AFR[0] |= (0b0111 << 8);
	GPIOA -> AFR[0] &= (~(0b1111 << 12));
	GPIOA -> AFR[0] |= (0b0111 << 12);

	GPIO_Pin_Mode_Set(DBG_LD1, OUTPUT);

	while (1)
	{
		uint8_t message[10] = {0};

		if (Line.Receive(message, 5, 1000) == true) {
			Line.Transmit(message, 5, 1000);
			GPIOC -> ODR ^= (1 << 13);
		}
	}

	return 0;
}
