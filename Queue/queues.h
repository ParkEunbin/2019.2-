//Queues ADT 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void * dataPtr;
	struct node* next;
}QUEUE_NODE;

typedef struct {
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int count;
}QUEUE;

//큐 생성하기
QUEUE* createQueue(void) {
	QUEUE* queue;
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue) {
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	}
	return queue;
}

//Enqueue-삽입
bool enqueue(QUEUE* queue, void* itemPtr) {
	QUEUE_NODE* newPtr;
	if (!(newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)))) {
		return false;
	}
	newPtr->dataPtr = itemPtr;
	newPtr->next = NULL;

	if (queue->count == 0)
		queue->front = newPtr;
	else
		queue->rear->next = newPtr;

	(queue->count)++;
	queue->rear = newPtr;
	return true;


	}

//Dequeue -삭제
bool dequeue(QUEUE* queue, void** itemPtr) {
	QUEUE_NODE* deleteLoc;
	if (!queue->count) {//큐 내의 데이터가 0개면
		return false;
	}
	*itemPtr = queue->front->dataPtr;
	deleteLoc = queue->front;
	if (queue->count == 1) {
		queue->rear = queue->front = NULL;
	}
	else {
		queue->front = queue->front->next;
	}
	(queue->count)--;
	free(deleteLoc);

	return true;
}

//Queue Front
bool queueFront(QUEUE* queue, void** itemPtr) {
	if (!queue->count)
		return false;
	else {
		*itemPtr = queue->front->dataPtr;
		return true;
	}
}

//Queue Rear
bool queueRear(QUEUE* queue, void** itemPtr) {
	if (!queue->count) {
		return true;
	}
	else {
		*itemPtr = queue->rear->dataPtr;
		return false;
	}
}

//Empty Queue
bool emptyQueue(QUEUE* queue) {
	return (queue->count == 0);
}

//Full Queue
bool fullQueue(QUEUE* queue) {
	QUEUE_NODE* temp;
	temp = (QUEUE_NODE*)malloc(sizeof(*(queue->rear)));
	if (temp) {
		free(temp);
		return true;
	}
	//heap 가 다차면 NULL값
	return false;
}

//Destory Queue
QUEUE* destoryQueue(QUEUE* queue) {
	QUEUE_NODE* deletePtr;
	if (queue) {
		while (queue->front != NULL) {
			free(queue->front->dataPtr);
			deletePtr = queue->front;
			queue->front = queue->front->next;
			free(deletePtr);
		}
		free(queue);
	}
	return NULL;
}

