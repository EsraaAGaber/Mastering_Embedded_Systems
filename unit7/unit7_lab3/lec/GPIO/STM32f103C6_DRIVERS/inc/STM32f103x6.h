/*
 * STM32f103x6.h
 *
 *  Created on: Aug 14, 2024
 *      Author: HP
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdlib.h>
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_MEMORY_BASE					0x08000000UL
#define SRAM_BASE          					0x20000000UL
#define SYSTEM_MEMORY_BASE  				0x1ffff800UL
#define PERIPHERALS_BASE 					0x40000000UL



//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

//Base addresses for APB2 Peripherals
#define GPIOA_BASE							(PERIPHERALS_BASE+0x10800UL)
#define GPIOB_BASE							(PERIPHERALS_BASE+0x10c00UL)
#define GPIOC_BASE							(PERIPHERALS_BASE+0x11000UL)
#define GPIOD_BASE							(PERIPHERALS_BASE+0x11400UL)
#define GPIOE_BASE							(PERIPHERALS_BASE+0x11800UL)
#define EXIT_BASE							(PERIPHERALS_BASE+0x10400UL)
#define AFIO_BASE							(PERIPHERALS_BASE+0x10000UL)

//Base addresses for AHB Peripherals
#define RCC_BASE							(PERIPHERALS_BASE+0x21000UL)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
typedef struct {
	volatile uint32_t CRL ;
	volatile uint32_t CRH ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR;
}GPIO_TypeDef;
//////////////////
//RCC
typedef struct
{
	volatile uint32_t RCC_CR         ;
	volatile uint32_t RCC_CFGR       ;
	volatile uint32_t RCC_CIR        ;
	volatile uint32_t RCC_APB2RSTR   ;
	volatile uint32_t RCC_BAPB1RSTR  ;
	volatile uint32_t RCC_AHBENR     ;
	volatile uint32_t RCC_APB2ENR    ;
	volatile uint32_t RCC_APB1ENR    ;
	volatile uint32_t RCC_BDCR       ;
	volatile uint32_t RCC_CSR        ;

}RCC_TypeDef;
//////////////////
//AFIO
typedef struct
{
	volatile uint32_t EVCR         ;
	volatile uint32_t MAPR         ;
	volatile uint32_t EXTICR1      ;
	volatile uint32_t EXTICR2      ;
	volatile uint32_t EXTICR3      ;
	volatile uint32_t EXTICR4      ;
	volatile uint32_t reserved     ;
	volatile uint32_t MAPR2        ;


}AFIO_TypeDef;

//EXTI
typedef struct
{
	volatile uint32_t IMR         ;
	volatile uint32_t EMR         ;
	volatile uint32_t RTSR      ;
	volatile uint32_t FTSR      ;
	volatile uint32_t SWIER      ;
	volatile uint32_t PR      ;


}EXIT_TypeDef;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
// GPIO Peripheral
#define  GPIOA				((GPIO_TypeDef *)GPIOA_BASE)
#define  GPIOB				((GPIO_TypeDef *)GPIOB_BASE)
#define  GPIOC				((GPIO_TypeDef *)GPIOC_BASE)
#define  GPIOD				((GPIO_TypeDef *)GPIOD_BASE)
#define  GPIOE				((GPIO_TypeDef *)GPIOE_BASE)

// RCC Peripheral
#define  RCC				((RCC_TypeDef *)RCC_BASE)

// EXTI Peripheral
#define  EXTI				((EXTI_TypeDef *)EXTI_BASE)

// AFIO Peripheral
#define  AFIO				((AFIO_TypeDef *)AFIO_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<6))
#define RCC_AFIO_CLK_ENABLE()     (RCC->RCC_APB2ENR |= (1<<0))
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-

#endif /* INC_STM32F103X6_H_ */
