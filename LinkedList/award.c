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


//소개글 프린트하기
void printInstr(void) {
	printf("This program prints the Academy Award\nBest Picture of Year and its director.\n Your job id to enter the year; we will do the rest. Enjoy\n");
	return;
}
//텍스트 파일을 읽고, 리스트로 로드한다.
//파일: yy \t 'pic' \t 'dir'
LIST* buildList(void) {
	FILE* fpData;
	LIST* list;

	short yearIn;
	int addResult;

	PICTURE* pPic;

	list = createList(cmpYear);
	

	if (!list) {//리스트 생성실패시
		printf("리스트 생성실패\n");
		exit(100);
	}

	fpData = fopen("pictures.txt", "r");//읽기형식으로 열기
	
	if (!fpData) {//파일 오픈 실패시 
		printf("Error opening input file\n");
		exit(110);
	}
	//파일 오픈 성공시
	while (fscanf(fpData, " %hd", &yearIn) == 1) {//16비트 (short)정수형 데이터//성공시 반환 1
		
		pPic = (PICTURE*)malloc(sizeof(PICTURE));
		if (!(pPic)) {
			printf("메모리부족\n");
			exit(100);
		}
		//pPic 메모리 할당 성공시
		pPic->year = yearIn;
		//tap과 "없애기
		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');
		fscanf(fpData, " %*c", pPic->picture);
		printf(" %*c", pPic->picture);
		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');
		fscanf(fpData, " %40[^\"],%*c", pPic->director);

		//insert into list
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

		while (fgetc(fpData) != '\n');
		
	}
	printf("ff");
	return list;
}
//과정 처리하기
void process(LIST* list) {
	char choice;
	do {
		choice = getChoice();
		switch (choice) {
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


int main(void) {
	LIST* list;
	printInstr();
	list = buildList();
	//여기서 무한 루프가 걸림
	printList(list);

	process(list);

	printf("End Best Picture\n Hope you found your favorite!\n");

	return 0;
}
*/