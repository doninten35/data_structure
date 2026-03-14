#include <stdio.h>

void exam_1_1(int n) {

	if (n > 0) {
		printf("%d", n);
		exam_1_1(n - 1);
		
	}
}

int main()
{
	exam_1_1(5);
	return 0;

}
