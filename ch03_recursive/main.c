#include <stdio.h>

typedef struct {

	int height;
	double weight;
}person;

void ex01(int* array, int length)
{
	int i,j;
	int value;
	for (i = 0; i < length; i++) 
	{
		 value = array[i];
		for (j = 0;j < value; j++) {
			printf("%d", value);
		}
		
	}
	printf("\n");
}


void test_ex01()
{
	int buf[3] = {5,1,4};
	ex01(buf, 3);
	
}


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

		else {
			value[i] = array[i];
		}
		
	}
	
	
	for (i = 0; i < length; i++) {
		
			printf("%d ", value[i]);    
		}
	
	printf("\n");
}



void test_ex02()
{

	int arr[6] = {1,2,3,100,99,98}; 
	ex02(arr, 6);

}

void ex_04(person father, person mother){

	person student;
	int i;

	student.height = (int)((father.height + mother.height) / 2 + 5);

	double avg_weight = (father.weight + mother.weight) / 2 - 4.5;
	student.weight = (int)(avg_weight * 10 + 0.5) / 10.0;

	printf("height: %dcm\n", student.height);
	printf("weight %.1lfkg\n", student.weight);
}
void test_ex04()
{
	person father = { 175, 68.8 }; 
	person mother = { 166, 56.4 }; 
		
	ex_04(father,mother);
}
 


int main(void) 
{
	test_ex01();
	test_ex02();
	test_ex04();

	return 0;
}
