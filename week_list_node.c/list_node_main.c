#include <stdio.h>
#include "def_list_node.h"


extern void test_pair_node(void);
extern void test_circle_node(void);
extern void test_list_node(void);

int main(void)
{
	// printf("Hello World\n");
	test_list_node();
	test_pair_node();
	test_circle_node();


	

	return 0;
}