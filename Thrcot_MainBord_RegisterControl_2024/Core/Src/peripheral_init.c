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

void GPIOA_Init(void)
{
	RCC -> AHB1ENR |= (1 << 0);

	GPIOA -> MODER &= (~(1 << 0));
	GPIOA -> MODER |= (1 << 1);
	GPIOA -> MODER &= (~(1 << 2));
	GPIOA -> MODER |= (1 << 3);
	GPIOA -> MODER &= (~(1 << 4));
	GPIOA -> MODER |= (1 << 5);
	GPIOA -> MODER &= (~(1 << 6));
	GPIOA -> MODER |= (1 << 7);
	GPIOA -> MODER |= (1 << 8);
	GPIOA -> MODER |= (1 << 9);
	GPIOA -> MODER |= (1 << 10);
	GPIOA -> MODER |= (1 << 11);
	GPIOA -> MODER &= (~(1 << 12));
	GPIOA -> MODER &= (~(1 << 13));
	GPIOA -> MODER &= (~(1 << 14));
	GPIOA -> MODER &= (~(1 << 15));
	GPIOA -> MODER &= (~(1 << 16));
	GPIOA -> MODER &= (~(1 << 17));
	GPIOA -> MODER |= (1 << 24);
	GPIOA -> MODER &= (~(1 << 25));
	GPIOA -> MODER |= (1 << 30);
	GPIOA -> MODER &= (~(1 << 31));

	GPIOA -> AFR[0] &= (~(1 << 0));
	GPIOA -> AFR[0] |= (1 << 1);
	GPIOA -> AFR[0] &= (~(1 << 2));
	GPIOA -> AFR[0] &= (~(1 << 3));
	GPIOA -> AFR[0] &= (~(1 << 4));
	GPIOA -> AFR[0] |= (1 << 5);
	GPIOA -> AFR[0] &= (~(1 << 6));
	GPIOA -> AFR[0] &= (~(1 << 7));
	GPIOA -> AFR[0] |= (1 << 8);
	GPIOA -> AFR[0] |= (1 << 9);
	GPIOA -> AFR[0] |= (1 << 10);
	GPIOA -> AFR[0] &= (~(1 << 11));
	GPIOA -> AFR[0] |= (1 << 12);
	GPIOA -> AFR[0] |= (1 << 13);
	GPIOA -> AFR[0] |= (1 << 14);
	GPIOA -> AFR[0] &= (~(1 << 15));
}

void GPIOB_Init(void)
{
	RCC -> AHB1ENR |= (1 << 1);

	GPIOB -> MODER |= (1 << 0);
	GPIOB -> MODER |= (1 << 1);
	GPIOB -> MODER |= (1 << 2);
	GPIOB -> MODER |= (1 << 3);
	GPIOB -> MODER &= (~(1 << 4));
	GPIOB -> MODER &= (~(1 << 5));
	GPIOB -> MODER &= (~(1 << 6));
	GPIOB -> MODER |= (1 << 7);
	GPIOB -> MODER &= (~(1 << 8));
	GPIOB -> MODER |= (1 << 9);
	GPIOB -> MODER &= (~(1 << 10));
	GPIOB -> MODER |= (1 << 11);
	GPIOB -> MODER &= (~(1 << 12));
	GPIOB -> MODER |= (1 << 13);
	GPIOB -> MODER &= (~(1 << 14));
	GPIOB -> MODER |= (1 << 15);
	GPIOB -> MODER &= (~(1 << 16));
	GPIOB -> MODER |= (1 << 17);
	GPIOB -> MODER &= (~(1 << 18));
	GPIOB -> MODER |= (1 << 19);
	GPIOB -> MODER &= (~(1 << 20));
	GPIOB -> MODER |= (1 << 21);

	GPIOB -> AFR[0] &= (~(1 << 12));
	GPIOB -> AFR[0] &= (~(1 << 13));
	GPIOB -> AFR[0] |= (1 << 14);
	GPIOB -> AFR[0] &= (~(1 << 15));
	GPIOB -> AFR[0] &= (~(1 << 16));
	GPIOB -> AFR[0] |= (1 << 17);
	GPIOB -> AFR[0] &= (~(1 << 18));
	GPIOB -> AFR[0] &= (~(1 << 19));
	GPIOB -> AFR[0] &= (~(1 << 20));
	GPIOB -> AFR[0] |= (1 << 21);
	GPIOB -> AFR[0] &= (~(1 << 22));
	GPIOB -> AFR[0] &= (~(1 << 23));
	GPIOB -> AFR[0] &= (~(1 << 24));
	GPIOB -> AFR[0] |= (1 << 25);
	GPIOB -> AFR[0] &= (~(1 << 26));
	GPIOB -> AFR[0] &= (~(1 << 27));
	GPIOB -> AFR[0] &= (~(1 << 28));
	GPIOB -> AFR[0] |= (1 << 29);
	GPIOB -> AFR[0] &= (~(1 << 30));
	GPIOB -> AFR[0] &= (~(1 << 31));

	GPIOB -> AFR[1] &= (~(1 << 0));
	GPIOB -> AFR[1] |= (1 << 1);
	GPIOB -> AFR[1] &= (~(1 << 2));
	GPIOB -> AFR[1] &= (~(1 << 3));
	GPIOB -> AFR[1] &= (~(1 << 4));
	GPIOB -> AFR[1] |= (1 << 5);
	GPIOB -> AFR[1] &= (~(1 << 6));
	GPIOB -> AFR[1] &= (~(1 << 7));
	GPIOB -> AFR[1] &= (~(1 << 8));
	GPIOB -> AFR[1] &= (~(1 << 9));
	GPIOB -> AFR[1] |= (1 << 10);
	GPIOB -> AFR[1] &= (1 << 11);
}

