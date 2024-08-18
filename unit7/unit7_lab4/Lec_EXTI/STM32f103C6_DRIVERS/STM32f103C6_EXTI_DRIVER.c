//-----------------------------
//Includes
//-----------------------------


#include "STM32f103C6_EXTI_DRIVER.h"
/*================================================================
-----Global Variable-------
*///================================================================
void (*G_IRQ_Callback[16])(void);



static void Enable_NVIC(uint8_t IRQn){
	switch(IRQn){
	case EXTI0:
		NVIC_IRQ6_EXTI0_Enable();
		break;
	case EXTI1:
		NVIC_IRQ7_EXTI1_Enable();
		break;
	case EXTI2:
		NVIC_IRQ8_EXTI2_Enable();
		break;
	case EXTI3:
		NVIC_IRQ9_EXTI3_Enable();
		break;
	case EXTI4:
		NVIC_IRQ10_EXTI4_Enable();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Enable();
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Enable();
		break;
	default: /* Do Nothing */ break;
	}
}

static void Disable_NVIC(uint8_t IRQn){
	switch(IRQn){
	case EXTI0:
		NVIC_IRQ6_EXTI0_Disable();
		break;
	case EXTI1:
		NVIC_IRQ7_EXTI1_Disable();
		break;
	case EXTI2:
		NVIC_IRQ8_EXTI2_Disable();
		break;
	case EXTI3:
		NVIC_IRQ9_EXTI3_Disable();
		break;
	case EXTI4:
		NVIC_IRQ10_EXTI4_Disable();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Disable();
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Disable();
		break;
	default: /* Do Nothing */ break;
	}
}


/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Init
 * @brief 		-initialize EXTI GPIO port
 * @param [in] 	-PinConfig struct contain config. of EXTI
 * @retval 		-none
 * Note			-none
 */
void MCAL_EXTI_GPIO_DeInit(void){
	/* Reset EXTI Registers */
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR = 0xFFFFFFFF;
	/* Disable EXTI from NVIC */
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();
}


void EXTI_UPDATE(EXTI_PinConfig_t *EXTI_Config){

	/* Configure GPIO to be AF -> Floating input */
	GPIO_PinConfig_t PinCfg;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	//void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t *PinConfig);
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PinCfg);
	/* Configure AFIO to route between EXTI Line with Specified PORT */

	uint8_t AFIO_EXTICR_index = (EXTI_Config->EXTI_PIN.EXTI_INPUT_LineNumber) / 4;
	uint8_t AFIO_EXTICR_position = ((EXTI_Config->EXTI_PIN.EXTI_INPUT_LineNumber) % 4) * 4;
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_position);
	AFIO->EXTICR[AFIO_EXTICR_index] |= (((AFIO_GPIO_EXTI_Selector(EXTI_Config->EXTI_PIN.GPIO_PORT)) << AFIO_EXTICR_position));


	/* Configure trigger event */
	EXTI->RTSR&=~EXTI_Config->EXTI_PIN.GPIO_PIN;
	EXTI->FTSR&=~EXTI_Config->EXTI_PIN.GPIO_PIN;
	if (EXTI_Config->Trigger_CASE==EXTI_TRIGGER_RISING)
	{
		//raising
		EXTI->RTSR|=EXTI_Config->EXTI_PIN.GPIO_PIN;
	}
	else if (EXTI_Config->Trigger_CASE==EXTI_TRIGGER_FALLING)
	{
		// falling
		EXTI->FTSR|=EXTI_Config->EXTI_PIN.GPIO_PIN;

	}
	else
	{
		// falling and raising
		EXTI->RTSR|=EXTI_Config->EXTI_PIN.GPIO_PIN;
		EXTI->FTSR|=EXTI_Config->EXTI_PIN.GPIO_PIN;

	}


	/* Configure IRQ Handling CallBack */
	G_IRQ_Callback[EXTI_Config->EXTI_PIN.EXTI_INPUT_LineNumber]=EXTI_Config->P_IRQ_CALLBACK_FUN;

	/* Enable/Disable IRQ EXTI & NVIC */
	if (EXTI_Config->IRQ_EN==EXTI_IRQ_ENABLE)
	{
		EXTI->IMR|=(EXTI_Config->EXTI_PIN.GPIO_PIN);
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_INPUT_LineNumber);
	}
	else if (EXTI_Config->IRQ_EN==EXTI_IRQ_DISABLE)
	{
		EXTI->IMR&=~(EXTI_Config->EXTI_PIN.GPIO_PIN);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_INPUT_LineNumber);



	}


}


/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_DeInit
 * @brief 		-reset  EXTI GPIO port
 * @retval 		-none
 * Note			-none
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config){
	EXTI_UPDATE(EXTI_Config);


}

/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Update
 * @brief 		-iupdate EXTI GPIO port
 * @param [in] 	-PinConfig struct contain new config. of EXTI
 * @retval 		-none
 * Note			-none
 */
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config){

	EXTI_UPDATE(EXTI_Config);


}



void EXTI0_IRQHandler(void)
{
    EXTI->PR |= (1 << 0);
    G_IRQ_Callback[0]();
}

void EXTI1_IRQHandler(void)
{
    EXTI->PR |= (1 << 1);
    G_IRQ_Callback[1]();
}

void EXTI2_IRQHandler(void)
{
    EXTI->PR |= (1 << 2);
    G_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void)
{
    EXTI->PR |= (1 << 3);
    G_IRQ_Callback[3]();
}

void EXTI4_IRQHandler(void)
{
    EXTI->PR |= (1 << 4);
    G_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI->PR & (1 << 5))
    {
        EXTI->PR |= (1 << 5);
        G_IRQ_Callback[5]();
    }
    if (EXTI->PR & (1 << 6))
    {
        EXTI->PR |= (1 << 6);
        G_IRQ_Callback[6]();
    }
    if (EXTI->PR & (1 << 7))
    {
        EXTI->PR |= (1 << 7);
        G_IRQ_Callback[7]();
    }
    if (EXTI->PR & (1 << 8))
    {
        EXTI->PR |= (1 << 8);
        G_IRQ_Callback[8]();
    }
    if (EXTI->PR & (1 << 9))
    {
        EXTI->PR |= (1 << 9);
        G_IRQ_Callback[9]();
    }
}

void EXTI10_15_IRQHandler(void)
{
    if (EXTI->PR & (1 << 10))
    {
        EXTI->PR |= (1 << 10);
        G_IRQ_Callback[10]();
    }
    if (EXTI->PR & (1 << 11))
    {
        EXTI->PR |= (1 << 11);
        G_IRQ_Callback[11]();
    }
    if (EXTI->PR & (1 << 12))
    {
        EXTI->PR |= (1 << 12);
        G_IRQ_Callback[12]();
    }
    if (EXTI->PR & (1 << 13))
    {
        EXTI->PR |= (1 << 13);
        G_IRQ_Callback[13]();
    }
    if (EXTI->PR & (1 << 14))
    {
        EXTI->PR |= (1 << 14);
        G_IRQ_Callback[14]();
    }
    if (EXTI->PR & (1 << 15))
    {
        EXTI->PR |= (1 << 15);
        G_IRQ_Callback[15]();
    }
}
