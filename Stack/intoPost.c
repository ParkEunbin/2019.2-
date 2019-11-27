/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "stacksADT.h"

//연산자 우선순위 정해주기
int priority(char token) {
	if (token == '*' || token == '/')
		return 2;
	if (token == '+' || token == '-')
		return 1;
	return 0;
}
//연산자인지 판단
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

	printf("infix 형식의 식 입력: ");
	while ((token = getchar()) != '\n') {//문자 하나씩 검토
		if (token == '(') {//'('일 때 stack에 push
			dataPtr = (char*)malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else if (token == ')') {//')'일 때 pop한 데이터->dataPtr
			dataPtr = (char*)popStack(stack);
			while (*dataPtr != '(') {//'('아니면 temp에 넣고 postfix에 temp이어붙이기->dataPtr에 다음 문자 pop으로 넣기->반복
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)popStack(stack);
			}
		}
		else if (isOperator(token)) {//들어온 문자가 연산자일 때
			dataPtr = (char*)stackTop(stack);//dataPtr에 stack의 Top 데이터 넣기
			while (!emptyStack(stack) && priority(token) <= priority(*dataPtr)) {//stack이 안비었고, 들어온 연산자의 우선순위가 dataPtr이 가리키는 것의 우선순위보다 낮다면 반복
				dataPtr = (char*)popStack(stack);
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)malloc(sizeof(char));//stack안에 있는 데이터가 없거나, 안에 있는 연산자가 우선순위가 더 높을 때 까지 반복
			}
			dataPtr = (char *)malloc(sizeof(char));//그렇지 않을 경우엔 stack에 push
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else {//피연산자일 경우 바로 출력
			temp[0] = token;
			strcat(postfix, temp);
		}
	}//문자 검토 끝
	while (!emptyStack(stack)) {//stack이 비어있지 않다면 안의 데이터 pop하면서 postfix로 
		dataPtr = (char*)popStack(stack);
		temp[0] = *dataPtr;
		strcat(postfix, temp);
	}
	printf("결과:");
	puts(postfix);

	destroyStack(stack);
	return 0;
}
*/