#include "stm32f4xx.h"

void RCC_PLL_Init(void);
void SysTick_Init(void);

void delay_ms(uint32_t ms);
void delay_us(unsigned int delay);

int main(void)
{
	RCC_PLL_Init();
	SysTick_Init();

	RCC -> AHB1ENR |= (1 << 2);

	GPIOC -> MODER |= (1 << 26);
	GPIOC -> MODER &= (~(1 << 27));
	GPIOC -> MODER |= (1 << 30);
	GPIOC -> MODER &= (~(1 << 31));

	while (1)
	{
		GPIOC -> ODR |= (1 << 13);
		GPIOC -> ODR &= (~(1 << 15));
		delay_ms(1000);

		GPIOC -> ODR &= (~(1 << 13));
		GPIOC -> ODR |= (1 << 15);
		delay_ms(1000);
	}

	return 0;
}

void RCC_PLL_Init(void)
{
	RCC -> PLLCFGR &= (~(0b111111U << 0));
	RCC -> PLLCFGR |= (8U << 0);
	RCC -> PLLCFGR &= (~(0b111111111U << 6));
	RCC -> PLLCFGR |= (360U << 6);
	RCC -> PLLCFGR |= (1U << 22);

	RCC -> CFGR &= (~(0b111U << 10));
	RCC -> CFGR |= (0b101U << 10);
	RCC -> CFGR &= (~(0b111U << 13));
	RCC -> CFGR |= (0b100U << 13);

	FLASH -> ACR &= (~(0b1111 << 0));
	FLASH -> ACR |= (5U << 0);

	RCC -> CR |= (1U << 16);
	while (!(RCC -> CR & (1 << 17)));

	RCC -> CR |= (1U << 24);
	while (!(RCC -> CR & (1U << 25)));

	RCC -> CFGR &= (~(0b11U << 0));
	RCC -> CFGR |= (0b10U << 0);
	while (!(RCC -> CFGR & (0b10 << 2)));
}

void SysTick_Init(void)
{
	SysTick -> CTRL |= (1 << 2);
}

void delay_ms(uint32_t ms)
{
	SysTick -> LOAD = 180000 - 1;
	SysTick -> VAL = 0;
	SysTick -> CTRL |= (1 << 0);

	for (uint32_t i = 0; i < ms; i++) {
		while (!(SysTick -> CTRL & (1 << 16)));
	}

	SysTick -> CTRL &= (~(1 << 0));
}
