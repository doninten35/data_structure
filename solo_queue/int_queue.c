
#include <stdlib.h>
#include <stdio.h>
#include "def_queue.h"



IntQueue* create_int_queue(int elements_size) {

	IntQueue* q = (IntQueue*)malloc(sizeof(IntQueue));
	if (q == NULL) {
		printf("queue 메모리 할당 실패");
	}

	else {
		q->elements = (int*)malloc(sizeof(int) * elements_size);
		q->front = -1;
		q->rear = -1;
		q->size = elements_size;

	}
}

int is_empty_int_queue(IntQueue* q)
{
	if (q->front == q->rear) {
		return 1;
	}
	return 0;



}

int is_full_int_queue(IntQueue* q)
{
	if ((q->rear + 1) == q->size) {
		return 1;
	}
	return 0;

}

void enqueue_int_queue(IntQueue* q, int data) {
	//full인지 검사
	if (is_full_int_queue(q) == 1) {
		printf("queue is full: enqueue\n");
	}
	else { //data 삽입
		q->rear++;
		q->elements[q->rear] = data;
	}
}

int dequeue_int_queue(IntQueue* q) {
	int data = NULL;
	//empty 검사
	if (is_empty_int_queue(q) == 1) {
		printf("queue is empty : dequeue\n");
	}
	else {//데이터 리턴
		q->front++;
		data = q->elements[q->front];
		return data;
	}
}


