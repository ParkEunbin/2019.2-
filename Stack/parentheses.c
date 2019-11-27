/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "stacksADT.h"

const char closMiss[] = "���� ��ȣ�� �����ϴ�.";
const char openMiss[] = "���� ��ȣ�� �����ϴ�.";

int main(void) {
	STACK* stack;
	char token;
	char* dataPtr;
	char fileID[25];
	FILE* fpIn;
	int lineCount = 1;

	stack = createStack();
	printf("���� �̸� :");
	scanf("%s", fileID);
	//fopen�� ��ȯ���� FILE*��, �б� �������� ���� ����
	fpIn = fopen(fileID, "r");

	if (!fpIn) {//������ ������ ���� ��� fopen�� NULL�� �� ��ȯ, null�̸� ������ ���� ����
		printf("���� ���� ����\n");
		exit(100);
	}
	while ((token = fgetc(fpIn)) != EOF) {//fgetc:���ϳ����� �ѱ��ھ� ������->token�� ����, eof�� �ƴϸ� �ݺ� 
		if (token == '\n') {//newLine�϶� lineCout++
			lineCount++;
		}
		if (token == '(') {//���� ��ȣ �� �� stack�� �־���
			dataPtr = (char *)malloc(sizeof(char));
			pushStack(stack, dataPtr);
		}
		else {
			if (token == ')') {//���� ��ȣ �� �� 
				if (emptyStack(stack))
				{//���� ��ȣ�� �־���ϴµ� ����
					printf("%s %d ��° �� \n", openMiss, lineCount);
					return 1;
				}
				else//������ ���� ��ȣ�� ����� ������ pop
					popStack(stack);
			}
		}
	}
	if (!emptyStack(stack)) {//������ȣ �ڿ� ���� ��ȣ�� ���� ��
		printf("%s %d ��° ��\n", closMiss, lineCount);
		return 1;
	}
	destroyStack(stack);
	printf("��ȣ Ȯ�� �Ϸ�: %d���� ���� Ȯ��\n", lineCount);
	return 0;
}*/