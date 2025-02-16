/*
 * I2c.h
 *
 *  Created on: Feb 17, 2025
 *      Author: ADMIN
 */

#ifndef DRIVER_INC_I2C_H_
#define DRIVER_INC_I2C_H_

#include "STM32F103C8T6.h"

void I2C_Init(void);
uint8_t I2C_MasterScanBus(void);
void I2C_MasterTransmit(I2C_Type * base, uint8_t data, uint8_t slave_address);

#endif /* DRIVER_INC_I2C_H_ */
