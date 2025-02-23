/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "STM32F103C8T6.h"
#include "I2c.h"
#include "LCD1602.h"

void gpio_init(void);
void timer2_init(void);
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);

int main(void)
{
    uint8_t slave_address = 0;
    uint8_t str[10] = "HELLO";

    gpio_init();
    timer2_init();

    I2C_Init();
    /* Scan I2C bus to get slave address */
    slave_address = I2C_MasterScanBus();

    /* Update scan address to LCD lib */
    lcd_update_address(slave_address);

    lcd_init();

    lcd_put_cur(0, 0);
    lcd_send_string(str);

    lcd_put_cur(1, 0);
    lcd_send_string(str);

    /* Loop forever */
    while (1)
    {
    }
}

void gpio_init(void)
{
    /* Enable clock for port B */
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN(1u);

    GPIOB->CRH &= ~(GPIO_CRL_MODE6_MASK | GPIO_CRL_CNF6_MASK);
    GPIOB->CRH &= ~(GPIO_CRL_MODE7_MASK | GPIO_CRL_CNF7_MASK);
    /* Set PB6, PB7 to  ALT output and open-drain mode, 50MHz */
    GPIOB->CRL |= GPIO_CRL_MODE6(3) | GPIO_CRL_CNF6(3);     /* I2C1_SCL */
    GPIOB->CRL |= GPIO_CRL_MODE7(3) | GPIO_CRL_CNF7(3);     /* I2C1_SDA */
}

void timer2_init(void)
{
    /* Enable clock for TIM2 */
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN(1u);

    /**
     * Setup clock frequency for TIM2. When POR (power of reset):
     * RCC_CR:      Reset value: 0x0000 XX83:   HSION and HSIRDY -> clock source is HSI (8MHz)
     * RCC_CFRG:    Reset value: 0x0
     *      + PLLSRC = 0 -> HSI oscillator clock / 2 selected as PLL input clock (4MHz)
     *      + PLLMUL = 0 -> PLL input clock * 2 (8MHz)
     *      + SW = 0 ->  HSI selected as system clock (8MHz)
     *      + HPRE = 0 -> SYSCLK not divided
     *      + PPRE1 = 0 -> HCLK not divided
     * Summary: PCLK1 = 8MHz
     */

    /* Set PSR = 7 -> Fclock = CK_PSC / (PSC[15:0] + 1) = 8 / (7 + 1) = 1MHz */
    TIM2->PSC = TIM_PSC_PSC(7u);
    TIM2->ARR = TIM_ARR_ARR(0xFFFFu);

    /* Enable counter */
    TIM2->CR1 |= TIM_CR1_CEN(1u);
}

void delay_us(uint32_t us)
{
    TIM2->CNT = 0;
    while ((TIM2->CNT) < us);   /* delay 1 us */
}

void delay_ms(uint32_t ms)
{
    TIM2->CNT = 0;
    while ((TIM2->CNT) < (1000*ms));
}
