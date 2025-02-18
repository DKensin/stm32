/*
 * lcd1602.h
 *
 *  Created on: Jan 21, 2020
 *      Author: Controllerstech
 */

#ifndef INC_LCD1602_H_
#define INC_LCD1602_H_

#include <stdint.h>

void lcd_init(void);   // initialize lcd

void lcd_send_cmd(uint8_t cmd);  // send command to the lcd

void lcd_send_data(uint8_t data);  // send data to the lcd

void lcd_send_string(uint8_t *str);  // send string to the lcd

void lcd_put_cur(uint32_t row, uint32_t col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_clear(void);

#endif /* INC_LCD1602_H_ */
