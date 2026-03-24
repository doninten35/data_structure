#include <stdio.h>

/*void ex01(int* array, int length)
{
	int i;
	int value;
	for (i = 0; i < length; i++) 
	{
		value = array[i];
		printf("%d", value);
	}

}


void test_ex01()
{
	int buf[3] = {5,1,4};
	ex01(buf, 3);
	
}*/


void ex02(int* array, int length) {

	int i;
	int value[6];
	for (i = 0;i <length; i++) {
		if (array[i] >= 50 && array[i] % 2 ==0)  {
			value[i] = array[i] / 2;

		}
		else if(array[i] < 50 && array[i] % 2 !=0) {
			value[i] = array[i] * 2;
		}
		printf("%d", value);
	}

}

void test_ex02()
{

	int arr[6] = {1,2,3,100,99,98}; 
	ex02(arr, 6);

}

int main(void) 
{
	//test_ex01();
	test_ex02();

	return 0;
}
