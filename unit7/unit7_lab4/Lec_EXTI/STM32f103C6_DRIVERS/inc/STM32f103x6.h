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

#define Cortex_M3_Internal_Peripherals_Base	0xE0000000UL
#define NVIC_BASE							0xE000E100UL


//----------------------------------------------
// Section: Base addresses for Cortex-M3 Peripherals
//----------------------------------------------

/* NVIC: */
#define NVIC_ISER0			(*(volatile uint32_t*)(NVIC_BASE))
#define NVIC_ISER1			(*(volatile uint32_t*)(NVIC_BASE + 0x004))
#define NVIC_ISER2			(*(volatile uint32_t*)(NVIC_BASE + 0x008))
#define NVIC_ICER0			(*(volatile uint32_t*)(NVIC_BASE + 0x080))
#define NVIC_ICER1			(*(volatile uint32_t*)(NVIC_BASE + 0x084))
#define NVIC_ICER2			(*(volatile uint32_t*)(NVIC_BASE + 0x088))
#define NVIC_ISPR0			(*(volatile uint32_t*)(NVIC_BASE + 0x100))
#define NVIC_ISPR1			(*(volatile uint32_t*)(NVIC_BASE + 0x104))
#define NVIC_ISPR2			(*(volatile uint32_t*)(NVIC_BASE + 0x108))
#define NVIC_ICPR0			(*(volatile uint32_t*)(NVIC_BASE + 0x180))
#define NVIC_ICPR1			(*(volatile uint32_t*)(NVIC_BASE + 0x184))
#define NVIC_ICPR2			(*(volatile uint32_t*)(NVIC_BASE + 0x188))
#define NVIC_IABR0			(*(volatile uint32_t*)(NVIC_BASE + 0x200))
#define NVIC_IABR1			(*(volatile uint32_t*)(NVIC_BASE + 0x204))
#define NVIC_IABR2			(*(volatile uint32_t*)(NVIC_BASE + 0x208))
#define NVIC_IPR0			(*(volatile uint32_t*)(NVIC_BASE + 0x300))
#define NVIC_IPR2			(*(volatile uint32_t*)(NVIC_BASE + 0x320))
#define NVIC_STIR			(*(volatile uint32_t*)(NVIC_BASE + 0xE00))


//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

//----------------------------------------------
// Section: Interrupt Vector Table
//----------------------------------------------
#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40


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
	volatile uint32_t EXTICR[4]	   ;
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
#define  EXTI				((EXIT_TypeDef *)EXIT_BASE)

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
//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: NVIC IRQ enable/disable Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC_IRQ6_EXTI0_Enable()		(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Enable()		(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable()		(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable()		(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable()		(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Enable()		(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Enable()	(NVIC_ISER1 |= (1<<8))


#define NVIC_IRQ6_EXTI0_Disable()		(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Disable()		(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Disable()		(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Disable()		(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Disable()		(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable()	(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable()	(NVIC_ICER1 |= (1<<8))

#endif /* INC_STM32F103X6_H_ */
