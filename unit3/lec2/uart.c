#include "uart.h"

#define UART0DR *((volatile unsigned int* const )((unsigned int *)0x101f1000))
void Uart_set_string(unsigned char * P_TX_STRING)
{
while (P_TX_STRING!='\0')
  {
UART0DR=(unsigned int )(*P_TX_STRING);
 P_TX_STRING++;
  }
}
