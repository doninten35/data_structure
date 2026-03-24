#include <stdio.h>

void exam_1_1(int n) { /////12345

	if (n > 0) {
		exam_1_1(n - 1);
		printf("%d", n);


	}
}

void exam_1_2(int n) { /////54321

	if (n > 0) {
		printf("%d", n);
		exam_1_2(n - 1);

	}
}

int exam_1_3(int n) {///1부터 n까지 합

	if (n > 0) {
		return  n + exam_1_3(n - 1);
		
	}
	return 0;
	
}

int exam_2(int n) {

	if (n <=1) {
		return 1;
	}
	return exam_2(n / 2) + exam_2(n - 1);
}

int exam_3(int n) {//작업 횟수 출력

	if (n <= 1) {
		return 0;
	}

	if (n % 2 == 0) {
		return 1 + exam_3(n / 2);
	}

	else {
		return 1 + exam_3(n / 3);
	}
}

int exam_4(int n) {///각 자리 숫자 제곱의 합

	if (n == 0) {
		return 0;
	}

	int number = n % 10;
	return (number * number) + exam_4(n / 10);

}

int exam_5_1(int n) {//각 자리 숫자 중 0을 제외한 모든 수들의 곱
	 
	if (n == 0) {
		return 1;
	}
	
	int digit = n % 10;

	if (digit == 0) {
		return exam_5_1(n / 10);
	}
	else {
		return digit * exam_5_1(n / 10);
	}
}

int main()
{
	exam_1_1(5);
	exam_1_2(5);
	printf("%d", exam_1_3(5));
	printf("%d", exam_2(10));
	printf("%d", exam_3(100));
	printf("%d", exam_4(12345));
	printf("%d", exam_5_1(123));
	return 0;

}
