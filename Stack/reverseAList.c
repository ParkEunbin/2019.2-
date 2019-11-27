/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "stacksADT.h"

int main(void) {
	bool done = false;
	int* dataPtr;
	STACK* stack;
	//stack생성
	stack = createStack();

	while (!done) {
		dataPtr = (int*)malloc(sizeof(int));
		printf("숫자입력(종료시 ctrl+z): ");
		//EOF거나 스택이 full일 경우에 반복문을 탈출
		if(scanf("%d",dataPtr)== EOF || fullStack(stack)){
			done = true;
		}
		else {//그 외 정수가 들어오면 stack에 push해줌
			pushStack(stack, dataPtr);
		}
	}

	printf("==결과==\n");
	while (!emptyStack(stack)) {
		//stack의 원리로 나중에 들어온 데이터(top)먼저 출력 된다. stack이 빌때 까지 하면 stack안의 data가 모두 출력된 것 임.
		dataPtr = (int*)popStack(stack);
		printf("%3d\n", *dataPtr);
		free(dataPtr);
	}
	//사용후 stack파괴
	destroyStack(stack);
	return 0;
}
*/