#include "stm32f4xx.h"
#include "peripheral_init.h"

void delay_ms(unsigned int delay);
void delay_us(unsigned int delay);

void USART2_Transmit(uint8_t *data, int size);
void USART2_Print(uint8_t *data);

int main(void)
{
	RCC_Init();
	TIM14_Init();
	GPIOA_Init();
	GPIOB_Init();
	GPIOC_Init();
	GPIOD_Init();
	USART2_Init();

	while (1)
	{
		USART2_Print("Hello World.\n\r");

		delay_ms(1000);
	}

	return 0;
}

void delay_ms(unsigned int delay)
{
	TIM14 -> SR &= (~(1 << 0));
	TIM14 -> PSC = 45000 - 1;
	TIM14 -> CNT = 0;
	TIM14 -> ARR = delay - 1;
	TIM14 -> CR1 |= (1 << 0);

	while (!(TIM14 -> SR & (1 << 0)));

	TIM14 -> CR1 &= (~(1 << 0));
}

void delay_us(unsigned int delay)
{
	TIM14 -> SR &= (~(1 << 0));
	TIM14 -> PSC = 45 - 1;
	TIM14 -> CNT = 0;
	TIM14 -> ARR = delay - 1;
	TIM14 -> CR1 |= (1 << 0);

	while (!(TIM14 -> SR & (1 << 0)));

	TIM14 -> CR1 &= (~(1 << 0));
}

void USART2_Transmit(uint8_t *data, int size)
{
	for (int i = 0; i < size; i++) {
		while (!(USART2 -> SR & (1 << 7)));

		USART2 -> DR = data[i];

		while (!(USART2 -> SR & (1 << 6)));
	}
}

void USART2_Print(uint8_t *data)
{
	for (int i = 0; data[i] != '\0'; i++) {
		while (!(USART2 -> SR & (1 << 7)));

		USART2 -> DR = data[i];

		while (!(USART2 -> SR & (1 << 6)));
	}
}
