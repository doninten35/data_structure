#ifndef  __INT_QUEUE_H__
#define  __INT_QUEUE_H__

#include "def_queue.h"

extern IntQueue* create_int_queue(int elements_size);
extern void enqueue_int_queue(IntQueue* q, int data);
extern int dequeue_int_queue(IntQueue* q);


#endif

