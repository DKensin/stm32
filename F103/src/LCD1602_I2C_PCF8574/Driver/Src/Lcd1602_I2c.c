/*
 * Lcd1602_I2c.c
 *
 *  Created on: Feb 17, 2025
 *      Author: ADMIN
 */

#include "STM32F103C8T6.h"
#include "I2c.h"

static uint8_t slave_address = 0;

extern void delay_us(uint32_t us);
extern void delay_ms(uint32_t ms);


void lcd_update_address(uint8_t address)
{
    slave_address = address;
}

void lcd_send_cmd (uint8_t cmd)
{
    uint8_t data_u, data_l;

    uint8_t buff[4];

    data_u = (cmd&0xf0);
    data_l = ((cmd<<4)&0xf0);

    buff[0] = data_u | 0x0C;  //en=1, rs=0
    buff[1] = data_u | 0x08;  //en=0, rs=0
    buff[2] = data_l | 0x0C;  //en=1, rs=0
    buff[3] = data_l | 0x08;  //en=0, rs=0

    I2C_MasterTransmit(I2C1, buff, 4, slave_address);
}

void lcd_send_data (uint8_t data)
{
    uint8_t data_u, data_l;
    uint8_t buff[4];

    data_u = (data&0xf0);
    data_l = ((data<<4)&0xf0);

    buff[0] = data_u | 0x0D;  //en=1, rs=0
    buff[1] = data_u | 0x09;  //en=0, rs=0
    buff[2] = data_l | 0x0D;  //en=1, rs=0
    buff[3] = data_l | 0x09;  //en=0, rs=0

    I2C_MasterTransmit(I2C1, buff, 4, slave_address);
}

void lcd_clear (void)
{
    lcd_send_cmd (0x01);
    delay_ms(5);
}

void lcd_put_cur(int row, int col)
{
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }

    lcd_send_cmd (col);
}


void lcd_init (void)
{
    // 4 bit initialisation
    delay_ms(50);  // wait for >40ms
    lcd_send_cmd (0x30);
    delay_ms(5);  // wait for >4.1ms
    lcd_send_cmd (0x30);
    delay_us(200);  // wait for >100us
    lcd_send_cmd (0x30);
    delay_ms(10);
    lcd_send_cmd (0x20);  // 4bit mode
    delay_ms(10);

  // dislay initialisation
    lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 uint8_tacters)
    delay_ms(1);
    lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
    delay_ms(1);
    lcd_send_cmd (0x01);  // clear display
    delay_ms(1);
    delay_ms(1);
    lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
    delay_ms(1);
    lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
    delay_ms(1);
}

void lcd_send_string (uint8_t *str)
{
    while (*str) lcd_send_data (*str++);
}
