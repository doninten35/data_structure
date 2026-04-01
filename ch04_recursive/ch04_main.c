#include <stdio.h>
#include <stdlib.h>
#include "ch04_def.h"
#include "int_stack.h"


#define STACK_SIZE 100

int* create_int_array_stack(int length) {
	int* stack = (int*)malloc(sizeof(int) * length);
	return stack;
}

int is_empty_int_stack(int top) {
	if (top == -1) {
		return 1;//empty o
	}
	else {
		return 0;//empty x
	}
}

int is_full_int_stack(int top) {
	if (top == (STACK_SIZE - 1)) {
		return 1; //full
	}
	else {
		return 0;
	}

}

void push_int_stack(int* stack, int* top, int element) {
	if (is_full_int_stack(*top) == 1) {
		printf("push error: stack is full\n");
		return;
	}
	*top += 1;
	stack[*top] = element;
}

int pop_int_stack_array(int* stack, int* top) {

	int element;
	if (is_empty_int_stack(*top) == 1) {
		printf("pop error: stack is empty\n");
		return 0;
	}
	element = stack[*top];
	*top += -1;
	return element;
}

void test_int_array_stack() {

	int array[STACK_SIZE];
	int* stack_array = create_int_array_stack(STACK_SIZE);
	int top = -1;
	int element = 0;

	if (1 == is_empty_int_stack(top)) {
		printf("stack is empty\n");
	}

	else {
		printf("stack is not empty\n");
	}

	if (0 == is_full_int_stack(top)) {
		printf("stack is not full\n");
	}

	else {
		printf("stack is full\n");
	}

	push_int_stack(stack_array, &top, 5);
	push_int_stack(stack_array, &top, 2);
	push_int_stack(stack_array, &top, 3);
	//push_int_stack(stack_array, &top, 4);

	element = pop_int_stack_array(stack_array, &top);
	printf("pop value = %d\n", element);

	element = pop_int_stack_array(stack_array, &top);
	printf("pop value = %d\n", element);

	element = pop_int_stack_array(stack_array, &top);
	printf("pop value = %d\n", element);

	element = pop_int_stack_array(stack_array, &top);
	printf("pop value = %d\n", element);

	/*element = pop_int_stack_array(stack_array, &top);
	printf("pop value = %d\n", element); */


	
}









int main(void) {

	//test_int_array_stack();

	IntStack* s = create_int_array_stack(10);
	int value;

	if (1 == is_empty_intstack(*s)) {
		printf("stack is empty\n");
	}

	else {
		printf("stack is not empty\n");
	}

	if (0 == is_full_intstack(*s)) {
		printf("stack is not full\n");
	}

	else {
		printf("stack is full\n");
	} 

	push_intstack(s, 5);
	push_intstack(s, 2);
	push_intstack(s, 4);
	push_intstack(s, 10);

	value = pop_intstack(s);
	printf("povalue = %d\n", value);

	value = pop_intstack(s);
	printf("povalue = %d\n", value);
	
	value = pop_intstack(s);
	printf("povalue = %d\n", value);
	
	value = pop_intstack(s);
	printf("povalue = %d\n", value);
	
	return 0;

}

