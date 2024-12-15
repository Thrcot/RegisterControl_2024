/*
 * i2c.h
 *
 *  Created on: Dec 15, 2024
 *      Author: neoki
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

#include "stm32f4xx.h"
#include <system/system.h>
#include <gpio/gpio.h>

typedef enum {
	I2C_1,
	I2C_2,
	I2C_3
} I2C_t;

class I2C {
	public:
		I2C(I2C_t __channel, uint32_t __i2c_freq, PinNum_t __pin1, PinNum_t __pin2);
		bool MasterTransmit(uint8_t __address, uint8_t* __data, uint32_t __size, uint32_t __timeout);

	private:
		I2C_t i2c_ch;
		I2C_TypeDef* channel;
};

#endif /* I2C_I2C_H_ */
