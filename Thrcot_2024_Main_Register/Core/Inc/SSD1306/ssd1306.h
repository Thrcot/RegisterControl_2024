/*
 * ssd1306_hal.h
 *
 *  Created on: Jul 29, 2024
 *      Author: neoki
 */

#ifndef INC_SSD1306_HAL_H_
#define INC_SSD1306_HAL_H_

#include <math.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include <system/system.h>
#include <gpio/gpio.h>
#include <i2c/i2c.h>
#include <SSD1306/ssd1306_fonts.h>

#define OLED_ADR 0x3c

#define PI 3.1415926535

long map(long x, long min_in, long max_in, long min_out, long max_out);
uint8_t Changing_Y_page(int Y);
uint8_t Changing_Y_val(int Y);

void OLED_Init(I2C* __i2c_ch);
void OLED_Display(void);
void OLED_Thrcot_Logo_Display(void);
void OLED_Thrcot_Large_Logo_Display(void);
void OLED_Dot_Display(int x, int y);
void OLED_Horizontal_Display(int x_s, int x_e, int y);
void OLED_Vartical_Display(int y_s, int y_e, int x);
void OLED_Line_Display(int x_s, int y_s, int x_e, int y_e);
void OLED_Circle_Draw(int x_0, int y_0, int radiation);
void OLED_DataClear(void);
void OLED_AllClear(void);

void OLED_Char_Print(char *message, int x, int y);
void OLED_Int_Print(int val, int x, int y);
void OLED_Double_Print(double val, int x, int y);

#endif /* INC_SSD1306_HAL_H_ */
