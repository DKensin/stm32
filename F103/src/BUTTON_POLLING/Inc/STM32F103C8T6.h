#ifndef _STM32F103C8T6_H__
#define _STM32F103C8T6_H__

#include <stdint.h>

/*******************************************************************************************************************
 * Peripheral Hardware Abstraction Layer for RCC                                                                   *
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

#define RCC_APB2ENR_IOPAEN_SHIFT    (2u)
#define RCC_APB2ENR_IOPAEN_MASK     (0x4u)
#define RCC_APB2ENR_IOPAEN(x)       (((x) << RCC_APB2ENR_IOPAEN_SHIFT) & (RCC_APB2ENR_IOPAEN_MASK))

#define RCC_APB2ENR_IOPCEN_SHIFT    (4u)
#define RCC_APB2ENR_IOPCEN_MASK     (0x10u)
#define RCC_APB2ENR_IOPCEN(x)       (((x) << RCC_APB2ENR_IOPCEN_SHIFT) & (RCC_APB2ENR_IOPCEN_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Abstraction Layer for GPIO                                                                  *
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


#define GPIOA_BASE                  (0x40010800u)
#define GPIOA                       ((GPIO_Type *)GPIOA_BASE)
#define GPIOC_BASE                  (0x40011000u)
#define GPIOC                       ((GPIO_Type *)GPIOC_BASE)

#define GPIO_CRL_MODE0_SHIFT        (0u)
#define GPIO_CRL_MODE0_MASK         (0x3u)
#define GPIO_CRL_MODE0(x)           (((x) << GPIO_CRL_MODE0_SHIFT) & (GPIO_CRL_MODE0_MASK))

#define GPIO_CRL_CNF0_SHIFT         (2u)
#define GPIO_CRL_CNF0_MASK          (0xCu)
#define GPIO_CRL_CNF0(x)            (((x) << GPIO_CRL_CNF0_SHIFT) & (GPIO_CRL_CNF0_MASK))

#define GPIO_CRH_MODE13_SHIFT       (20u)
#define GPIO_CRH_MODE13_MASK        (0x300000u)
#define GPIO_CRH_MODE13(x)          (((x) << GPIO_CRH_MODE13_SHIFT) & (GPIO_CRH_MODE13_MASK))

#define GPIO_CRH_CNF13_SHIFT        (22u)
#define GPIO_CRH_CNF13_MASK         (0xC00000u)
#define GPIO_CRH_CNF13(x)           (((x) << GPIO_CRH_CNF13_SHIFT) & (GPIO_CRH_CNF13_MASK))

#define GPIO_IDR_IDR0_MASK          (0x1u)

#define GPIO_ODR_ODR13_SHIFT        (13u)
#define GPIO_ODR_ODR13_MASK         (0x2000u)
#define GPIO_ODR_ODR13(x)           (((x) << GPIO_ODR_ODR13_SHIFT) & (GPIO_ODR_ODR13_MASK))

#define GPIO_BSRR_BS0_SHIFT         (0u)
#define GPIO_BSRR_BS0_MASK          (0x1u)
#define GPIO_BSRR_BS0(x)            (((x) << GPIO_BSRR_BS0_SHIFT) & (GPIO_BSRR_BS0_MASK))

#define GPIO_BSRR_BS13_SHIFT        (13u)
#define GPIO_BSRR_BS13_MASK         (0x2000u)
#define GPIO_BSRR_BS13(x)           (((x) << GPIO_BSRR_BS13_SHIFT) & (GPIO_BSRR_BS13_MASK))

#define GPIO_BSRR_BR13_SHIFT        (29u)
#define GPIO_BSRR_BR13_MASK         (0x20000000u)
#define GPIO_BSRR_BR13(x)           (((x) << GPIO_BSRR_BR13_SHIFT) & (GPIO_BSRR_BR13_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Abstraction Layer for EXTI                                                                  *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t IMR;
    uint32_t EMR;
    uint32_t RTSR;
    uint32_t FTSR;
    uint32_t SWIER;
    uint32_t PR;
} EXTI_Type;

#define EXTI_BASE                   (0x40010400u)
#define EXTI                        ((EXTI_Type *)EXTI_BASE)

#define EXTI_FTSR_TR0_SHIFT         (0u)
#define EXTI_FTSR_TR0_MASK          (0x1u)
#define EXTI_FTSR_TR0(x)            (((x) << EXTI_FTSR_TR0_SHIFT) & (EXTI_FTSR_TR0_MASK))

#define EXTI_IMR_MR0_SHIFT          (0u)
#define EXTI_IMR_MR0_MASK           (0x1u)
#define EXTI_IMR_MR0(x)             (((x) << EXTI_IMR_MR0_SHIFT) & (EXTI_IMR_MR0_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Abstraction Layer for NVIC                                                                  *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t ISER[3];
    uint32_t RESERVED_0[29];
    uint32_t ICER[3];
    uint32_t RESERVED_1[29];
    uint32_t ISPR[3];
    uint32_t RESERVED_2[29];
    uint32_t ICPR[3];
    uint32_t RESERVED_3[29];
    uint32_t IABR[3];
    uint32_t RESERVED_4[29];
    uint32_t IPR[9];
    uint32_t RESERVED_5[695];
    uint32_t STIR;
} NVIC_Type;

#define NVIC_BASE                   (0xE000EF00u)
#define NVIC                        ((NVIC_Type *)NVIC_BASE)

#endif /* _STM32F103C8T6_H__ */
