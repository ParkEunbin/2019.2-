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

	printf("������ �����Է�: ");
	scanf("%d", &num);
	//�������� �޾� 2�� ���� ���������� stack�� �׾��ش�. �������� �� ������ ���� �������� ����� ���̴�.
	while (num > 0) {
		digit = (int*)malloc(sizeof(int));
		*digit = num % 2;
		pushStack(stack, digit);
		num = num / 2;
	}
	//���� �ֱٿ� ���� ������ ��(top)���� ������ָ� �ȴ�.
	printf("������: ");
	while (!emptyStack(stack) ){
		digit = (int*)popStack(stack);
		printf("%1d", *digit);
	}
	printf("\n");

	destroyStack(stack);
	return 0;
}

*/