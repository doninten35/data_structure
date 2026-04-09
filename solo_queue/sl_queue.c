#include <stdio.h>

#include "Int_queue.h"


int main(void) {

	IntQueue* q = create_int_queue(5);
	int data;

	enqueue_int_queue(q, 3);
	enqueue_int_queue(q, 5);
	enqueue_int_queue(q, 7);

	enqueue_int_queue(q, 3);
	enqueue_int_queue(q, 5);
	enqueue_int_queue(q, 7);
	

	data = dequeue_int_queue(q);
	printf("data: %d\n", data);

	data = dequeue_int_queue(q);
	printf("data: %d\n", data);
	
	data = dequeue_int_queue(q);
	printf("data: %d\n", data);

	data = dequeue_int_queue(q);
	printf("data: %d\n", data);
	
	
	
	return 0;
	
}

