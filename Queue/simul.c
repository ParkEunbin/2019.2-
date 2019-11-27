/*
��Ź�� ���α׷�
� ����: 10:00 ~ 21:00 ���� �
		��Ź�� �Ϸ�Ǹ� ���� �ٷ� ã�ư���.->�ٷ� ���� ���´�.
		��Ź�� �Ը��� �ִ�ġ�� �Ǹ� ��Ź�⸦ ������.
		��Ź�� 4���� ���ÿ� ��� �����ϴ�.
		��Ź�Ⱑ ���ư��� �߿��� ���� ���� �� ����.
		�մ��� 3�п� �Ѹ� �´ٰ� ����.
		�մ��� �ѹ��� 1���� ���� ��� �´ٰ� ����.

��Ź�� �Ը�: Ƽ���� 10���� 1��-1�ð�, �̺�5���� 1��-1�ð�, �е�8���� 1��-2�ð�
			�� ��� �ٱ��� ����
				
����: 1Ƽ����:4000�� , 2�̺�:20000�� , 3�е�:80000�� 
*/

/*
1.�մ��� �°��-> ��2��(����)�� �ñ��->ex)"�մ�1��: Ƽ������ �ñ�ϴ�."(enqueue)
2.ť(��Ź��)�� ���̰� �ִ�ġ �϶� ��Ź�⸦ ������
3.�ð��� �ٵǸ� ��Ź�Ϸ�->������(dequeue)->"~�� �մ��� Ƽ������ �������ϴ�."->��������
4.����ð��� �Ǿ��� �� ���� �����ִٸ� ������ �Ѵ�.
*/

/*


*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queues.h"

int sum = 0;//�Ѽ���

//�մ��� ������ �ñ���
void newcoustumer(QUEUE* rea_tshirt, QUEUE* rea_blanket,QUEUE* rea_padding,int* dataPtr) {
	int *numdata =(int*)malloc(sizeof(int));
	*numdata = *dataPtr;
	int given = (rand() % 3 + 1);
	switch (given)
	{
	case 1: enqueue(rea_tshirt, numdata);
		printf("�մ� %d���� Ƽ������ �ð���ϴ�.\n",(*numdata));
		break;
	case 2: enqueue(rea_blanket, numdata);
		printf("�մ� %d���� �̺��� �ð���ϴ�.\n", (*numdata));
		break;
	default:enqueue(rea_padding, numdata);
		printf("�մ� %d���� �е��� �ð���ϴ�.\n", (*numdata));
		break;
	}
	return;
}
//�� ã�ư���
void getclothes(QUEUE* queue, int flag) {
	
	while (!emptyQueue(queue)) {
		int **a = malloc(sizeof(int*));
		if (flag == 0) {//Ƽ����
			dequeue(queue, a);
			printf("%d�� �մ��� Ƽ������ ã�ư����ϴ�.\n ", **a);
			sum += 4000;
		}
		else if (flag == 1) {//�̺�
			dequeue(queue, a);
			printf("%d�� �մ��� �̺��� ã�ư����ϴ�.\n ", **a);
			sum += 20000;
		}
		else{ //�е�
			dequeue(queue, a);
			printf("%d�� �մ��� �е��� ã�ư����ϴ�.\n ", **a);
			sum += 8000;
		}
		free(a);
	}
}

/*
void getclothes(QUEUE* tshirt, QUEUE* blanket, QUEUE* padding,QUEUE* queue) {
	int ** a=(int**)malloc(sizeof(int*));

	while (!emptyQueue(queue)) {
		//ť�� �����Ͱ� �ִٸ� dataPtr�� dequeue�� �����͸� ����Ű����
		
		if (queue == tshirt) {//�����Ͱ� ���ٸ�
			printf("%d�� �մ��� Ƽ������ ã�ư����ϴ�.\n ", *((int*)(queue->front->dataPtr)));
			dequeue(queue, a);
			sum += 4000;
		}
		else if(queue == blanket) {
			printf("%d�� �մ��� �̺��� ã�ư����ϴ�. \n", *((int*)(queue->front->dataPtr)));
			dequeue(queue, a);
			sum += 20000;
		}
		else {
			printf("%d�� �մ��� �е��� ã�ư����ϴ�. \n", *((int*)(queue->front->dataPtr)));
			dequeue(queue, a);
			sum += 8000;
		}
		
	}
	return;
}
*/
//��� �ٱ���->��Ź��
void startclean(QUEUE* rea, QUEUE* clean) {
	int *dataPtr;
	dequeue(rea, (void*)&dataPtr);
	enqueue(clean, dataPtr);
	//printf("�ű�� ����!\n");
}

int main(void) {
	QUEUE* tshirt;//��Ź��
	QUEUE* blanket;
	QUEUE* padding;
	QUEUE* rea_tshirt;//��� �ٱ���
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

	
	int daytime = 0;//10�� ���� 9�� ����:60*11=660 time����
	int num = 1;
	int * dataPtr=&num;//�մ��� ����

	for (daytime = 1; daytime <= 660; daytime++) {

		if (daytime % 4 == 0) {//�մ��� �Ծ��!
			newcoustumer(rea_tshirt, rea_blanket, rea_padding,dataPtr );
			(*dataPtr)++;
		}
		//���ٱ��Ͽ� ���� á���� ��Ź�⵹����
	
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

		//��Ź ��
		if ((tshirt->count) == 10) {
			t_time++;
		}
		if ((blanket->count) == 5) {
			b_time++;
		}
		if ((padding->count) == 8) {
			p_time++;
		}

		//��Ź�Ϸ�
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


	printf("�� ����: %d ��\n", sum);
	printf("������� ��(������ ����): Ƽ����:%d��/ �̺�:%d��/ �е�:%d��\n", rea_tshirt->count, rea_blanket->count, rea_padding->count);
	
	return 0;
}