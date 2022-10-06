#include <stdio.h>
#define MAX 300

typedef int element;
typedef struct {
	element data[MAX];
	int top;
} Stack;

void initStack(Stack* s)
{
	s->top = -1;
}
int isFull(Stack* s)
{
	return s->top == MAX-1;
}
void push(Stack* s, element c)
{
	if(isFull(s)) {
		printf("Stack is Full");
		return;
	}
	s->data[++s->top] = c;
}
void pop(Stack* s, element c)
{
	switch(c) {
		case '+':
			s->data[s->top] = s->data[s->top] + s->data[--s->top];
			break;
		case '-':
			s->data[s->top] = s->data[s->top-1] - s->data[s->top--];
			break;
		case '*':
			s->data[s->top] = s->data[s->top] * s->data[--s->top];
			break;
		case '/':
			s->data[s->top] = s->data[s->top-1] / s->data[s->top--];
			break;
		default:
			return;
	}
}
int main()
{
	char expr[300];
	Stack s;
	fgets(expr, 300, stdin);
	for(int i=0; expr[i]!='\0'; i++) {
		if(expr[i]>='0' && expr[i]<='9')
			push(&s, expr[i]-'0');
		else pop(&s, expr[i]);
	}
	printf("%d", s.data[s.top]);
	return 0;
}

