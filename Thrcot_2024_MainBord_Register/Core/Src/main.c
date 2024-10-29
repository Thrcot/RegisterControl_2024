#include "main.h"

void delay_ms(unsigned int delay);
void delay_us(unsigned int delay);

int main(void)
{
	RCC_Init();
	TIM14_Init();

	while (1)
	{
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