void GPIOC_Init(void)
{
	RCC -> AHB1ENR |= (1 << 2);

	GPIOC -> MODER |= (1 << 0);
	GPIOC -> MODER |= (1 << 1);
	GPIOC -> MODER |= (1 << 2);
	GPIOC -> MODER |= (1 << 3);
	GPIOC -> MODER |= (1 << 4);
	GPIOC -> MODER |= (1 << 5);
	GPIOC -> MODER |= (1 << 6);
	GPIOC -> MODER |= (1 << 7);
	GPIOC -> MODER |= (1 << 8);
	GPIOC -> MODER |= (1 << 9);
	GPIOC -> MODER &= (~(1 << 12));
	GPIOC -> MODER |= (1 << 13);
	GPIOC -> MODER &= (~(1 << 14));
	GPIOC -> MODER |= (1 << 15);
	GPIOC -> MODER &= (~(1 << 16));
	GPIOC -> MODER |= (1 << 17);
	GPIOC -> MODER &= (~(1 << 18));
	GPIOC -> MODER |= (1 << 19);
	GPIOC -> MODER &= (~(1 << 20));
	GPIOC -> MODER |= (1 << 21);
	GPIOC -> MODER &= (~(1 << 22));
	GPIOC -> MODER |= (1 << 23);
	GPIOC -> MODER &= (~(1 << 24));
	GPIOC -> MODER |= (1 << 25);
	GPIOC -> MODER |= (1 << 26);
	GPIOC -> MODER &= (~(1 << 27));
	GPIOC -> MODER &= (~(1 << 28));
	GPIOC -> MODER &= (~(1 << 29));
	GPIOC -> MODER |= (1 << 30);
	GPIOC -> MODER &= (~(1 << 31));

	GPIOC -> AFR[0] &= (~(1 << 24));
	GPIOC -> AFR[0] &= (~(1 << 25));
	GPIOC -> AFR[0] &= (~(1 << 26));
	GPIOC -> AFR[0] |= (1 << 27);
	GPIOC -> AFR[0] &= (~(1 << 28));
	GPIOC -> AFR[0] &= (~(1 << 29));
	GPIOC -> AFR[0] &= (~(1 << 30));
	GPIOC -> AFR[0] |= (1 << 31);

	GPIOC -> AFR[1] &= (~(1 << 0));
	GPIOC -> AFR[1] |= (1 << 1);
	GPIOC -> AFR[1] &= (~(1 << 2));
	GPIOC -> AFR[1] &= (~(1 << 3));
	GPIOC -> AFR[1] &= (~(1 << 4));
	GPIOC -> AFR[1] |= (1 << 5);
	GPIOC -> AFR[1] &= (~(1 << 6));
	GPIOC -> AFR[1] &= (~(1 << 7));
	GPIOC -> AFR[1] |= (1 << 8);
	GPIOC -> AFR[1] |= (1 << 9);
	GPIOC -> AFR[1] |= (1 << 10);
	GPIOC -> AFR[1] &= (~(1 << 11));
	GPIOC -> AFR[1] |= (1 << 12);
	GPIOC -> AFR[1] |= (1 << 13);
	GPIOC -> AFR[1] |= (1 << 14);
	GPIOC -> AFR[1] &= (~(1 << 15));
	GPIOC -> AFR[1] &= (~(1 << 16));
	GPIOC -> AFR[1] &= (~(1 << 17));
	GPIOC -> AFR[1] &= (~(1 << 18));
	GPIOC -> AFR[1] |= (1 << 19);
}

void GPIOD_Init(void)
{
	RCC -> AHB1ENR |= (1 << 3);

	GPIOD -> MODER &= (~(1 << 4));
	GPIOD -> MODER |= (1 << 5);

	GPIOD -> AFR[0] &= (~(1 << 8));
	GPIOD -> AFR[0] &= (~(1 << 9));
	GPIOD -> AFR[0] &= (~(1 << 10));
	GPIOD -> AFR[0] |= (1 << 11);
}

void USART2_Init(void)
{
	RCC -> APB1ENR |= (1 << 17);

	USART2 -> BRR |= 45000000 / 115200;

	USART2 -> CR1 |= (1 << 2);
	USART2 -> CR1 |= (1 << 3);
	USART2 -> CR1 |= (1 << 13);
}
