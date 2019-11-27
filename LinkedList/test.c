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


//소개글 프린트하기
void printInstr(void) {
	printf("This program prints the Academy Award\nBest Picture of Year and its director.\n Your job id to enter the year; we will do the rest. Enjoy\n");
	return;
}
//텍스트 파일을 읽고, 리스트로 로드한다.
//파일: yy \t 'pic' \t 'dir'
LIST* buildList(LIST* list) {

	short yearIn;
	int addResult;

	PICTURE* pPic;
	
		pPic = (PICTURE*)malloc(sizeof(PICTURE));
		if (!(pPic)) {
			printf("메모리부족\n");
			exit(100);
		}

		printf("년도:");
		scanf("%hd", &yearIn);
		while (getchar() != '\n');
		pPic->year = yearIn;
		printf("사진명:");
		scanf("%s", pPic->picture);
		while (getchar() != '\n');
		printf("작가명:");
		scanf(" %s", pPic->director);
		while (getchar() != '\n');
		addResult = addNode(list, pPic);

		if (addResult != 0) {//삽입실패
			if (addResult == -1) {
				printf("오버플로우 됬어요\n");
				exit(120);
			}
			else {
				printf("이미 있는 값입니다.");
			}
		}

	
	return list;
}
//삭제하기
LIST* removeData(LIST* list){
	short* year=(short*)malloc(sizeof(short));
	PICTURE** dataOutPtr=(PICTURE**)malloc(sizeof(PICTURE*));
	printf("삭제할 년도:");
	scanf("%hd", year);
	while (getchar() != '\n');
	removeNode(list, year, dataOutPtr);
	return list;
}
//과정 처리하기
void process(LIST* list) {
	char choice;
	do {
		choice = getChoice();
		switch (choice) {
		case 'I': buildList(list);//새로운 데이터 삽입
			break;
		case'R':removeData(list);
			break;
		case 'P':printList(list);//P이면 리스트 프린트하기
			break;
		case 'S':search(list);//모든년도 찾기
		case 'Q':break;//그만두기
		}
	} while (choice != 'Q');
	return;
}

//선택하기
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
			printf("잘못입력했어요. 다시 선택해주세요:");
			break;
		}
	} while (!valid);
	return choice;
}

//전체 리스트 출력하기
void printList(LIST* list) {
	PICTURE* pPic;

	if (listCount(list) == 0) {
		printf("리스트가 비어있습니다.\n");
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

//년도로 찾기
void search(LIST* list) {
	short year;
	bool found;

	PICTURE pSrchArgu;
	PICTURE* pPic;

	printf("년도를 입력해주세요:");
	scanf("%hd", &year);
	pSrchArgu.year = year;

	found = searchList(list, &pSrchArgu, (void**)&pPic);

	if (found) {
		printf("%hd %-40s,%s\n", pPic->year, pPic->picture, pPic->director);
	}
	else {
		printf("본 년도는 존재하지 않습니다");
	}
}

//년도 비교하기
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
Try to delete a node that doesn’t exist.
Try to delete a node whose key is less than the first data node’s key.
Try to delete a node whose key is greater than the last data node’s key.
Try to delete from an empty list.

*/


int main(void) {
	LIST* list;
	printInstr();
	list = createList(cmpYear);
	if (!list) {//리스트 생성실패시
		printf("리스트 생성실패\n");
		exit(100);
	}

	process(list);


	//여기서 무한 루프가 걸림
	printList(list);

	

	printf("End Best Picture\n Hope you found your favorite!\n");
	destroyList(list);
	return 0;
}
