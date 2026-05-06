#include <stdio.h>
#include <stdlib.h>
#include "def_list_node.h"


ListNode *create_list_node()
{
  ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  if(head==NULL) {
    printf("memory error: List Node\n");
    exit(1);
  }
  head->next = NULL;
  return head;
}

ListNode *insert_first_node(ListNode *head, int value)
{
  ListNode *p = create_list_node();
  p->data = value;
  p->next = head;
  head = p;
  return head;
}

ListNode *insert_pre_node(ListNode *head, ListNode *pre, int value)
{
  ListNode *p=create_list_node();
  p->data=value;
  p->next=pre->next;
  pre->next = p;
  return head;
}


ListNode *delete_pre_node(ListNode *head, ListNode *pre)
{
  ListNode *remove_node;
  remove_node = pre->next;
  pre->next = remove_node->next;
  free(remove_node);
  return head;
}

ListNode *delete_first_node(ListNode *head)
{
  ListNode *remove_node;
  if(head==NULL) {
    return NULL;
  }
  remove_node = head;
  head = remove_node->next;
  free(remove_node);
  return head;
}

void print_list_node(ListNode *head)
{
  ListNode *p = NULL;
  for(p=head; p!=NULL; p=p->next) {
    printf("%d->", p->data);
  }
  printf("NULL\n");
}

ListNode* search_list_node(ListNode* head, int x)
{
  ListNode* p = head;
  while (p != NULL) { //리스트의 끝까지 검색(loop 사용)
    if (p->data == x) { //x가 발견되면 해당 리스트의 포인터 반환
      return p;
    }
    p = p->next; // x가 발견되지 않으면 다음 링크로 업데이트
  }
  return NULL; 
}

ListNode* delete_list_node(ListNode* head, ListNode* node)
{
  ListNode* p = head;
  ListNode* parent_node = NULL;
  while (p != NULL) { //리스트 끝까지 순회(loop 사용) 
    if (p->next == node)// p의 다음 노드가 삭제할 노드이면 p를 parent_node에 저장
      parent_node = p;
    p = p->next; //순회 진행
  }
  if (parent_node == NULL) {
    printf("no list\n");
    return NULL;
  }
  return delete_pre_node(head, parent_node); 
}


void test_list_node(void)
{
  int i;
  ListNode* head = NULL;
  ListNode* temp = NULL;
  for (i = 0; i < 5; i++) {
    head = insert_first_node(head, i + 1);
    print_list_node(head);
  }


  printf("-------- delete node test --------\n");
  temp = search_list_node(head, 3);
  delete_list_node(head, temp);
  print_list_node(head);
  //calc_sum(head);

  /*
  
  

  for (i = 0; i < 5; i++) {
    head = delete_first_node(head);
    print_list_node(head);
  }
  */
  return 0;
}

ListNode* inverse_list_node(ListNode* head, ListNode* node) {
 //순회 포인터로 p,q,r사용
    ListNode* p, * q, * r;

    p = head;  //p는 역순으로 만들 리스트
    q = NULL;  // q는 역순으로 만들 노드
    while (p != NULL) { 
    
        r = q; //r은 역순으로 된 리스트
//r은 q, q는 p를 차례로 따라간다
        q = p;
        q->next = r; //q의 링크 방향을 바꾼다
        p = p->next;
    
    }
    return q;

}