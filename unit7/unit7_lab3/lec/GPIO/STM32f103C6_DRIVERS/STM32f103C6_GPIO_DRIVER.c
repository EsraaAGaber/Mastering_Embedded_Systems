#include "STM32f103C6_GPIO_DRIVER.h"
// API's to initialize and deinitialze

/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-initialize GPIO port
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-PinConfig struct contain config. of the port
 * @retval 		-none
 * Note			-none
 */
uint8_t Get_CRLH_Position(uint16_t Pin_Number)
{
	// we will switch on the number of pin


	    if (Pin_Number == GPIO_PIN_0) return 0;
	    else if (Pin_Number == GPIO_PIN_1) return 4;
	    else if (Pin_Number == GPIO_PIN_2) return 8;
	    else if (Pin_Number == GPIO_PIN_3) return 12;
	    else if (Pin_Number == GPIO_PIN_4) return 16;
	    else if (Pin_Number == GPIO_PIN_5) return 20;
	    else if (Pin_Number == GPIO_PIN_6) return 24;
	    else if (Pin_Number == GPIO_PIN_7) return 28;
	    else if (Pin_Number == GPIO_PIN_8) return 0;
	    else if (Pin_Number == GPIO_PIN_9) return 4;
	    else if (Pin_Number == GPIO_PIN_10) return 8;
	    else if (Pin_Number == GPIO_PIN_11) return 12;
	    else if (Pin_Number == GPIO_PIN_12) return 16;
	    else if (Pin_Number == GPIO_PIN_13) return 20;
	    else if (Pin_Number == GPIO_PIN_14) return 24;
	    else if (Pin_Number == GPIO_PIN_15) return 28;

	    // Optionally, handle invalid Pin_Number
	    return -1; // or another error handling mechanism

}

void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx , GPIO_PinConfig_t *PinConfig)
{
	// Port configuration register low (GPIOx_CRL) configure the pins 0 >>> 7
	// Port configuration register high (GPIOx_CRH) configure the pins 8 >>> 15
	// we will create a pointer to points to the register (CRL or CRH) according to condition that the pin number < 8 or not
	// and create a variable to set the value of the configuration in  o/p mode
	volatile uint32_t *Config_Register = NULL; uint8_t PIN_Confige = 0;
	Config_Register = ((PinConfig->GPIO_PinNumber) < GPIO_PIN_8)?(&GPIOx->CRL):(&GPIOx->CRH);
	// we will use the function Get_CRLH_Position to get the shift of pin ... each pin reserve 4 bit from the register

	// clear CNFx[1:0] MODEx[1:0]
	(*Config_Register) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
	// if the pin in the Output modes
	if((PinConfig->GPIO_MODE == GPIO_MODE_Output_AF_OD) ||(PinConfig->GPIO_MODE == GPIO_MODE_Output_AF_PP)
			||(PinConfig->GPIO_MODE == GPIO_MODE_Output_OD)||(PinConfig->GPIO_MODE == GPIO_MODE_Output_PP))
	{
		// set CNFx[1:0] MODEx[1:0]
		PIN_Confige = (((PinConfig->GPIO_MODE - 4) << 2) | ((PinConfig->GPIO_Output_Speed) & 0x0f));

	}
	// if the pin in i/p modes
	else // mode = 00 in case of i/p modes
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_Input_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			// set CNFx[1:0] MODEx[1:0]
			PIN_Confige = (((PinConfig->GPIO_MODE << 2) | 0x0) & 0x0F);

		}
		else if((PinConfig->GPIO_MODE == GPIO_MODE_AF_Input)) // consider it as input floating
		{
			// set CNFx[1:0] MODEx[1:0]
			PIN_Confige = (((GPIO_MODE_Input_FLO << 2) | 0x0) & 0x0F);
		}
		else // the pin PD or PU modes
		{
			// set CNFx[1:0] MODEx[1:0]
			PIN_Confige = (((GPIO_MODE_Input_PU << 2) | 0x0) & 0x0F);

			if((PinConfig->GPIO_MODE == GPIO_MODE_Input_PU))
			{
				// PxODR = 1 if Pull up mode : Table 20. Port bit configuration table
				GPIOx->ODR |=(PinConfig->GPIO_PinNumber);
			}
			else
			{
				// PxODR = 0 if Pull down mode : Table 20. Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}

		}

	}
	// set the values on the register CRL or CRH
	(*Config_Register)|= (PIN_Confige << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}


