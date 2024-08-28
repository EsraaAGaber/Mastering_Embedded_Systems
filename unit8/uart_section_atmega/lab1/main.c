
#include "lcd.h"



int main(void)
{
	LCD_INIT();
	UART_INIT();
	
	
	LCD_clear_screen();
	UART_SEND_string(" esraa");
	LCD_WRITE_STRING("hi there");
	_delay_ms(2000);
	LCD_clear_screen();
	while (1)
	{
		
		char* x=(char*)UART_RECEIVE_STRING();
		LCD_clear_screen();
		LCD_WRITE_STRING(x);
	
	}
	
}