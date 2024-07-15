#include "fifo.h"

FIFO_buf_status FIFO_init(FIFO_buf_t* FIFO_buf, element_type* buf, unsigned int length) {
    if (buf == NULL)
        return FIFO_null;
    FIFO_buf->base = buf;
    FIFO_buf->head = buf;
    FIFO_buf->tail = buf;
    FIFO_buf->count = 0;
    FIFO_buf->length = length;
    return FIFO_no_error;
}

FIFO_buf_status FIFO_enqueue(FIFO_buf_t* FIFO_buf, element_type item) {
    if (!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
        return FIFO_null;
    if (FIFO_buf->count == FIFO_buf->length) return FIFO_full;
    *(FIFO_buf->head) = item;
    FIFO_buf->count++;
    if ((FIFO_buf->head) - (FIFO_buf->base) == ((FIFO_buf->length) * sizeof(element_type)))
        FIFO_buf->head = FIFO_buf->base;
    else
        FIFO_buf->head++;
    return FIFO_no_error;
}

// Uncomment and fix the dequeue function if needed
// FIFO_buf_status FIFO_dequeue(FIFO_buf_t* FIFO_buf, unsigned int* item) {
//     if (!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
//         return FIFO_null;
//     if (FIFO_buf->count == 0) return FIFO_empty;
//     FIFO_buf->count--;
//     *item = *((FIFO_buf->tail)->roll);
//     if ((FIFO_buf->tail) - (FIFO_buf->base) == ((FIFO_buf->length) * sizeof(element_type)))
//         FIFO_buf->tail = FIFO_buf->base;
//     else
//         FIFO_buf->tail++;
//     return FIFO_no_error;
// }

void FIFO_print(FIFO_buf_t* FIFO_buf) {
    element_type* temp;
    int i;
    if (FIFO_buf->count == 0) {
        printf("The FIFO is empty\n");
    } else {
        temp = FIFO_buf->tail;
        for (i = 0; i < FIFO_buf->count; i++) {
					printf("name:%s %s\n gpa :%f \n courses  %d %d %d %d\n",(*temp).fname ,(*temp).lname,(*temp).GPA ,(*temp).SUBJECTS[0],(*temp).SUBJECTS[1],(*temp).SUBJECTS[2],(*temp).SUBJECTS[3]);
            if (temp == FIFO_buf->base + ((FIFO_buf->length) * sizeof(element_type)))
                temp = FIFO_buf->base;
            else
                temp++;
        }
    }
}