#include "def_list.h"
#include <stdio.h>


ListNode* create_list_node(void)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) {
		printf("error: create list node\n");
		return ;
		head->link = NULL;
	}
	return head;
}

void insert_first_node(ListNode* head, int value)
{
	ListNode* node = create_list_node(); //데이터를 넣을 노드 생성
	node->link = head->link; //생성한 것에서 기존의 처음 것의 링크에 있음, 연결 
	head->link = node->link;
}
