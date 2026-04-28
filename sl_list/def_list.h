#ifndef __DEF_LIST_H__
#define __DEF_LIST_H__

typedef struct {
	int* element;//생성한 배열
	int pos; //현재위치, 현재 들어가 있는 데이터의 갯수
	int size; //리스트의 총 크기

}ArrayList;

typedef struct {
	int data;
	ListNode* link;

}ListNode;






#endif 

