#include "f446_gpio.h"

void GPIOA_Init(void)
{
	RCC -> AHB1ENR |= (1 << 0);

	GPIOA -> MODER &= (~0xC33FFFFF);
	GPIOA -> MODER |= (0b10 << 0);
	GPIOA -> MODER |= (0b10 << 2);
	GPIOA -> MODER |= (0b10 << 4);
	GPIOA -> MODER |= (0b10 << 6);
	GPIOA -> MODER |= (0b11 << 8);
	GPIOA -> MODER |= (0b11 << 10);
	GPIOA -> MODER |= (0b00 << 12);
	GPIOA -> MODER |= (0b00 << 14);
	GPIOA -> MODER |= (0b00 << 16);
	GPIOA -> MODER |= (0b10 << 18);
	GPIOA -> MODER |= (0b10 << 20);
	GPIOA -> MODER |= (0b01 << 24);
	GPIOA -> MODER |= (0b11 << 30);

	GPIOA -> AFR[0] &= (~0x0000FFFF);
	GPIOA -> AFR[0] |= (0b0010 << 0);
	GPIOA -> AFR[0] |= (0b0010 << 4);
	GPIOA -> AFR[0] |= (0b0111 << 8);
	GPIOA -> AFR[0] |= (0b0111 << 12);

	GPIOA -> AFR[1] &= (~0x00000FF0);
	GPIOA -> AFR[1] |= (0b0111 << 4);
	GPIOA -> AFR[1] |= (0b0111 << 8);
}

void GPIOB_Init(void)
{
	RCC -> AHB1ENR |= (1 << 1);

	GPIOB -> MODER &= (~0x003FFFCF);
	GPIOB -> MODER |= (0b11 << 0);
	GPIOB -> MODER |= (0b11 << 2);
	GPIOB -> MODER |= (0b10 << 6);
	GPIOB -> MODER |= (0b10 << 8);
	GPIOB -> MODER |= (0b10 << 10);
	GPIOB -> MODER |= (0b10 << 12);
	GPIOB -> MODER |= (0b10 << 14);
	GPIOB -> MODER |= (0b10 << 16);
	GPIOB -> MODER |= (0b10 << 18);
	GPIOB -> MODER |= (0b10 << 20);

	GPIOB -> AFR[0] &= (~0xFFFFF000);
	GPIOB -> AFR[0] |= (0b0100 << 12);
	GPIOB -> AFR[0] |= (0b0010 << 16);
	GPIOB -> AFR[0] |= (0b0010 << 20);
	GPIOB -> AFR[0] |= (0b0010 << 24);
	GPIOB -> AFR[0] |= (0b0010 << 28);

	GPIOB -> AFR[1] &= (~0x00000FFF);
	GPIOB -> AFR[1] |= (0b0010 << 0);
	GPIOB -> AFR[1] |= (0b0010 << 4);
	GPIOB -> AFR[1] |= (0b0100 << 8);
}

void GPIOC_Init(void)
{
	RCC -> AHB1ENR |= (1 << 2);

	GPIOC -> MODER &= (~0xFFFFF3FF);
	GPIOC -> MODER |= (0b11 << 0);
	GPIOC -> MODER |= (0b11 << 2);
	GPIOC -> MODER |= (0b11 << 4);
	GPIOC -> MODER |= (0b11 << 6);
	GPIOC -> MODER |= (0b11 << 8);
	GPIOC -> MODER |= (0b10 << 12);
	GPIOC -> MODER |= (0b10 << 14);
	GPIOC -> MODER |= (0b10 << 16);
	GPIOC -> MODER |= (0b10 << 18);
	GPIOC -> MODER |= (0b10 << 20);
	GPIOC -> MODER |= (0b10 << 22);
	GPIOC -> MODER |= (0b10 << 24);
	GPIOC -> MODER |= (0b01 << 26);
	GPIOC -> MODER |= (0b00 << 28);
	GPIOC -> MODER |= (0b01 << 30);

	GPIOC -> AFR[0] &= (~0xFF000000);
	GPIOC -> AFR[0] |= (0b1000 << 24);
	GPIOC -> AFR[0] |= (0b1000 << 28);

	GPIOC -> AFR[1] &= (~0x000FFFFF);
	GPIOC -> AFR[1] |= (0b0010 << 0);
	GPIOC -> AFR[1] |= (0b0010 << 4);
	GPIOC -> AFR[1] |= (0b0111 << 8);
	GPIOC -> AFR[1] |= (0b0111 << 12);
	GPIOC -> AFR[1] |= (0b1000 << 16);
}

void GPIOD_Init(void)
{
	RCC -> AHB1ENR |= (1 << 3);

	GPIOD -> MODER &= (~(0b11 << 4));
	GPIOD -> MODER |= (0b10 << 4);

	GPIOD -> AFR[0] &= (~(0b1111 << 8));
	GPIOD -> AFR[0] |= (0b1000 << 8);
}
