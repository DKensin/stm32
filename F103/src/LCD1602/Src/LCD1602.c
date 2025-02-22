/*
 * LCD1602.c
 *
 *  Created on: 21-Jan-2020
 *      Author: Controllerstech
 */

#include "STM32F103C8T6.h"

/*********** Define the LCD PINS below ****************/
#define RS_PIN          (1u)        /* PA1 */
#define RW_PIN          (2u)        /* PA2 */
#define EN_PIN          (3u)        /* PA3 */
#define DB4_PIN         (4u)        /* PA4 */
#define DB5_PIN         (5u)        /* PA5 */
#define DB6_PIN         (6u)        /* PA6 */
#define DB7_PIN         (7u)        /* PA7 */

extern void delay_us(uint32_t us);
extern void delay_ms(uint32_t ms);

/****************************************************************************************************************************************************************/

void send_to_lcd(uint8_t data, uint32_t rs)
{
    GPIOA->ODR &= ~(1 << RS_PIN);
    // rs = 1 for data, rs=0 for command
    GPIOA->ODR |= (rs << RS_PIN);

    /* write the data to the respective pin */
    GPIOA->ODR &= ~((1 << DB7_PIN) | (1 << DB6_PIN) | (1 << DB5_PIN) | (1 << DB4_PIN));
    GPIOA->ODR |= ((((data>>3)&0x01)) << DB7_PIN);
    GPIOA->ODR |= ((((data>>2)&0x01)) << DB6_PIN);
    GPIOA->ODR |= ((((data>>1)&0x01)) << DB5_PIN);
    GPIOA->ODR |= ((((data>>0)&0x01)) << DB4_PIN);

    /* Toggle EN PIN to send the data */
    GPIOA->ODR |= (1 << EN_PIN);
    /* Wait at least 450ns */
    delay_us(1);
    GPIOA->ODR &= ~(1 << EN_PIN);
    delay_us(1);
}

void lcd_send_cmd(uint8_t cmd)
{
    uint8_t datatosend;

    /* send upper nibble first */
    datatosend = ((cmd >> 4u) & 0x0Fu);
    /* RS must be 0 while sending command*/
    send_to_lcd(datatosend, 0);

    /* send Lower Nibble */
    datatosend = ((cmd) & 0x0Fu);
    send_to_lcd(datatosend, 0);
}

void lcd_send_data(uint8_t data)
{
    uint8_t datatosend;

    /* send higher nibble */
    datatosend = ((data >> 4u) & 0x0Fu);
    send_to_lcd(datatosend, 1);  // rs =1 for sending data

    /* send Lower nibble */
    datatosend = ((data) & 0x0Fu);
    send_to_lcd(datatosend, 1);
}

void lcd_clear(void)
{
    lcd_send_cmd(0x01);
    delay_ms(2);
}

void lcd_put_cur(uint32_t row, uint32_t col)
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
    lcd_send_cmd(0x30);
    delay_ms(5);  // wait for >4.1ms
    lcd_send_cmd(0x30);
    delay_ms(1);  // wait for >100us
    lcd_send_cmd(0x30);

    lcd_send_cmd(0x20);  // 4bit mode

  // dislay initialisation
    lcd_send_cmd(0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
    lcd_send_cmd(0x0F); //Display on/off control --> D=0,C=0, B=0  ---> display off
    lcd_send_cmd(0x01);  // clear display
    lcd_send_cmd(0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
}

void lcd_send_string(uint8_t *str)
{
    while (*str) lcd_send_data (*str++);
}
