/*
 * Lcd1602_I2c.h
 *
 *  Created on: Feb 17, 2025
 *      Author: ADMIN
 */

#ifndef INC_LCD1602_I2C_H_
#define INC_LCD1602_I2C_H_

void lcd_update_address(uint8_t address);

/**
 * @brief: Initial the LCD
 */
void lcd_init (void);

/**
 * @brief: Send command to the LCD
 */
void lcd_send_cmd (uint8_t cmd);

/**
 * @brief: Send data to the LCD
 */
void lcd_send_data (uint8_t data);

/**
 * @brief: Send string to the LCD
 */
void lcd_send_string (uint8_t *str);

/**
 * @brief: Put cursor at the entered position row (0 or 1), col (0-15);
 */
void lcd_put_cur(int row, int col);

/**
 * @brief: Clear LCD
 */
void lcd_clear (void);

#endif /* INC_LCD1602_I2C_H_ */
