/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "stacksADT.h"

int main(void) {
	bool done = false;
	int* dataPtr;
	STACK* stack;
	//stack����
	stack = createStack();

	while (!done) {
		dataPtr = (int*)malloc(sizeof(int));
		printf("�����Է�(����� ctrl+z): ");
		//EOF�ų� ������ full�� ��쿡 �ݺ����� Ż��
		if(scanf("%d",dataPtr)== EOF || fullStack(stack)){
			done = true;
		}
		else {//�� �� ������ ������ stack�� push����
			pushStack(stack, dataPtr);
		}
	}

	printf("==���==\n");
	while (!emptyStack(stack)) {
		//stack�� ������ ���߿� ���� ������(top)���� ��� �ȴ�. stack�� ���� ���� �ϸ� stack���� data�� ��� ��µ� �� ��.
		dataPtr = (int*)popStack(stack);
		printf("%3d\n", *dataPtr);
		free(dataPtr);
	}
	//����� stack�ı�
	destroyStack(stack);
	return 0;
}
*/