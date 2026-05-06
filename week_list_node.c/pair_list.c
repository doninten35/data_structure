#include <stdio.h>
#include <stdlib.h>
#include "def_list_node.h"

PairNode* create_pair_node()
{
	PairNode* p = (PairNode*)malloc(sizeof(PairNode));
	p->prev = p;
	p->next = p;
	return p;
}

void insert_pair_node_to_next(PairNode* node, int data)
{
	PairNode* p = create_pair_node();
	p->data = data;
	p->prev = node;
	p->next = node->next;
	p->next->prev = p;
	node->next = p;
}

void delete_pair_node_to_next(PairNode* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

void print_pair_list(PairNode* head)
{
	PairNode* p;
	for (p = head->next; p != head; p = p->next) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

void test_pair_node(void)
{
	PairNode* head = create_pair_node();
    printf("INSERT\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽에 삽입
		insert_pair_node_to_next(head, i);
		print_pair_list(head);
	}
	printf("\nDELETE\n");
	for (int i = 0; i < 5; i++) {
		print_pair_list(head);
		delete_pair_node_to_next(head->next);
	}
	free(head);
}
