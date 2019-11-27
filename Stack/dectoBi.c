/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "stacksADT.h"

int main(void) {
	unsigned int num;
	int * digit;
	STACK * stack;

	stack = createStack();

	printf("십진수 정수입력: ");
	scanf("%d", &num);
	//십진수를 받아 2로 나눈 나머지값을 stack에 쌓아준다. 이진수는 그 나머지 값을 역순으로 출력한 값이다.
	while (num > 0) {
		digit = (int*)malloc(sizeof(int));
		*digit = num % 2;
		pushStack(stack, digit);
		num = num / 2;
	}
	//가장 최근에 들어온 나머지 값(top)부터 출력해주면 된다.
	printf("이진수: ");
	while (!emptyStack(stack) ){
		digit = (int*)popStack(stack);
		printf("%1d", *digit);
	}
	printf("\n");

	destroyStack(stack);
	return 0;
}

*/