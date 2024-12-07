#include <clock.h>
#include <timer.h>
#include "stm32f4xx.h"

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
