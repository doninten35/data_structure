#include <stdio.h>
#include <stdlib.h>
#include "def_list_node.h"

CircleNode* create_list_circle_node()
{
    CircleNode* p = (CircleNode*)malloc(sizeof(CircleNode));
    if (p == NULL) {
        printf("memory error: Circle List\n");
        exit(1); //프로그램 종료
    }
    p->next = NULL;
    return p;
}

CircleNode* insert_last_circle_node(CircleNode* head, int x)
{
    CircleNode* p = create_list_circle_node();
    p->data = x;
    if (head != NULL) {
        p->next = head->next;
        head->next = p;
    }
    else {
        p->next = p;
    }
    return p;
}

CircleNode* insert_first_circle_node(CircleNode* head, int x)
{
    CircleNode* p = create_list_circle_node();// 삽입할 노드 생성
    p->data = x;// 노드의 데이터에 x값 대입
    if (head != NULL) {
        // 생성한 node의 next는 첫 번째 node(head->next)를 가리킴
        p->next = head->next;
        // head의 next가 생성한 노드를 가리킴
        head->next = p;
    }  
    else {
        // head가 없을 경우(NULL) head에 노드 연결
        p->next = p;
        head = p;
    }  
    return head;// head 포인터 반환
}

void print_circle_list(CircleNode* head)
{
    CircleNode* p;
    if (head == NULL) return;
    p = head->next;
    do {
        printf("%d->", p->data);
        p = p->next;
    } while (p != head->next);
    printf("\n");
}


void test_circle_node(void)
{
    CircleNode* head = NULL;
    // list = 10->20->30->40
    head = insert_last_circle_node(head, 20);
    head = insert_last_circle_node(head, 30);
    head = insert_last_circle_node(head, 40);
    head = insert_first_circle_node(head, 10);
    print_circle_list(head);
    return ;
}



