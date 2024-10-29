#include "peripheral_init.h"

void RCC_Init(void)
{
	RCC -> CFGR |= (5 << 10);
	RCC -> CFGR |= (4 << 13);

	RCC -> PLLCFGR = 0;
	RCC -> PLLCFGR |= (8 << 0);
	RCC -> PLLCFGR |= (360 << 6);
	RCC -> PLLCFGR |= (1 << 22);
	RCC -> PLLCFGR |= (2 << 24);
	RCC -> PLLCFGR |= (2 << 28);

	FLASH -> ACR |= (5 << 0);

	RCC -> CR |= (1 << 16);
	while (!(RCC -> CR & (1 << 17)));

	RCC -> CR |= (1 << 24);
	while (!(RCC -> CR & (1 << 25)));

	RCC -> CFGR |= (2 << 0);
	while (!(RCC -> CFGR & (2 << 0)));
}

void TIM14_Init(void)
{
	RCC -> APB1ENR |= (1 << 8);

	TIM14 -> CR1 &= (~(1 << 0));
}

void USART2_Init(void)
{
	RCC -> APB1ENR |= (1 << 17);

	USART2 -> BRR |= 45000000 / 115200;

	USART2 -> CR1 |= (1 << 2);
	USART2 -> CR1 |= (1 << 3);
	USART2 -> CR1 |= (1 << 13);
}
