#include "stm32f4xx.h"

void RCC_Init(void);
void GPIO_Init(void);
void USART1_Init(void);

int main(void)
{
	RCC_Init();
	GPIO_Init();

	GPIOC -> ODR |= (1 << 13);

	while (1)
	{
		GPIOC -> ODR ^= (1 << 13);
		GPIOC -> ODR ^= (1 << 15);

		for (int i = 0; i < 1000000; i++);
	}

	return 0;
}

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

void GPIO_Init(void)
{
	RCC -> AHB1ENR |= (1 << 0);
	RCC -> AHB1ENR |= (1 << 1);
	RCC -> AHB1ENR |= (1 << 2);
	RCC -> AHB1ENR |= (1 << 3);

	GPIOA -> MODER = 0x1A680CAA;
	GPIOB -> MODER = 0x002AAA8F;
	GPIOC -> MODER = 0x46AAA3FF;
	GPIOD -> MODER = 0x00000020;
}
