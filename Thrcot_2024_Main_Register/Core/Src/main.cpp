#include "stm32f4xx.h"
#include <system.h>
#include <gpio/gpio.h>
#include <usart/usart.h>
#include <DFPlayer/DFPlayer.h>

#define DBG_LD1		PC13
#define DBG_LD2		PC15

#define SW1			PA6
#define SW2			PA7
#define SW3			PA8
#define SW_START	PC14

USART Line(USART_2, 115200);
USART WiFi(USART_3, 115200);
USART Camera(UART_5, 115200);
USART DFPlayer(USART_6, 9600);

int main(void)
{
	RCC_PLL_Init();
	SysTick_Init();

	Line.pinSet(PA2, PA3);
	WiFi.pinSet(PC10, PC11);
	Camera.pinSet(PC12, PD2);
	DFPlayer.pinSet(PC6, PC7);

	GPIO_Pin_Mode_Set(DBG_LD1, OUTPUT);
	GPIO_Pin_Mode_Set(DBG_LD2, OUTPUT);

	GPIO_Pin_Mode_Set(SW1, INPUT);
	GPIO_Pin_Mode_Set(SW2, INPUT);
	GPIO_Pin_Mode_Set(SW3, INPUT);
	GPIO_Pin_Mode_Set(SW_START, INPUT);

	DFP_Init(&DFPlayer);

	while (1)
	{
		uint8_t msg[10] = "Hello\n\r";

		Camera.Transmit(msg, sizeof(msg), 1000);
		delay_ms(1000);
	}

	return 0;
}
