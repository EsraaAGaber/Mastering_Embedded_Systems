/*
 * main.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */


/*
 * main.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */

#include "LIFO.h"
#include "stdio.h"
unsigned int buffer1[5];
#include "stdlib.h"
void main()
{
	LIFO_buf_t uart_lifo ,i2c_lifo ;
	LIFO_init(&uart_lifo,buffer1,5);
	unsigned int *buffer2=malloc(5*sizeof(unsigned int));
	LIFO_init(&i2c_lifo,buffer2,5);
	int i=0,temp=0;
	for (i=0;i<5;i++)
	{
		LIFO_add_item(&uart_lifo,i);
		printf("add %d\n",i);
	}
	for (i=0;i<5;i++)
		{
			LIFO_get_item(&uart_lifo,&temp);
			printf("get %d\n",temp);
		}

}
