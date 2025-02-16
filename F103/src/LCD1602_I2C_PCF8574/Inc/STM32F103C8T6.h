#ifndef _STM32F103C8T6_H__
#define _STM32F103C8T6_H__

#include <stdint.h>
#include <stdbool.h>

/*******************************************************************************************************************
 * Peripheral Hardware Access Layer for RCC                                                                        *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t CR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t BDCR;
    uint32_t CSR;
} RCC_Type;

#define RCC_BASE                    (0x40021000u)
#define RCC                         ((RCC_Type *)RCC_BASE)

#define RCC_APB2ENR_IOPBEN_SHIFT    (3u)
#define RCC_APB2ENR_IOPBEN_MASK     (0x8u)
#define RCC_APB2ENR_IOPBEN(x)       (((x) << RCC_APB2ENR_IOPBEN_SHIFT) & (RCC_APB2ENR_IOPBEN_MASK))

#define RCC_APB2ENR_IOPCEN_SHIFT    (4u)
#define RCC_APB2ENR_IOPCEN_MASK     (0x10u)
#define RCC_APB2ENR_IOPCEN(x)       (((x) << RCC_APB2ENR_IOPCEN_SHIFT) & (RCC_APB2ENR_IOPCEN_MASK))

#define RCC_APB1ENR_TIM2EN_SHIFT    (0u)
#define RCC_APB1ENR_TIM2EN_MASK     (0x1u)
#define RCC_APB1ENR_TIM2EN(x)       (((x) << RCC_APB1ENR_TIM2EN_SHIFT) & (RCC_APB1ENR_TIM2EN_MASK))

#define RCC_APB1ENR_I2C1EN_SHIFT    (21u)
#define RCC_APB1ENR_I2C1EN_MASK     (0x200000u)
#define RCC_APB1ENR_I2C1EN(x)       (((x) << RCC_APB1ENR_I2C1EN_SHIFT) & (RCC_APB1ENR_I2C1EN_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Access Layer for GPIO                                                                       *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} GPIO_Type;

#define GPIOB_BASE                  (0x40010C00u)
#define GPIOB                       ((GPIO_Type *)GPIOB_BASE)

#define GPIOC_BASE                  (0x40011000u)
#define GPIOC                       ((GPIO_Type *)GPIOC_BASE)

#define GPIO_CRL_MODE6_SHIFT        (24u)
#define GPIO_CRL_MODE6_MASK         (0x3000000u)
#define GPIO_CRL_MODE6(x)           (((x) << GPIO_CRL_MODE6_SHIFT) & (GPIO_CRL_MODE6_MASK))

#define GPIO_CRL_CNF6_SHIFT         (26u)
#define GPIO_CRL_CNF6_MASK          (0xC000000u)
#define GPIO_CRL_CNF6(x)            (((x) << GPIO_CRL_CNF6_SHIFT) & (GPIO_CRL_CNF6_MASK))

#define GPIO_CRL_MODE7_SHIFT        (28u)
#define GPIO_CRL_MODE7_MASK         (0x30000000u)
#define GPIO_CRL_MODE7(x)           (((x) << GPIO_CRL_MODE7_SHIFT) & (GPIO_CRL_MODE7_MASK))

#define GPIO_CRL_CNF7_SHIFT         (30u)
#define GPIO_CRL_CNF7_MASK          (0xC0000000u)
#define GPIO_CRL_CNF7(x)            (((x) << GPIO_CRL_CNF7_SHIFT) & (GPIO_CRL_CNF7_MASK))

#define GPIO_CRH_MODE13_SHIFT       (20u)
#define GPIO_CRH_MODE13_MASK        (0x300000u)
#define GPIO_CRH_MODE13(x)          (((x) << GPIO_CRH_MODE13_SHIFT) & (GPIO_CRH_MODE13_MASK))

#define GPIO_CRH_CNF13_SHIFT        (22u)
#define GPIO_CRH_CNF13_MASK         (0xC00000u)
#define GPIO_CRH_CNF13(x)           (((x) << GPIO_CRH_CNF13_SHIFT) & (GPIO_CRH_CNF13_MASK))

#define GPIO_BSRR_BS13_SHIFT        (13u)
#define GPIO_BSRR_BS13_MASK         (0x2000u)
#define GPIO_BSRR_BS13(x)           (((x) << GPIO_BSRR_BS13_SHIFT) & (GPIO_BSRR_BS13_MASK))

#define GPIO_BSRR_BR13_SHIFT        (29u)
#define GPIO_BSRR_BR13_MASK         (0x20000000u)
#define GPIO_BSRR_BR13(x)           (((x) << GPIO_BSRR_BR13_SHIFT) & (GPIO_BSRR_BR13_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Access Layer for Timer                                                                      *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t SMCR;
    uint32_t DIER;
    uint32_t SR;
    uint32_t EGR;
    uint32_t CCMR1;
    uint32_t CCMR2;
    uint32_t CCER;
    uint32_t CNT;
    uint32_t PSC;
    uint32_t ARR;
    uint32_t RESERVED_1;
    uint32_t CCR1;
    uint32_t CCR2;
    uint32_t CCR3;
    uint32_t CCR4;
    uint32_t RESERVED_2;
    uint32_t DCR;
    uint32_t DMAR;
} TIM_Type;

#define TIM2_BASE                   (0x40000000u)
#define TIM2                        ((TIM_Type *)TIM2_BASE)

#define TIM_CR1_CEN_SHIFT           (0u)
#define TIM_CR1_CEN_MASK            (0x1u)
#define TIM_CR1_CEN(x)              (((x) << TIM_CR1_CEN_SHIFT) & (TIM_CR1_CEN_MASK))

#define TIM_PSC_PSC_SHIFT           (0u)
#define TIM_PSC_PSC_MASK            (0xFFFFu)
#define TIM_PSC_PSC(x)               (((x) << TIM_PSC_PSC_SHIFT) & (TIM_PSC_PSC_MASK))

#define TIM_ARR_ARR_SHIFT           (0u)
#define TIM_ARR_ARR_MASK            (0xFFFFu)
#define TIM_ARR_ARR(x)               (((x) << TIM_ARR_ARR_SHIFT) & (TIM_ARR_ARR_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Access Layer for I2C                                                                        *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t OAR1;
    uint32_t OAR2;
    uint32_t DR;
    uint32_t SR1;
    uint32_t SR2;
    uint32_t CCR;
    uint32_t TRISE;
} I2C_Type;

#define I2C1_BASE                   (0x40005400u)
#define I2C1                        ((I2C_Type *)I2C1_BASE)

#define I2C_CR1_PE_SHIFT            (0u)
#define I2C_CR1_PE_MASK             (0x1u)
#define I2C_CR1_PE(x)               (((x) << I2C_CR1_PE_SHIFT) & (I2C_CR1_PE_MASK))

#define I2C_CR1_NOSTRETCH_SHIFT     (7u)
#define I2C_CR1_NOSTRETCH_MASK      (0x80u)
#define I2C_CR1_NOSTRETCH(x)        (((x) << I2C_CR1_NOSTRETCH_SHIFT) & (I2C_CR1_NOSTRETCH_MASK))

#define I2C_CR1_START_SHIFT         (8u)
#define I2C_CR1_START_MASK          (0x100u)
#define I2C_CR1_START(x)            (((x) << I2C_CR1_START_SHIFT) & (I2C_CR1_START_MASK))

#define I2C_CR1_STOP_SHIFT          (9u)
#define I2C_CR1_STOP_MASK           (0x200u)
#define I2C_CR1_STOP(x)             (((x) << I2C_CR1_STOP_SHIFT) & (I2C_CR1_STOP_MASK))

#define I2C_CR1_ACK_SHIFT           (10u)
#define I2C_CR1_ACK_MASK            (0x400u)
#define I2C_CR1_ACK(x)              (((x) << I2C_CR1_ACK_SHIFT) & (I2C_CR1_ACK_MASK))

#define I2C_CR2_FREQ_SHIFT          (0u)
#define I2C_CR2_FREQ_MASK           (0x3Fu)
#define I2C_CR2_FREQ(x)             (((x) << I2C_CR2_FREQ_SHIFT) & (I2C_CR2_FREQ_MASK))

#define I2C_DR_DR_SHIFT             (0u)
#define I2C_DR_DR_MASK              (0xFFu)
#define I2C_DR_DR(x)                (((x) << I2C_DR_DR_SHIFT) & (I2C_DR_DR_MASK))

#define I2C_SR1_SB_SHIFT            (0u)
#define I2C_SR1_SB_MASK             (0x1u)
#define I2C_SR1_SB(x)               (((x) << I2C_SR1_SB_SHIFT) & (I2C_SR1_SB_MASK))

#define I2C_SR1_ADDR_SHIFT          (1u)
#define I2C_SR1_ADDR_MASK           (0x2u)
#define I2C_SR1_ADDR(x)             (((x) << I2C_SR1_ADDR_SHIFT) & (I2C_SR1_ADDR_MASK))

#define I2C_SR1_BTF_SHIFT           (2u)
#define I2C_SR1_BTF_MASK            (0x4u)
#define I2C_SR1_BTF(x)              (((x) << I2C_SR1_BTF_SHIFT) & (I2C_SR1_BTF_MASK))

#define I2C_SR1_TXE_SHIFT           (7u)
#define I2C_SR1_TXE_MASK            (0x80u)
#define I2C_SR1_TXE(x)              (((x) << I2C_SR1_TXE_SHIFT) & (I2C_SR1_TXE_MASK))

#define I2C_SR1_AF_SHIFT            (10u)
#define I2C_SR1_AF_MASK             (0x400u)
#define I2C_SR1_AF(x)               (((x) << I2C_SR1_AF_SHIFT) & (I2C_SR1_AF_MASK))

#define I2C_CCR_CCR_SHIFT           (0u)
#define I2C_CCR_CCR_MASK            (0xFFFu)
#define I2C_CCR_CCR(x)              (((x) << I2C_CCR_CCR_SHIFT) & (I2C_CCR_CCR_MASK))

#define I2C_CCR_FS_SHIFT            (15u)
#define I2C_CCR_FS_MASK             (0x8000u)
#define I2C_CCR_FS(x)               (((x) << I2C_CCR_FS_SHIFT) & (I2C_CCR_FS_MASK))

#define I2C_TRISE_TRISE_SHIFT       (0u)
#define I2C_TRISE_TRISE_MASK        (0x3Fu)
#define I2C_TRISE_TRISE(x)          (((x) << I2C_TRISE_TRISE_SHIFT) & (I2C_TRISE_TRISE_MASK))

#endif /* _STM32F103C8T6_H__ */
