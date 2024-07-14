#ifndef MANGE_H
#define MANGE_H

#include "fifo.h"

void add_student_file(FIFO_buf_t* students_data);
void add_student_manually(FIFO_buf_t* students_data);
FIFO_buf_status find_rl(FIFO_buf_t* students_data);
void find_fn(FIFO_buf_t* students_data);
void find_c(FIFO_buf_t* students_data);
void tot_s(FIFO_buf_t* students_data);
void del_s(FIFO_buf_t* students_data);
void up_s(FIFO_buf_t* students_data);
void show_s(FIFO_buf_t* students_data);
FIFO_buf_status find(FIFO_buf_t* students_data,int id);

#endif /* MANGE_H */
