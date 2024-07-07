/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
typedef volatile unsigned int vuint32_t;
#include <stdint.h>
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800
#define RCC_APB2ENR *(vuint32_t*)(RCC_BASE+0x18)
#define GPIOA_CRH *(vuint32_t*)(GPIOA_BASE+0x04)
#define RCC_IOPAEN (1<<2)
#define GPIOA_13 (1UL<<13)
typedef union {
vuint32_t all_port;
struct {
	vuint32_t empty:13;
	vuint32_t p13:1;
}pin;
} R_ODR_T;
volatile R_ODR_T* R_ODR =(volatile R_ODR_T*)(GPIOA_BASE+0x0c);

int main(void)
{

	RCC_APB2ENR |=RCC_IOPAEN;
	GPIOA_CRH %= 0xff0fffff;
	GPIOA_CRH |=0x00200000;
	int i=0;
	while (1)
	{
		R_ODR->pin.p13=1;
		for ( i=0;i<5000;i++);
		R_ODR->pin.p13=0;
		for ( i=0;i<5000;i++);
	}return 0;

}
