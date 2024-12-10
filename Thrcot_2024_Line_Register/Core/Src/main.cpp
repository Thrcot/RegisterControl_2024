#include "stm32f3xx.h"
#include <system.h>
#include <gpio/gpio.h>

#define DBG_LED		PA15

int main(void)
{
	RCC_PLL_Init();
	SysTick_Init();

	GPIO_Pin_Mode_Set(DBG_LED, OUTPUT);

	while(1)
	{
		GPIO_Pin_Write(DBG_LED, HIGH);
		delay_ms(100);

		GPIO_Pin_Write(DBG_LED, LOW);
		delay_ms(100);
	}

	return 0;
}
