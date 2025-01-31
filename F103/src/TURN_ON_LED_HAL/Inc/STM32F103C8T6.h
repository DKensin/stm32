#ifndef _STM32F103C8T6_H__
#define _STM32F103C8T6_H__

#include <stdint.h>

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

#define RCC_APB2ENR_IOPCEN_SHIFT    (4u)
#define RCC_APB2ENR_IOPCEN_MASK     (0x10u)
#define RCC_APB2ENR_IOPCEN(x)       (((x) << RCC_APB2ENR_IOPCEN_SHIFT) & (RCC_APB2ENR_IOPCEN_MASK))

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

#define GPIOC_BASE                  (0x40011000u)
#define GPIOC                       ((GPIO_Type *)GPIOC_BASE)

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


#endif /* _STM32F103C8T6_H__ */
