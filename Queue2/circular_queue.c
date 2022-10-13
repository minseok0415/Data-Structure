#include <stdlib.h>
#include <stdio.h>
#define MAX_Q_SIZE 5

typedef int element;
typedef struct {
	int rear;
	int front;
	element data[MAX_Q_SIZE];
} Queue;

void initQueue(Queue* q)
{
	q->rear = q->front = 0;
}
int isEmpty(Queue* q)
{
	return q->rear == q->front;
}
int isFull(Queue* q)
{
	return q->front == (q->rear + 1) % MAX_Q_SIZE;
}
void enQueue(Queue* q, element item)
{
	if(isFull(q)) printf("큐가 포화상태입니다.\n");
	else q->data[++q->rear % MAX_Q_SIZE] = item;
}
element deQueue(Queue* q)
{
	if(isEmpty(q)) printf("큐는 공백상태입니다.\n");
	else return q->data[++q->front % MAX_Q_SIZE];
}
void printQueue(Queue* q)
{
	int i = q->front;
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (isEmpty(q)) {
		printf("큐는 공백상태입니다.\n");
		return;
	}
	do{
		i = (i+1) % MAX_Q_SIZE;
		printf("%d | ", q->data[i]);
	} while(i!=q->rear);
	printf("\n");
}

int main()
{
	Queue q;
	element item;
	initQueue(&q);
	printf("--데이터 추가 단계--\n");
	while (!isFull(&q)) {
		printf("정수를 입력하시오.");
		scanf("%d", &item);
		enQueue(&q, item);
		printQueue(&q);
	}
	printf("큐는 포화상태입니다.\n\n");
	printf("--데이터 삭제 단계--\n");
	while (!isEmpty(&q)){
		item = deQueue(&q);
		printf("꺼내진 정수 : %d\n", item);
		printQueue(&q);
	}
	return 0;
}