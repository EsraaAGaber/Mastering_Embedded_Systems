#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
typedef struct {
    char fname[20];
    char lname[20];
    int roll;
    float GPA;
    int SUBJECTS[4];
} Data;

#define element_type Data
#define width 50
element_type students_buffer[width];

typedef struct {
    unsigned int length;
    unsigned int count;
    element_type *base;
    element_type *head;
    element_type *tail;
} FIFO_buf_t;

typedef enum {
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
} FIFO_buf_status;

FIFO_buf_status FIFO_init(FIFO_buf_t* FIFO_buf, element_type* buf, unsigned int length);
FIFO_buf_status FIFO_enqueue(FIFO_buf_t* FIFO_buf, element_type item);
FIFO_buf_status FIFO_dequeue(FIFO_buf_t* FIFO_buf, unsigned int* item);
void FIFO_print(FIFO_buf_t* FIFO_buf);

#endif /* FIFO_H_ */