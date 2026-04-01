#ifndef __INT_STACK_H__
#define __INT_STACK_H__
#include "ch04_def.h"



extern IntStack* create_int_stack(int element_size);
extern int is_empty_intstack(IntStack stack);
extern int is_full_intstack(IntStack stack);
extern void push_intstack(IntStack* stack, int value);
extern int pop_intstack(IntStack* stack);


#endif
