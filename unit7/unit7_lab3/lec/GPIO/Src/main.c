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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "STM32f103C6_GPIO_DRIVER.h"
#include "STM32f103x6.h"

typedef volatile unsigned int vuint32_t;


//port A
#define GPIOA_CRH *(vuint32_t*)(GPIOA_BASE+0x04)
#define GPIOA_CRL *(vuint32_t*)(GPIOA_BASE+0x00)
#define GPIOA_ODR *(vuint32_t*)(GPIOA_BASE+0x0c)
#define GPIOA_IDR *(vuint32_t*)(GPIOA_BASE+0x08)
//port B
#define GPIOB_CRH *(vuint32_t*)(GPIOB_BASE+0x04)
#define GPIOB_CRL *(vuint32_t*)(GPIOB_BASE+0x00)
#define GPIOB_ODR *(vuint32_t*)(GPIOB_BASE+0x0c)
#define GPIOB_IDR *(vuint32_t*)(GPIOB_BASE+0x08)
//void init_GPIO()
// {
//
//
//
// GPIOA_CRL=0;
// GPIOA_CRH=0;
// GPIOA_ODR=0;
//
//
//	//A1 input floating 01
// GPIOA_CRL&=~(0b11<<4);
//	GPIOA_CRL|=(0b01<<6);
// //B1 output push pull
//		GPIOB_CRL|=(0b01<<4);
//		GPIOB_CRL&=~(0b11<<6);
//
//	// A13 input floating
//	 GPIOA_CRH&=~(0b11<<20);
//		GPIOA_CRH|=(0b01<<22);
//
//
//	//b13 output push pull
//		GPIOB_CRH|=(0b01<<20);
//		GPIOB_CRH&=~(0b11<<22);
//
// }
void init_GPIO()
{
	GPIO_PinConfig_t PinConfig;

	//A1 input floating 01
MCAL_GPIO_Write_Port(GPIOA, 0x0000);
MCAL_GPIO_Write_Port(GPIOB, 0x0000);

	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	//B1 output push pull
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB,&PinConfig);

	// A13 input floating
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA,&PinConfig);


	//b13 output push pull
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_13;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB,&PinConfig);

}
void init_clock()
{
	//GPIO enable clock
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();
}
void dely(int x)
{
	unsigned int i,j;
	for (i=0;i<x;i++)
		for (j=0;j<255;j++);
}
int main(void)
{
	init_clock();
	init_GPIO();
	volatile char flag =1;
	MCAL_GPIO_Write_PIN(GPIOB,GPIO_PIN_13, 0);
	MCAL_GPIO_Write_PIN(GPIOB,GPIO_PIN_1, 0);

	while (1){

		if ((MCAL_GPIO_Read_PIN(GPIOA, GPIO_PIN_1)))
		{
			if (flag)
				MCAL_GPIO_Toggle_PIN(GPIOB,GPIO_PIN_1);
			flag=0;

		}
		else flag=1;
		if ((MCAL_GPIO_Read_PIN(GPIOA, GPIO_PIN_13)))
		{
			MCAL_GPIO_Toggle_PIN(GPIOB,GPIO_PIN_13);


		}

		dely(10);

	}
}

