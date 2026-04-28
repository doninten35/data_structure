#include <stdlib.h>
#include <stdio.h>
#include "def_list.h"

ArrayList* create_array_list(int size)
{
	ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
	if (!list) {
		printf("error: create list");
		return NULL;//프로그램 종료 exit(0);
	}

	//배열의 크기를 가지고 배열을 선언
	
		list->element = (int*)malloc(sizeof(int) * size);
		if (list->element== NULL) {
			printf("error: create element\n");
			return NULL;
		}
		list->size = size;
		list->pos = 0; //현재 갯수가 0개 들어가 있다. 
		//list->pos = -1; //list에 아무 데이터가 없다.
	}

int is_empty_array_list(ArrayList *list){

	if (list->pos == 0) {
		return 1;
	}
	return 0;

}

int is_full_array_list(ArrayList* list)
{
	if (list->pos == list->size) {
		return 1;
	}
	return 0;
}

//활용하는 과정에 따라서 선택
//int..return하고싶다 => 삽입이 잘되면 1, 삽입이 안 되면 0
//void => 삽입 성공 여부 검토하지 않겠다.

void insert_pos_array_list(ArrayList* list, int data, int position)
{
	int i;
	if (is_full_array_list(list)) {
		printf("list is full\n");
		return;
	}
	for (i = list->pos; i > position; i--) {
		list->element[i] = list->element[i - 1];
	}
	list->element[position] = data;
	list->pos++;
}

void insert_first_array_list(ArrayList* list, int data)
{
	int i; 
	if (is_full_array_list(list)==1) {
		printf("array is full\n");
		return;
	}


	for (i = list->pos; i > 0; i--) {
		list->element[i] = list->element[i - 1];
	}
	  list->element[0] = data;
	  list->pos++;
}
/*
void insert_first_array_list(ArrayList* list, int data)
{
	intert_pos_array_list(list, data, 0);
}
*/


void insert_last_array_list(ArrayList* list, int data)
{
	if (is_full_array_list(list)) {
		printf("list is full\n");
		return;
	}
	list->element[list->pos] = data;
	list->pos++;
}
/*void insert_last_array_list(ArrayList* list, int data)
{
	intert_pos_array_list(list, data, lost->pos);
}*/

void delete_pos_array_list(ArrayList* list, int pos)
{
	int i;
	int data;

	if (is_empty_array_list(list)) {  //지울 수 있는지 검토
		printf("delete error: list is full\n");
		return;
	}
	else if (pos<0 && pos>list->pos) {
		printf("delete error: position error\n");
		return;
	}
	data = list->element[pos];  
	for (i = pos; i < list->pos; i++) {
		list->element[i] = list->element[i + 1];
	}
	list->pos--;
	return data;
}

/*void print_array_list(ArrayList* list) {
	int i;
	for (i = 0;i < list->pos;i++) {
		printf("%d->", list->element[i]);
	}
}*/



