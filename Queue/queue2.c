#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element* data;
	int front;
	int rear;
	int size;
} Queue;

Queue *initQueue(int n);
int isFull(Queue *q);
void enQueue(Queue *q, element data);
int isEmpty(Queue *q);
element deQueue(Queue *q);
void destroyQueue(Queue * q);
void printAll(Queue *q);

int main()
{
	Queue *q;
	element data;
	q = initQueue(5);
	enQueue(q, 10);	printAll(q);
	enQueue(q, 20);	printAll(q);
	enQueue(q, 30);	printAll(q);
	enQueue(q, 40);	printAll(q);
	enQueue(q, 50);	printAll(q);
	data = deQueue(q);	printAll(q);
	enQueue(q, 60);	printAll(q);
	destroyQueue(q);
	return 0;
}
Queue* initQueue(int n)
{
	Queue *temp = (Queue*)malloc(sizeof(Queue));
	temp -> size = n;
	temp -> rear = -1;
	temp -> front = -1;
	temp -> data = (element*)malloc(sizeof(element)*n);
	return temp;
}
int isFull(Queue *q)
{
	return q->rear == q->size-1;
}
void enQueue(Queue *q, element data)
{
	if(isFull(q))
		printf("Queue is full\n");
	q->data[++q->rear] = data;
}
int isEmpty(Queue *q)
{
	return q->rear == q->front;
}
element deQueue(Queue *q)
{
	if(isEmpty(q)) {
		printf("Queue is empty\n");
		return 0;
	}
	return q->data[++q->front];
}
void printAll(Queue *q)
{
	for(int i=0; i<q->size; i++)
		if(i<=q->front || i>q->rear) printf(" | ");
		else printf("%d | ", q->data[i]);
	printf("\n");
}
void destroyQueue(Queue * q)
{
	free(q->data);
	free(q);
}