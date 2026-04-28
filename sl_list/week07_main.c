#include <stdio.h>
#include "def_list.h"
#include "array_list.h"


int main(void) {
	ArrayList* array_list = create_array_list(10);
	
	insert_first_array_list(array_list, 5);
	insert_first_array_list(array_list, 4);
	insert_first_array_list(array_list, 3);
	/*insert_first_array_list(array_list, 2);
	insert_first_array_list(array_list, 1);
	insert_first_array_list(array_list, 0);*/

	insert_last_array_list(array_list, 10);
	insert_last_array_list(array_list, 8);

	insert_pos_array_list(array_list, 20, 3);
	insert_pos_array_list(array_list, 15, 1);

	delete_pos_array_list(array_list, 5);
	printf("list\n");
}

