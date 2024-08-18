

#include "lcd.h"
void delay(int x)
{
	unsigned int i,j;
	for (i=0;i<x;i++)
		for (j=0;j<255;j++);
}
void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){
	MCAL_GPIO_Write_PIN(LCD_PORT, EN_SWITCH, GPIO_PIN_SET);
	//	LCD_CTRL |= (1 << EN_SWITCH);
	delay(50);
	MCAL_GPIO_Write_PIN(LCD_PORT, EN_SWITCH, GPIO_PIN_RESET);

	//	LCD_CTRL &= ~(1 << EN_SWITCH);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}
GPIO_PinConfig_t PinConfig;
void LCD_INIT(){
	delay(20);

	//control pin input
	//enable config input floating
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=EN_SWITCH;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);
	//RS config input floating
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=RS_SWITCH;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);
	//RW config input floating
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	PinConfig.GPIO_PinNumber=RW_SWITCH;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	delay(15);

	//DATA pins output config
	//P0 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_0;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P1 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P2 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_2;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P3 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_3;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P4 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_4;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P5 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_5;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P6 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_6;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P7 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_7;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);


	LCD_clear_screen();


#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE
	//LCD_WRITE_COMMAND(0x02);		/* send for 4 bit initialization of LCD  */
	//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
	//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_WRITE_COMMAND(0x01);
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);	
}

void LCD_check_lcd_isbusy(){
	//	DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);

	//P0 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_0;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P1 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P2 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_2;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P3 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_3;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P4 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_4;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P5 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_5;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P6 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_6;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P7 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Input_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_7;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	MCAL_GPIO_Write_PIN(LCD_PORT,RW_SWITCH, GPIO_PIN_SET);
	//	LCD_CTRL |= (1 << RW_SWITCH);
	MCAL_GPIO_Write_PIN(LCD_PORT,RS_SWITCH, GPIO_PIN_RESET);

	//	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();

	//DATA pins output config
	//P0 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_0;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P1 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P2 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_2;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P3 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_3;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P4 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_4;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P5 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_5;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P6 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_6;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);

	//P7 config output pp
	PinConfig.GPIO_MODE=GPIO_MODE_Output_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_7;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_PORT,&PinConfig);


	//	DataDir_LCD_PORT |= (0xFF<<DATA_shift);
	MCAL_GPIO_Write_PIN(LCD_PORT,RW_SWITCH, GPIO_PIN_RESET);

	//	LCD_CTRL &= ~(1 << RW_SWITCH);

}


void LCD_WRITE_COMMAND(unsigned char command){
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	MCAL_GPIO_Write_Port(LCD_PORT, command);
	//	LCD_PORT = command;
	MCAL_GPIO_Write_PIN(LCD_PORT,RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_Write_PIN(LCD_PORT,RW_SWITCH, GPIO_PIN_RESET);

	//	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	LCD_lcd_kick();
#endif
#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_lcd_kick ();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_lcd_kick();
#endif
}

void LCD_WRITE_CHAR(unsigned char character){
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	MCAL_GPIO_Write_Port(LCD_PORT,character);
	//	LCD_PORT = character;
	MCAL_GPIO_Write_PIN(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);
	//	LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_Write_PIN(LCD_PORT,RS_SWITCH, GPIO_PIN_SET);

	//	LCD_CTRL |= (1 << RS_SWITCH);
	delay(1);
	LCD_lcd_kick();
#endif
#ifdef FOUR_BIT_MODE
	//LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_lcd_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_lcd_kick ();
#endif
}

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}
