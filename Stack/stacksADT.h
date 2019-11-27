#ifndef STACKSADT_H
#define STACKSADT_H

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//���(�����͸� ����Ű�� ������ + �� ��带 ����Ű�� ������)
typedef struct node {
	void * dataPtr;
	struct node* link;
}STACK_NODE;

//����
typedef struct {
	int count;
	STACK_NODE* top;
}STACK;

//����ִ� ���ø���� ,matadata�����
STACK* createStack(void) {
	STACK * stack;
	stack = (STACK*) malloc (sizeof(STACK));
	if (stack) {//stack�� �����ϸ� ����, ��������������(NULL���̸�) ������ �ȵ�
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}

//push : �����͸� �־���
bool pushStack(STACK* stack, void* dataInPtr) {
	STACK_NODE * newPtr;
	newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	
	if (!newPtr) {//null�� �ƴϸ� ����!
		return false;
	}
	//Null�� ��쿣 newPtr�� dataPtr�� �Է��� �����͸� �ְ�, newPtr�� link�� ������ top�� �ּҰ��� ��´�. ���� stack�� top�� newPtr�� �ǰ��Ѵ�.
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;

	return true;
}

//pop : ���� top�� �����͸� ���ش�
void * popStack(STACK* stack) {
	void * dataOutPtr;
	STACK_NODE* temp;

	if (stack->count == 0) {//������ ����ִ� ���
		dataOutPtr = NULL;
	}
	else {//data�� �ִ� ���
		temp = stack->top;//top�� node������ ��Ƶ�
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;//top���� �� ������ �ּҰ��� ��
		free(temp);
		(stack->count)--;
	}
	return dataOutPtr;
}

//top������ ã��
void* stackTop(STACK* stack) {
	if (stack->count == 0)
		return NULL;
	else
		return stack->top->dataPtr;
}

//���� ������� Ȯ��
bool emptyStack(STACK* stack) {
	return (stack->count == 0);//0�̸� �����!true
}

//������ �� ã���� Ȯ��->true:�޸𸮰� ������
bool fullStack(STACK* stack) {
	STACK_NODE * temp;
	//�ӽ÷� stack�� top�� �Ҵ�-> ���������� �Ҵ�Ǹ� 0�̿��� �ּҸ� ����0->true
	//null�� ��ȯ->false->Full�̴�!
	if ((temp = (STACK_NODE*)malloc(sizeof(*(stack->top))))) {
		free(temp);
		return false;
	}
	return true;
}

//��������
int stackCount(STACK* stack) {
	return stack->count;
}

//���� �ı��ϱ�
STACK* destroyStack(STACK* stack) {
	STACK_NODE* temp;

	if (stack) {
		while (stack->top != NULL) {//���� ������ �����ϱ�
			free(stack->top->dataPtr);
			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
		}
		free(stack);
	}
	return NULL;
}


#endif