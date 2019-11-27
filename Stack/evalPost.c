#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stacksADT.h"
//연산자인지 판단
bool isOperator(char token) {
	if (token == '*' || token == '/' || token == '+' || token == '-')
		return true;
	return false;
}
//연산자에 따라 계산
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

	printf("식 입력: ");
	while ((token = getchar()) != '\n') {//한문자씩 받아오기
		if (!isOperator(token)) {//연산자가 아닐 때, stack에 push
			dataPtr = (int*)malloc(sizeof(int));
			*dataPtr = atoi(&token);//문자열 정수변환
			pushStack(stack, dataPtr);
		}
		else {//연산자일 때,stack에 쌓인 데이터 두개pop해서 연산자로 계산-> 계산값 다시 push
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
	//stack에 남은 값이 최종 결과
	dataPtr = (int*)popStack(stack);
	value = *dataPtr;
	printf("결과값: %d \n", value);

	destroyStack(stack);
	return 0;
}