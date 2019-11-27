#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cType.h>
#include "P5-16.h"
#include "linklistADT.h"

void printInstr(void);
LIST* buildList(void);
char getChoice(void);
void printList(LIST* list);
void search(LIST* list);

int cmpYear(void* pTear1, void* pYear2);


//�Ұ��� ����Ʈ�ϱ�
void printInstr(void) {
	printf("This program prints the Academy Award\nBest Picture of Year and its director.\n Your job id to enter the year; we will do the rest. Enjoy\n");
	return;
}
//�ؽ�Ʈ ������ �а�, ����Ʈ�� �ε��Ѵ�.
//����: yy \t 'pic' \t 'dir'
LIST* buildList(LIST* list) {

	short yearIn;
	int addResult;

	PICTURE* pPic;
	
		pPic = (PICTURE*)malloc(sizeof(PICTURE));
		if (!(pPic)) {
			printf("�޸𸮺���\n");
			exit(100);
		}

		printf("�⵵:");
		scanf("%hd", &yearIn);
		while (getchar() != '\n');
		pPic->year = yearIn;
		printf("������:");
		scanf("%s", pPic->picture);
		while (getchar() != '\n');
		printf("�۰���:");
		scanf(" %s", pPic->director);
		while (getchar() != '\n');
		addResult = addNode(list, pPic);

		if (addResult != 0) {//���Խ���
			if (addResult == -1) {
				printf("�����÷ο� ����\n");
				exit(120);
			}
			else {
				printf("�̹� �ִ� ���Դϴ�.");
			}
		}

	
	return list;
}
//�����ϱ�
LIST* removeData(LIST* list){
	short* year=(short*)malloc(sizeof(short));
	PICTURE** dataOutPtr=(PICTURE**)malloc(sizeof(PICTURE*));
	printf("������ �⵵:");
	scanf("%hd", year);
	while (getchar() != '\n');
	removeNode(list, year, dataOutPtr);
	return list;
}
//���� ó���ϱ�
void process(LIST* list) {
	char choice;
	do {
		choice = getChoice();
		switch (choice) {
		case 'I': buildList(list);//���ο� ������ ����
			break;
		case'R':removeData(list);
			break;
		case 'P':printList(list);//P�̸� ����Ʈ ����Ʈ�ϱ�
			break;
		case 'S':search(list);//���⵵ ã��
		case 'Q':break;//�׸��α�
		}
	} while (choice != 'Q');
	return;
}

//�����ϱ�
char getChoice(void) {
	char choice;
	bool valid;

	printf("========Menu=========\nHere are you choice:\nI:Insert the data\nR:Remove the data\nS: Search for a year\nP: Print all year\nQ:Quit\n\nEnter your choice:");
	do {
		
		scanf("%c", &choice);
		while (getchar() != '\n');
		choice = toupper(choice);
		switch (choice) {
		case 'I':
		case 'R':
		case 'S':
		case 'P':
		case 'Q': valid = true;
			break;
		default: valid = false;
			printf("�߸��Է��߾��. �ٽ� �������ּ���:");
			break;
		}
	} while (!valid);
	return choice;
}

//��ü ����Ʈ ����ϱ�
void printList(LIST* list) {
	PICTURE* pPic;

	if (listCount(list) == 0) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	}
	else {
		printf("\n BEST PICTURES LIST\n");
		traverse(list, 0, (void**)&pPic);
		do {
			printf("%hd %-40s %s\n", pPic->year, pPic->picture, pPic->director);
		} while (traverse(list, 1, (void**)&pPic));
	}
	printf("====================\n\n");
}

//�⵵�� ã��
void search(LIST* list) {
	short year;
	bool found;

	PICTURE pSrchArgu;
	PICTURE* pPic;

	printf("�⵵�� �Է����ּ���:");
	scanf("%hd", &year);
	pSrchArgu.year = year;

	found = searchList(list, &pSrchArgu, (void**)&pPic);

	if (found) {
		printf("%hd %-40s,%s\n", pPic->year, pPic->picture, pPic->director);
	}
	else {
		printf("�� �⵵�� �������� �ʽ��ϴ�");
	}
}

//�⵵ ���ϱ�
int cmpYear(void* pYear1, void* pYear2) {
	int result;
	short year1;
	short year2;

	year1 = ((PICTURE*)pYear1)->year;
	year2 = ((PICTURE*)pYear2)->year;

	if (year1 < year2) {
		result = -1;
	}
	else if (year1 > year2) {
		result = +1;
	}
	else {
		result = 0;
	}
	return result;
}
/*
-Testing Insert Logic
Insert a node into a null list.
Insert a node before the first data node.
Insert between two data nodes.
Insert after the last node.
-Testing Delete Logic
Delete to a null list.
Delete the first data node in the list.
Delete a node between two data nodes.
Delete the node at the end of the list.
Try to delete a node that doesn��t exist.
Try to delete a node whose key is less than the first data node��s key.
Try to delete a node whose key is greater than the last data node��s key.
Try to delete from an empty list.

*/


int main(void) {
	LIST* list;
	printInstr();
	list = createList(cmpYear);
	if (!list) {//����Ʈ �������н�
		printf("����Ʈ ��������\n");
		exit(100);
	}

	process(list);


	//���⼭ ���� ������ �ɸ�
	printList(list);

	

	printf("End Best Picture\n Hope you found your favorite!\n");
	destroyList(list);
	return 0;
}
