#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include "def_list.h"

extern ArrayList* create_array_list(int size);
extern int is_empty_array_list(ArrayList* list);
extern int is_full_array_list(ArrayList* list);
extern void insert_first_array_list(ArrayList* list, int value);
extern void insert_last_array_list(ArrayList* list, int data);
extern void insert_pos_array_list(ArrayList* list, int data, int position);
extern void delete_pos_array_list(ArrayList* list, int pos);




#endif // __ARRAY_LIST_H__

