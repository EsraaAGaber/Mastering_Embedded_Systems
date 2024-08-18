


#include "keypad.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns

void Keypad_init(){


	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=R0;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=R1;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=R2;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=R3;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=C0;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=C1;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=C2;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=C3;
	MCAL_GPIO_Init(KEYPAD_PORT,&PinConfig);

	MCAL_GPIO_Write_Port(KEYPAD_PORT, 0xff);
	//	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	//	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	//KEYPAD_PORT = 0xFF;
}

char Keypad_getkey(){
	int i,j;
	for (i = 0; i < 4; i++){
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);

//		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
//		KEYPAD_PORT &= ~(1<<Key_padCol[i]);
		for(j = 0; j < 4; j++){
			if (!MCAL_GPIO_Read_PIN(KEYPAD_PORT, Key_padRow[j]))
			{
				while(!MCAL_GPIO_Read_PIN(KEYPAD_PORT, Key_padRow[j]));
				switch(i){
				case (0):
										if (j == 0) return '7';
										else if (j == 1) return '4';
										else if (j == 2) return '1';
										else if (j == 3) return '?';
				break;
				case (1):
										if (j == 0) return '8';
										else if (j == 1) return '5';
										else if (j == 2) return '2';
										else if (j == 3) return '0';
				break;
				case (2):
										if (j == 0) return '9';
										else if (j == 1) return '6';
										else if (j == 2) return '3';
										else if (j == 3) return '=';
				break;
				case (3):
										if (j == 0) return '/';
										else if (j == 1) return '*';
										else if (j == 2) return '-';
										else if (j == 3) return '+';
				break;
				}
			}
		}
	}
	return 'A';
}
