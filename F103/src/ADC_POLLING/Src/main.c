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

/**
 * Program to read LM35 sensor.
 * LM35 data pin was connect to PTA0
 * PTA0 will be configured as ADC pin
 */

#include "STM32F103C8T6.h"

void delay_us(uint32_t us);

int main(void)
{
    uint32_t adc_data = 0;

    /*
     *****************************************************************************************
     * TIM2 setup                                                                            *
     * ***************************************************************************************
     */
    /* Enable clock for TIM2 */
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN(1u);
    /* Set PSR = 7 -> Fclock = CK_PSC / (PSC[15:0] + 1) = 8 / (7 + 1) = 1MHz */
    TIM2->PSC = TIM_PSC_PSC(7u);
    TIM2->ARR = TIM_ARR_ARR(0xFFFFu);

    /* Enable counter */
    TIM2->CR1 |= TIM_CR1_CEN(1u);

    /*
     *****************************************************************************************
     * GPIOA setup                                                                           *
     * ***************************************************************************************
     */
    /* Enable clock for port A */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN(1u);

    /* Configure PTA0 as input pin, analog mode */
    GPIOA->CRL &= ~GPIO_CRL_MODE0_MASK; /* 00: Input mode */
    GPIOA->CRL &= ~GPIO_CRL_CNF0_MASK;  /* 00: Analog mode */

    /*
     *****************************************************************************************
     * ADC1 setup                                                                            *
     * ***************************************************************************************
     */
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN_MASK;

    /* Disable ADC1 to start ADC configuration */
    ADC1->CR2 &= ~ADC_CR2_ADON_MASK;

    /**
     * ADC configuration for ADC1, IN0, only 1 conversion
     * SCANMODE = OFF, continuous conversion
     * Right alignment data
     * Sample time: 1.5 cycles
     */
    ADC1->CR1   &= ~ADC_CR1_SCAN_MASK;      /* Disable SCAN mode */
    ADC1->CR2   |= ADC_CR2_CONT_MASK;       /* Continuous conversion mode */
    ADC1->CR2   &= ~ADC_CR2_ALIGN_MASK;     /* Right alignment */
    ADC1->SMPR2 &= ~ADC_SMPR2_SMP0_MASK;    /* Sample time = 1.5 cycles */
    ADC1->SQR1  &= ~ADC_SQR1_L_MASK;        /* 1 conversion */
    ADC1->SQR3  &= ~ADC_SQR3_SQ1_MASK;      /* First conversion is channel 0 */

    /* When the ADON bit is set for the first time, it wakes up the ADC from Power Down mode. */
    ADC1->CR2 |= ADC_CR2_ADON_MASK;
    /* Wait for ADC stable (1us) */
    delay_us(1);

    /* Conversion starts when ADON bit is set for a second time by software after ADC power-up time (tSTAB). */
    ADC1->CR2 |= ADC_CR2_ADON_MASK;

    /* Loop forever */
    while (1)
    {
        /* Clear EOC flag */
        ADC1->SR &= ~ADC_SR_EOC_MASK;           /* Write 0 to clear */
        ADC1->CR2 |= ADC_CR2_SWSTART_MASK;      /* Start ADC conversion */
        /* Wait until conversion finish */
        while (!((ADC1->SR & ADC_SR_EOC_MASK) >> ADC_SR_EOC_SHIFT));
        /* Read ADC data */
        adc_data = (ADC1->DR) & ADC_DR_DATA_MASK;
    }
}

void delay_us(uint32_t us)
{
    TIM2->CNT = 0;
    while ((TIM2->CNT) < us);   /* delay 1 us */
}

