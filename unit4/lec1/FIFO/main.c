/*
 * main.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */

#include "FIFO.h"
void main()
{
	FIFO_buf_t FIFO_uart;
	element_type i,temp=0;
	if (FIFO_init(&FIFO_uart, uart_buffer, 5)==FIFO_no_eror)
		printf("FIFO init ---done ----\n");

	for (i=0;i<5;i++){
			if (FIFO_enqueue(&FIFO_uart, i)==FIFO_no_eror)
				printf("enqueue done (%x)\n",i);
			else
				printf("enqueue fail\n");
		}
	FIFO_print(&FIFO_uart);
	if (FIFO_dequeue(&FIFO_uart, &temp)==FIFO_no_eror)
		printf("the top is %x\n",temp);
	if (FIFO_dequeue(&FIFO_uart, &temp)==FIFO_no_eror)
		printf("the top is %x\n",temp);

}
