#include <stdio.h>
#define MAX 100
typedef char element;
typedef struct {
	element str[MAX];
	int top;
} Stack;

void initStack(Stack *s)
{
	s->top = -1;
}

int isFull(Stack *s)
{
	return s->top == MAX - 1;
}

int isEmpty(Stack *s)
{
	return s->top == -1;
}

void push(Stack* s, char c)
{
	if(isFull(s)) {
		printf("FULL");
		exit(0);
	}
	s->str[++s->top] = c;
}

char pop(Stack *s)
{
	if(isEmpty(s)) {
		printf("EMPTY");
		exit(0);
	}
	return s->str[s->top--];
}

int palindrome(char String[])
{
	Stack S;
	int i;
	char c;
	initStack(&S);
	for(i=0; String[i]!='\0'; i++)
		push(&S, String[i]);
	for(i=0; String[i]!='\0'; i++) {
		c = pop(&S);
		if(c!=String[i]) return 0;
	}
	return 1;
}

int main()
{
	char str[MAX];
	scanf("%s", str);
	if(palindrome(str)) printf("TRUE");
	else printf("FALSE");
	return 0;
}