#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stacksADT.h"
//���������� �Ǵ�
bool isOperator(char token) {
	if (token == '*' || token == '/' || token == '+' || token == '-')
		return true;
	return false;
}
//�����ڿ� ���� ���
int calc(int operand1, int oper, int operand2) {
	int result;
	switch (oper) {
	case '+': result = operand1 + operand2;
		break;
	case '-': result = operand1 - operand2;
		break;
	case '*': result = operand1 * operand2;
		break;
	case '/': result = operand1 / operand2;
		break;
	}
	return result;
}

int main(void) {
	char token;
	int operand1;
	int operand2;
	int value;
	int* dataPtr;
	STACK* stack;

	stack = createStack();

	printf("�� �Է�: ");
	while ((token = getchar()) != '\n') {//�ѹ��ھ� �޾ƿ���
		if (!isOperator(token)) {//�����ڰ� �ƴ� ��, stack�� push
			dataPtr = (int*)malloc(sizeof(int));
			*dataPtr = atoi(&token);//���ڿ� ������ȯ
			pushStack(stack, dataPtr);
		}
		else {//�������� ��,stack�� ���� ������ �ΰ�pop�ؼ� �����ڷ� ���-> ��갪 �ٽ� push
			dataPtr = (int*)popStack(stack);
			operand2 = *dataPtr;
			dataPtr = (int*)popStack(stack);
			operand1 = *dataPtr;
			value = calc(operand1, token, operand2);
			dataPtr = (int*)malloc(sizeof(int));
			*dataPtr = value;
			pushStack(stack, dataPtr);
		}
	}
	//stack�� ���� ���� ���� ���
	dataPtr = (int*)popStack(stack);
	value = *dataPtr;
	printf("�����: %d \n", value);

	destroyStack(stack);
	return 0;
}