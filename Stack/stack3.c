#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 20

typedef char element;
//스택 구조체 작성
typedef struct{
	element data[STACK_SIZE];
	int top;
} Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, element data);
element pop(Stack *s);

int main()
{
	int i;
 	Stack s;
	char str[20];
	initStack(&s);
	printf("문자열 입력 : ");
	scanf("%s", str);
	//문자열을 입력받아 거꾸로 출력
	for(i=0; i<strlen(str); i++) {
		push(&s, str[i]);
	}
	for(i=0; i<strlen(str); i++) {
		printf("%c", pop(&s));
	}
}

void initStack(Stack *s)
{
	 s->top = -1;
}
int isFull(Stack *s)
{
	return s->top == STACK_SIZE - 1;
}
int isEmpty(Stack *s)
{
	return s->top == -1;
}
void push(Stack *s, element c)
{
	if(isFull(s)) {
		printf("Stack is Full");
		exit(0);
	}
	 s->data[++s->top] = c;
}
element pop(Stack *s)
{
	if(isEmpty(s)) {
		printf("Stack is Empty");
		exit(0);
	}
	return s->data[s->top--];
}