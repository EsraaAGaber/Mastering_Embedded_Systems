/*
 * LIFO.h
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */


/*
 * LIFO.h
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */
#ifndef LIFO_H_
#define LIFO_H_

typedef struct {
	unsigned int length;
	unsigned int *count; //umber of
	unsigned int* base;//adress first element
	unsigned int *head ;//adress top element

}LIFO_buf_t;
typedef enum {
	LIFO_no_eror,LIFO_full,LIFO_empty,LIFO_null
}LIFO_status;
LIFO_status LIFO_add_item(LIFO_buf_t* lifo_buf ,unsigned int item);
LIFO_status LIFO_get_item(LIFO_buf_t* lifo_buf ,unsigned int* item);
LIFO_status LIFO_init(LIFO_buf_t* lifo_buf ,unsigned int* buf,unsigned int length);




#endif

