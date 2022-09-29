#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100

typedef int element; //int를 element로 재정의
element	stack[MAX_STACK_SIZE]; //1차원 배열로 스택 정의
//전역변수로 스택 선언
int top = -1;

bool isEmpty()
{
	return top == -1;
}
bool isFull()
{
	return top == MAX_STACK_SIZE - 1;
}	 
void push(element item)
{
	if(isFull()) return;
	stack[++top] = item;
}
element pop() //반환후 제거
{
	if(isEmpty()) return 0;
	element temp = stack[top--];
	return temp;
}
element peek() //반환만
{
	return stack[top];
}
int main()
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", peek());
	printf("%d\n", pop());
	return 0;
}