/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-deinitialize GPIO pin
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx )
{
	//PB2 peripheral reset register (RCC_APB2RSTR)
	if ( GPIOx==GPIOA)
		RCC->RCC_APB2RSTR |= (1<<2);
	if ( GPIOx==GPIOB)
		RCC->RCC_APB2RSTR |= (1<<3);
	if ( GPIOx==GPIOC)
		RCC->RCC_APB2RSTR |= (1<<4);
	if ( GPIOx==GPIOD)
		RCC->RCC_APB2RSTR |= (1<<5);
	if ( GPIOx==GPIOE)
		RCC->RCC_APB2RSTR |= (1<<6);
}


// API's to Read values
/**================================================================
 * @Fn			-MCAL_GPIO_Read_PIN
 * @brief 		-read pin value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-Pin_Number @ref GPIO_PINS_Define
 * @retval 		-pin value @ref GPIO_PIN_State
 * Note			-none
 */
uint8_t  MCAL_GPIO_Read_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number){
	if ((GPIOx->IDR)&Pin_Number)
	{
		return  GPIO_PIN_SET;
	}
	return GPIO_PIN_RESET;
}

/**================================================================
 * @Fn			-MCAL_GPIO_Read_PORT
 * @brief 		-read all port  value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @retval 		-pin value @ref GPIO_PIN_State
 * Note			-none
 */
uint16_t MCAL_GPIO_Read_PORT(GPIO_TypeDef * GPIOx )
{
	return GPIOx->IDR;
}

// API's to Write
/**================================================================
 * @Fn			-MCAL_GPIO_Write_PIN
 * @brief 		-write  pin value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-Pin_Number @ref GPIO_PINS_Define
 * @param [in]  	-pin value @ref GPIO_PIN_State
 * @retval 		-none
 * Note			-none
 */
void   MCAL_GPIO_Write_PIN(GPIO_TypeDef * GPIOx , uint16_t Pin_Number,uint8_t Value){
	if (Value==GPIO_PIN_SET)
	{
		GPIOx->ODR|=(Pin_Number);
	}
	else GPIOx->ODR&=~(Pin_Number);
}
/**================================================================
 * @Fn			-MCAL_GPIO_Write_Port
 * @brief 		-write port value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in]  	-port value
 * @retval 		-none
 * Note			-none
 */
void   MCAL_GPIO_Write_Port(GPIO_TypeDef * GPIOx , uint16_t Value){

	GPIOx->ODR = Value ;
}

// API's to toggle pin
/**================================================================
 * @Fn			-MCAL_GPIO_Toggle_PIN
 * @brief 		-toggle pin value
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-Pin_Number @ref GPIO_PINS_Define
 * @retval 		-none
 * Note			-none
 */
void   MCAL_GPIO_Toggle_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number){

	GPIOx->ODR^=((uint32_t)Pin_Number);


}

// API's to lock pin
/**================================================================
 * @Fn			-MCAL_GPIO_Lock_PIN
 * @brief 		-lock pin config.
 * @param [in] 	-GPIOx (x=a,b,c,d,e)
 * @param [in] 	-Pin_Number @ref GPIO_PINS_Define
 * @retval 		-check the procces @ref GPIO_RETURN_define
 * Note			-none
 */
uint8_t MCAL_GPIO_Lock_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number){

	/*
	 *
	 *Bit 16 LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	0: Port configuration lock key not active
	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.
	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	These bits are read write but can only be written when the LCKK bit is 0.
	0: Port configuration not locked
	1: Port configuration locked.
	 *
	 */
	volatile uint16_t Temp = (volatile uint16_t)(1<<16);
	//	Write 1
	GPIOx->LCKR|=Pin_Number;
	GPIOx->LCKR|=Temp;
	//	Write 0
	GPIOx->LCKR&=~Temp;
	//	Write 1
	GPIOx->LCKR|=Temp;
	//	Read 0
	Temp = GPIOx->LCKR;
	//	Read 1
	if (GPIOx->LCKR&(1<<16))
		return GPIO_RETURN_OK;
	return GPIO_RETURN_ERROR;



}
