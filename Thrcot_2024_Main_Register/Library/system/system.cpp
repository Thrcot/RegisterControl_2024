/*
 * system.cpp
 *
 *  Created on: Dec 12, 2024
 *      Author: neoki
 */

#include <system/system.h>

int __pow(int num, int count)
{
	int __num = num;

	if (count == 0) {
		return 1;
	} else {
		for (int i = 1; i < count; i++) {
			__num *= num;
		}

		return __num;
	}
}

void __ToStr_8(int8_t num, char* str)
{
	bool digit = false;
	int i = 0;

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
	} else if (num < 0) {
		str[0] = '-';
		num *= -1;
		i = 1;
	}

	for (int j = 0; j < 3; j++) {
		if (num / __pow(10, (2 - j)) == 0) {
			if (digit == true) {
				str[i] = '0';
				i++;
			}
		} else {
			str[i] = (char)(num / __pow(10, (2 - j))) + '0';
			i++;
			digit = true;
		}

		num -= (num / __pow(10, (2 - j))) * __pow(10, (2 - j));
	}

	str[i] = '\0';
}

void __ToStr_u8(uint8_t num, char* str)
{
	bool digit = false;
	int i = 0;

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
	}

	for (int j = 0; j < 3; j++) {
		if (num / __pow(10, (2 - j)) == 0) {
			if (digit == true) {
				str[i] = '0';
				i++;
			}
		} else {
			str[i] = (char)(num / __pow(10, (2 - j))) + '0';
			i++;
			digit = true;
		}

		num -= (num / __pow(10, (2 - j))) * __pow(10, (2 - j));
	}

	str[i] = '\0';
}

void __ToStr_16(int16_t num, char* str)
{
	bool digit = false;
	int i = 0;

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
	} else if (num < 0) {
		str[0] = '-';
		num *= -1;
		i = 1;
	}

	for (int j = 0; j < 5; j++) {
		if (num / __pow(10, (4 - j)) == 0) {
			if (digit == true) {
				str[i] = '0';
				i++;
			}
		} else {
			str[i] = (char)(num / __pow(10, (4 - j))) + '0';
			i++;
			digit = true;
		}

		num -= (num / __pow(10, (4 - j))) * __pow(10, (4 - j));
	}

	str[i] = '\0';
}

void __ToStr_u16(uint16_t num, char* str)
{
	bool digit = false;
	int i = 0;

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
	}

	for (int j = 0; j < 5; j++) {
		if (num / __pow(10, (4 - j)) == 0) {
			if (digit == true) {
				str[i] = '0';
				i++;
			}
		} else {
			str[i] = (char)(num / __pow(10, (4 - j))) + '0';
			i++;
			digit = true;
		}

		num -= (num / __pow(10, (4 - j))) * __pow(10, (4 - j));
	}

	str[i] = '\0';
}

void __ToStr_32(int32_t num, char* str)
{
	bool digit = false;
	int i = 0;

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
	} else if (num < 0) {
		str[0] = '-';
		num *= -1;
		i = 1;
	}

	for (int j = 0; j < 10; j++) {
		if (num / __pow(10, (9 - j)) == 0) {
			if (digit == true) {
				str[i] = '0';
				i++;
			}
		} else {
			str[i] = (char)(num / __pow(10, (9 - j))) + '0';
			i++;
			digit = true;
		}

		num -= (num / __pow(10, (9 - j))) * __pow(10, (9 - j));
	}

	str[i] = '\0';
}

void __ToStr_u32(uint32_t num, char* str)
{
	bool digit = false;
	int i = 0;

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
	}

	for (int j = 0; j < 10; j++) {
		if (num / __pow(10, (9 - j)) == 0) {
			if (digit == true) {
				str[i] = '0';
				i++;
			}
		} else {
			str[i] = (char)(num / __pow(10, (9 - j))) + '0';
			i++;
			digit = true;
		}

		num -= (num / __pow(10, (9 - j))) * __pow(10, (9 - j));
	}

	str[i] = '\0';
}

void NumToStr(int8_t num, char* str)
{
	__ToStr_8(num, str);
}

void NumToStr(uint8_t num, char* str)
{
	__ToStr_u8(num, str);
}

void NumToStr(int16_t num, char* str)
{
	__ToStr_16(num, str);
}

void NumToStr(uint16_t num, char* str)
{
	__ToStr_u16(num, str);
}

void NumToStr(int32_t num, char* str)
{
	__ToStr_32(num, str);
}
void NumToStr(uint32_t num, char* str)
{
	__ToStr_u32(num, str);
}
