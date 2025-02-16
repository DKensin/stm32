/*
 * I2c.c
 *
 *  Created on: Feb 17, 2025
 *      Author: ADMIN
 */
#include "STM32F103C8T6.h"

#define FREQ_APB1               (8u)

void I2C_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN_MASK;    /* Enable clock for I2C1 */

    I2C1->CR1 |= I2C_CR1_ACK_MASK;              /* Enable ACK */
    I2C1->CR1 &= ~I2C_CR1_NOSTRETCH_MASK;       /* Enable clock stretching */

    I2C1->CR2 &= ~I2C_CR2_FREQ_MASK;
    I2C1->CR2 |= I2C_CR2_FREQ(FREQ_APB1);       /* Write FREQ with value equal APB1 bus frequency */

    I2C1->CCR &= ~I2C_CCR_FS_MASK;              /* Select SM (standard mode) */

    I2C1->CCR &= ~I2C_CCR_CCR_MASK;
    /**
     * Standard mode: Freq = 100kHz
     * Tperiod = 2 * CCR * Tpck1
     * Tpck1 = 8MHz
     */
    I2C1->CCR |= I2C_CCR_CCR(40);

    I2C1->TRISE &= ~I2C_TRISE_TRISE_MASK;
    /**
     * From I2C NXP spec, max Trise in SM is 1000ns
     * FREQ = 8MHz -> T = 125ns
     * TRISE = (1000ns / 125 ns) + 1
     */
    I2C1->TRISE |= I2C_TRISE_TRISE(9);

    I2C1->CR1 |= I2C_CR1_PE_MASK;               /* Enable I2C peripheral */
}

bool I2C_MasterScanAddress(I2C_Type * base, uint8_t address)
{
    bool match = false;
    uint8_t temp;

    /* Generate START condition */
    base->CR1 |= I2C_CR1_START_MASK;
    /* Wait until SB was set */
    while (!(base->SR1 & I2C_SR1_SB_MASK) >> I2C_SR1_SB_SHIFT);

    /* Generate slave address */
    temp = address << 1;
    /* To enter Transmitter mode, a master sends the slave address with LSB reset */
    temp &= ~(1 << 0);
    base->DR = temp & I2C_DR_DR_MASK;
    /* Wait until ADDR or AF was set */
    while (!(base->SR1 & (I2C_SR1_ADDR_MASK | I2C_SR1_AF_MASK)));

    if (base->SR1 & I2C_SR1_ADDR_MASK)
    {
        /* Read SR2 to clear ADDR flag */
        (void)base->SR2;
        match = true;
    }
    else
    {
        /* clear AF flag */
        base->SR1 &= ~I2C_SR1_AF_MASK;
    }

    /* Generate STOP condition */
    base->CR1 |= I2C_CR1_STOP_MASK;

    return match;
}

uint8_t I2C_MasterScanBus(void)
{
    uint8_t index = 0;
    uint8_t address = 0;

    for (index = 0u; index <= 0xFFu; index++)
    {
        if (I2C_MasterScanAddress(I2C1, index))
        {
            address = index;
            break;
        }
    }

    return address;
}

void I2C_MasterTransmit(I2C_Type * base, uint8_t data, uint8_t slave_address)
{
    uint8_t temp;

    /* Generate START condition */
    I2C1->CR1 |= I2C_CR1_START_MASK;
    /* Wait until SB was set */
    while (!(I2C1->SR1 & I2C_SR1_SB_MASK) >> I2C_SR1_SB_SHIFT);

    /* Generate slave address */
    temp = 0;
    temp = slave_address << 1;
    /* To enter Transmitter mode, a master sends the slave address with LSB reset */
    temp &= (1 << 0);
    I2C1->DR = temp & I2C_DR_DR_MASK;
    /* Wait until ADDR was set */
    while (!(I2C1->SR1 & I2C_SR1_ADDR_MASK) >> I2C_SR1_ADDR_SHIFT);
    /* Read SR2 to clear ADDR flag */
    (void)I2C1->SR2;

    /* Wait until DR and shift register is empty */
    while (!(I2C1->SR1 & I2C_SR1_TXE_MASK) >> I2C_SR1_TXE_SHIFT);
    /* Write data */
    I2C1->DR = data & I2C_DR_DR_MASK;
    /* Wait TXE flag was set */
    while (!(I2C1->SR1 & I2C_SR1_TXE_MASK) >> I2C_SR1_TXE_SHIFT);
    /* Wait BTF flag was set */
    while (!(I2C1->SR1 & I2C_SR1_BTF_MASK) >> I2C_SR1_BTF_SHIFT);

    /* Generate STOP condition */
    I2C1->CR1 |= I2C_CR1_STOP_MASK;
}
