#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef char element;

typedef struct {
	element data[STACK_SIZE];
	int top;
} Stack;

int checkTest(char expr[]);
void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, element data);
element pop(Stack *s);

int main()
{
	int i;
	Stack s;
	char expr[20];
	scanf("%s", expr);
	printf("괄호포함 수식 입력 : ");
	if (checkTest(expr)) printf("성공");
	else printf("실패");
	return 0;
	
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
int checkTest(char expr[])
{
	int i;
	Stack s;
	initStack(&s);
	char ch, open_ch;
  for(i=0; expr[i]!='\0'; i++) {
		ch = expr[i];
		switch(ch) {
			case '(': 
			case '[':
			case '{':
				push(&s, ch);
				break;
			case ')':
			case ']':
			case '}':	
				if (isEmpty(&s)) return 0;
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) return 0;
				break;
		}
	}
	if(!isEmpty(&s)) return 0;
	return 1;
}
