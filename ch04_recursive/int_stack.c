#include <stdlib.h>
#include "ch04_def.h"

IntStack* create_int_stack(int element_size) 
{
	IntStack* stack = (IntStack*)malloc(sizeof(IntStack));//메모리 할당
	if (stack == NULL) {
		return NULL;//메모리 할당이 실패함
	}
	else {

		stack->element = (int*)malloc(sizeof(int) * element_size); //  =>stack이 생성이 안되어 있으면 어쩔거냐?
		stack->top = -1;
		stack->size = element_size;
	}

	return stack;
}
int is_empty_intstack(IntStack stack){
if (stack.top == -1) {
	return 1;
}

return 0;
}

int is_full_intstack(IntStack stack) {

	if (stack.top == (stack.size - 1)) {
		return 1; //stack full
	}
	return 0;
}

void push_intstack(IntStack* stack, int value)
{
	if (is_full_intstack(*stack)) {
		printf("stack is full\n");
		return;
	}
	stack->top += 1;
	stack->element[stack->top] = value;
}

int pop_intstack(IntStack* stack) {

	int pop_value;
	if (is_empty_intstack(*stack)) {
		printf("stack is empty");
		return;
	}
	pop_value = stack->element[stack->top];
	stack->top += -1;
	return pop_value;
}