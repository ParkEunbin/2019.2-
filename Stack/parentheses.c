/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "stacksADT.h"

const char closMiss[] = "닫힌 괄호가 없습니다.";
const char openMiss[] = "열린 괄호가 없습니다.";

int main(void) {
	STACK* stack;
	char token;
	char* dataPtr;
	char fileID[25];
	FILE* fpIn;
	int lineCount = 1;

	stack = createStack();
	printf("파일 이름 :");
	scanf("%s", fileID);
	//fopen의 반환형은 FILE*형, 읽기 형식으로 파일 열기
	fpIn = fopen(fileID, "r");

	if (!fpIn) {//파일이 열리지 않은 경우 fopen은 NULL값 을 반환, null이면 오류를 띄우고 종료
		printf("파일 열기 오류\n");
		exit(100);
	}
	while ((token = fgetc(fpIn)) != EOF) {//fgetc:파일내용을 한글자씩 가져옴->token에 저장, eof가 아니면 반복 
		if (token == '\n') {//newLine일때 lineCout++
			lineCount++;
		}
		if (token == '(') {//열린 괄호 일 때 stack에 넣어줌
			dataPtr = (char *)malloc(sizeof(char));
			pushStack(stack, dataPtr);
		}
		else {
			if (token == ')') {//닫힌 괄호 일 때 
				if (emptyStack(stack))
				{//열린 괄호가 있어야하는데 없음
					printf("%s %d 번째 줄 \n", openMiss, lineCount);
					return 1;
				}
				else//열리고 닫힌 괄호가 제대로 있으면 pop
					popStack(stack);
			}
		}
	}
	if (!emptyStack(stack)) {//열린괄호 뒤에 닫힌 괄호가 없을 때
		printf("%s %d 번째 줄\n", closMiss, lineCount);
		return 1;
	}
	destroyStack(stack);
	printf("괄호 확인 완료: %d개의 문장 확인\n", lineCount);
	return 0;
}*/