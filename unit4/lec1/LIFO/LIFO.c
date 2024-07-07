/*
 * LIFO.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */


/*
 * LIFO.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */
#include "LIFO.h"
#include "stdio.h"
LIFO_status LIFO_add_item(LIFO_buf_t* lifo_buf ,unsigned int item)
{
	if (!lifo_buf->base)
		return LIFO_null;
	if (lifo_buf->count==lifo_buf->length)return LIFO_full;
	*(lifo_buf->head)=item;
	lifo_buf->head++;
	lifo_buf->count++;

	return LIFO_no_eror;
}
LIFO_status LIFO_get_item(LIFO_buf_t* lifo_buf ,unsigned int* item){
	if (!lifo_buf->base)
			return LIFO_null;
		if (lifo_buf->count==0)return LIFO_empty;
		lifo_buf->head--;
		*item=*(lifo_buf->head);

		lifo_buf->count--;

		return LIFO_no_eror;
}
LIFO_status LIFO_init(LIFO_buf_t* lifo_buf ,unsigned int* buf,unsigned int length){

	if (buf==NULL)
				return LIFO_null;
	lifo_buf->base=buf;
	lifo_buf->head=buf;
	lifo_buf->count=0;
	lifo_buf->length=length;
}

