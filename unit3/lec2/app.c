#include "uart.h"
unsigned char string_buffer[100]="learn-in-depth:Esraa";
void main(void )
{
Uart_set_string (string_buffer);

}
