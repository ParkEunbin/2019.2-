/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "stacksADT.h"

//������ �켱���� �����ֱ�
int priority(char token) {
	if (token == '*' || token == '/')
		return 2;
	if (token == '+' || token == '-')
		return 1;
	return 0;
}
//���������� �Ǵ�
bool isOperator(char token) {
	if (token == '*' || token == '/' || token == '+' || token == '-')
		return true;
	return false;
}

int main(void) {
	char postfix[80] = { 0 };
	char temp[2] = { 0 };
	char token;
	char* dataPtr;
	STACK* stack;

	stack = createStack();

	printf("infix ������ �� �Է�: ");
	while ((token = getchar()) != '\n') {//���� �ϳ��� ����
		if (token == '(') {//'('�� �� stack�� push
			dataPtr = (char*)malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else if (token == ')') {//')'�� �� pop�� ������->dataPtr
			dataPtr = (char*)popStack(stack);
			while (*dataPtr != '(') {//'('�ƴϸ� temp�� �ְ� postfix�� temp�̾���̱�->dataPtr�� ���� ���� pop���� �ֱ�->�ݺ�
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)popStack(stack);
			}
		}
		else if (isOperator(token)) {//���� ���ڰ� �������� ��
			dataPtr = (char*)stackTop(stack);//dataPtr�� stack�� Top ������ �ֱ�
			while (!emptyStack(stack) && priority(token) <= priority(*dataPtr)) {//stack�� �Ⱥ����, ���� �������� �켱������ dataPtr�� ����Ű�� ���� �켱�������� ���ٸ� �ݺ�
				dataPtr = (char*)popStack(stack);
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)malloc(sizeof(char));//stack�ȿ� �ִ� �����Ͱ� ���ų�, �ȿ� �ִ� �����ڰ� �켱������ �� ���� �� ���� �ݺ�
			}
			dataPtr = (char *)malloc(sizeof(char));//�׷��� ���� ��쿣 stack�� push
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else {//�ǿ������� ��� �ٷ� ���
			temp[0] = token;
			strcat(postfix, temp);
		}
	}//���� ���� ��
	while (!emptyStack(stack)) {//stack�� ������� �ʴٸ� ���� ������ pop�ϸ鼭 postfix�� 
		dataPtr = (char*)popStack(stack);
		temp[0] = *dataPtr;
		strcat(postfix, temp);
	}
	printf("���:");
	puts(postfix);

	destroyStack(stack);
	return 0;
}
*/