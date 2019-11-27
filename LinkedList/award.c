/*
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
LIST* buildList(void) {
	FILE* fpData;
	LIST* list;

	short yearIn;
	int addResult;

	PICTURE* pPic;

	list = createList(cmpYear);
	

	if (!list) {//����Ʈ �������н�
		printf("����Ʈ ��������\n");
		exit(100);
	}

	fpData = fopen("pictures.txt", "r");//�б��������� ����
	
	if (!fpData) {//���� ���� ���н� 
		printf("Error opening input file\n");
		exit(110);
	}
	//���� ���� ������
	while (fscanf(fpData, " %hd", &yearIn) == 1) {//16��Ʈ (short)������ ������//������ ��ȯ 1
		
		pPic = (PICTURE*)malloc(sizeof(PICTURE));
		if (!(pPic)) {
			printf("�޸𸮺���\n");
			exit(100);
		}
		//pPic �޸� �Ҵ� ������
		pPic->year = yearIn;
		//tap�� "���ֱ�
		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');
		fscanf(fpData, " %*c", pPic->picture);
		printf(" %*c", pPic->picture);
		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');
		fscanf(fpData, " %40[^\"],%*c", pPic->director);

		//insert into list
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

		while (fgetc(fpData) != '\n');
		
	}
	printf("ff");
	return list;
}
//���� ó���ϱ�
void process(LIST* list) {
	char choice;
	do {
		choice = getChoice();
		switch (choice) {
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

	printf("========Menu=========\nHere are you choice:\n   S: Search for a year\n   P: Print all year\n   Q:Quit\n\nEnter your choice:");
	do {
		scanf("%c", &choice);
		choice = toupper(choice);
		switch (choice) {
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


int main(void) {
	LIST* list;
	printInstr();
	list = buildList();
	//���⼭ ���� ������ �ɸ�
	printList(list);

	process(list);

	printf("End Best Picture\n Hope you found your favorite!\n");

	return 0;
}
*/