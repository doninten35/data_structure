#ifndef __DEF_LIST_NODE_H__
#define __DEF_LIST_NODE_H__

typedef struct {
	int* data;
	int max_size;
	int size;
} ArrayList;

typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode;

typedef struct CircleNode {
	int data;
	struct CircleNode* next;
}CircleNode;



typedef struct PairNode {
	int data;
	struct PairNode* prev;
	struct PairNode* next;
} PairNode;


#endif

