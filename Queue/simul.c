/*
세탁소 프로그램
운영 가정: 10:00 ~ 21:00 까지 운영
		세탁이 완료되면 고객이 바로 찾아간다.->바로 돈이 들어온다.
		세탁기 규모의 최대치가 되면 세탁기를 돌린다.
		세탁기 4개는 동시에 운영이 가능하다.
		세탁기가 돌아가는 중에는 옷을 넣을 수 없다.
		손님은 3분에 한명씩 온다고 가정.
		손님은 한번에 1벌의 옷을 들고 온다고 가정.

세탁기 규모: 티셔츠 10개용 1대-1시간, 이불5개용 1대-1시간, 패딩8개용 1대-2시간
			각 대기 바구니 있음
				
가격: 1티셔츠:4000원 , 2이불:20000원 , 3패딩:80000원 
*/

/*
1.손님이 온경우-> 옷2벌(랜덤)을 맡긴다->ex)"손님1번: 티셔츠을 맡깁니다."(enqueue)
2.큐(세탁기)의 길이가 최대치 일때 세탁기를 돌린다
3.시간이 다되면 세탁완료->가져감(dequeue)->"~번 손님이 티셔츠을 가져갑니다."->가격측정
4.종료시간이 되었을 때 옷이 남아있다면 다음날 한다.
*/

/*


*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queues.h"

int sum = 0;//총수입

//손님이 무엇을 맡길지
void newcoustumer(QUEUE* rea_tshirt, QUEUE* rea_blanket,QUEUE* rea_padding,int* dataPtr) {
	int *numdata =(int*)malloc(sizeof(int));
	*numdata = *dataPtr;
	int given = (rand() % 3 + 1);
	switch (given)
	{
	case 1: enqueue(rea_tshirt, numdata);
		printf("손님 %d번이 티셔츠를 맡겼습니다.\n",(*numdata));
		break;
	case 2: enqueue(rea_blanket, numdata);
		printf("손님 %d번이 이불을 맡겼습니다.\n", (*numdata));
		break;
	default:enqueue(rea_padding, numdata);
		printf("손님 %d번이 패딩을 맡겼습니다.\n", (*numdata));
		break;
	}
	return;
}
//옷 찾아가기
void getclothes(QUEUE* queue, int flag) {
	
	while (!emptyQueue(queue)) {
		int **a = malloc(sizeof(int*));
		if (flag == 0) {//티셔츠
			dequeue(queue, a);
			printf("%d번 손님이 티셔츠를 찾아갔습니다.\n ", **a);
			sum += 4000;
		}
		else if (flag == 1) {//이불
			dequeue(queue, a);
			printf("%d번 손님이 이불을 찾아갔습니다.\n ", **a);
			sum += 20000;
		}
		else{ //패딩
			dequeue(queue, a);
			printf("%d번 손님이 패딩을 찾아갔습니다.\n ", **a);
			sum += 8000;
		}
		free(a);
	}
}

/*
void getclothes(QUEUE* tshirt, QUEUE* blanket, QUEUE* padding,QUEUE* queue) {
	int ** a=(int**)malloc(sizeof(int*));

	while (!emptyQueue(queue)) {
		//큐에 데이터가 있다면 dataPtr이 dequeue된 데이터를 가리키도록
		
		if (queue == tshirt) {//포인터가 같다면
			printf("%d번 손님이 티셔츠를 찾아갔습니다.\n ", *((int*)(queue->front->dataPtr)));
			dequeue(queue, a);
			sum += 4000;
		}
		else if(queue == blanket) {
			printf("%d번 손님이 이불을 찾아갔습니다. \n", *((int*)(queue->front->dataPtr)));
			dequeue(queue, a);
			sum += 20000;
		}
		else {
			printf("%d번 손님이 패딩을 찾아갔습니다. \n", *((int*)(queue->front->dataPtr)));
			dequeue(queue, a);
			sum += 8000;
		}
		
	}
	return;
}
*/
//대기 바구니->세탁기
void startclean(QUEUE* rea, QUEUE* clean) {
	int *dataPtr;
	dequeue(rea, (void*)&dataPtr);
	enqueue(clean, dataPtr);
	//printf("옮기기 성공!\n");
}

int main(void) {
	QUEUE* tshirt;//세탁기
	QUEUE* blanket;
	QUEUE* padding;
	QUEUE* rea_tshirt;//대기 바구니
	QUEUE* rea_blanket;
	QUEUE* rea_padding;

	int t_time = 0;
	int b_time = 0;
	int p_time = 0;

	printf("====open=====\n");

	tshirt = createQueue();
	blanket = createQueue();
	padding = createQueue();
	rea_tshirt = createQueue();
	rea_padding = createQueue();
	rea_blanket = createQueue();

	
	int daytime = 0;//10시 시작 9시 종료:60*11=660 time까지
	int num = 1;
	int * dataPtr=&num;//손님의 순서

	for (daytime = 1; daytime <= 660; daytime++) {

		if (daytime % 4 == 0) {//손님이 왔어요!
			newcoustumer(rea_tshirt, rea_blanket, rea_padding,dataPtr );
			(*dataPtr)++;
		}
		//대기바구니에 옷이 찼으면 세탁기돌리기
	
		//printf("%d", rea_tshirt->count);
		if (((rea_tshirt->count) >= 10) && ((tshirt->count) == 0)) {
			while((tshirt->count)<10) {
				startclean(rea_tshirt, tshirt);
				//printf("%d\n", rea_tshirt->count);
				//printf("%d\n", tshirt->count);
			}
		}
		if (((rea_blanket->count) >= 5) && ((blanket->count) == 0)) {
			while((blanket->count)<5) {
				startclean(rea_blanket, blanket);
			}
		}
		if (((rea_padding->count) >= 8) && ((padding->count) == 0)) {
			while((padding->count)<8) {
				startclean(rea_padding, padding);
			}
		}

		//세탁 중
		if ((tshirt->count) == 10) {
			t_time++;
		}
		if ((blanket->count) == 5) {
			b_time++;
		}
		if ((padding->count) == 8) {
			p_time++;
		}

		//세탁완료
		if (t_time == 60) {
			getclothes(tshirt,0);
			t_time = 0;
		}
		if (b_time == 60) {
			getclothes(blanket,1);
			b_time = 0;
		}
		if (p_time == 60) {
			getclothes(padding,2);
			p_time = 0;
		}

	}//for


	printf("총 수입: %d 원\n", sum);
	printf("대기중인 옷(다음날 진행): 티셔츠:%d벌/ 이불:%d벌/ 패딩:%d벌\n", rea_tshirt->count, rea_blanket->count, rea_padding->count);
	
	return 0;
}