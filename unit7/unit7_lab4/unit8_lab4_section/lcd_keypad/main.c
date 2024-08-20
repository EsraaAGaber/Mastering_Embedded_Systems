
#include "HAL/inc/lcd.h"



int main(void)
{LCD_INIT();
	/* Replace with your application code */
	while (1)
	{
		
		LCD_WRITE_STRING("Learn_In_Depth..");
		_delay_ms(2000);
		LCD_clear_screen();
		LCD_WRITE_STRING("Esraa Gaber");
		_delay_ms(2000);
		LCD_clear_screen();

	
	}
	
}