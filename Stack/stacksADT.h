#ifndef STACKSADT_H
#define STACKSADT_H

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//노드(데이터를 가르키는 포인터 + 뒤 노드를 가르키는 포인터)
typedef struct node {
	void * dataPtr;
	struct node* link;
}STACK_NODE;

//스택
typedef struct {
	int count;
	STACK_NODE* top;
}STACK;

//비어있는 스택만들기 ,matadata만들기
STACK* createStack(void) {
	STACK * stack;
	stack = (STACK*) malloc (sizeof(STACK));
	if (stack) {//stack이 존재하면 실행, 존재하지않으면(NULL값이면) 실행이 안됨
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}

//push : 데이터를 넣어줌
bool pushStack(STACK* stack, void* dataInPtr) {
	STACK_NODE * newPtr;
	newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	
	if (!newPtr) {//null이 아니면 실행!
		return false;
	}
	//Null일 경우엔 newPtr의 dataPtr에 입력할 데이터를 넣고, newPtr의 link에 기존의 top의 주소값을 담는다. 이제 stack의 top은 newPtr이 되게한다.
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;

	return true;
}

//pop : 스택 top의 데이터를 없앤다
void * popStack(STACK* stack) {
	void * dataOutPtr;
	STACK_NODE* temp;

	if (stack->count == 0) {//스택이 비어있는 경우
		dataOutPtr = NULL;
	}
	else {//data가 있는 경우
		temp = stack->top;//top의 node정보를 담아둠
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;//top에는 그 다음의 주소값을 줌
		free(temp);
		(stack->count)--;
	}
	return dataOutPtr;
}

//top데이터 찾기
void* stackTop(STACK* stack) {
	if (stack->count == 0)
		return NULL;
	else
		return stack->top->dataPtr;
}

//스택 비엇는지 확인
bool emptyStack(STACK* stack) {
	return (stack->count == 0);//0이면 비었다!true
}

//스택이 다 찾는지 확인->true:메모리가 가득참
bool fullStack(STACK* stack) {
	STACK_NODE * temp;
	//임시로 stack의 top을 할당-> 정상적으로 할당되면 0이외의 주소를 받음0->true
	//null이 반환->false->Full이다!
	if ((temp = (STACK_NODE*)malloc(sizeof(*(stack->top))))) {
		free(temp);
		return false;
	}
	return true;
}

//갯수세기
int stackCount(STACK* stack) {
	return stack->count;
}

//스택 파괴하기
STACK* destroyStack(STACK* stack) {
	STACK_NODE* temp;

	if (stack) {
		while (stack->top != NULL) {//남은 데이터 삭제하기
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