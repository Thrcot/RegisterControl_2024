#include "stm32f4xx.h"
#include <system/system.h>
#include <gpio/gpio.h>
#include <usart/usart.h>
#include <i2c/i2c.h>
#include <DFPlayer/DFPlayer.h>
#include <SSD1306/ssd1306.h>

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

I2C OLED_BMX(I2C_2, 400000, PB3, PB10);

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
	OLED_Init(&OLED_BMX);

	OLED_Thrcot_Large_Logo_Display();
	delay_ms(1500);
	OLED_AllClear();

	while (1)
	{
		Camera.Println((uint16_t)(I2C2 -> SR1));
		Camera.Println((uint16_t)(I2C2 -> SR2));
		Camera.Println("");
		delay_ms(1000);
	}

	return 0;
}
