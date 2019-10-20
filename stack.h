#define MAX_SIZE 10

#ifndef _STACK_H
#define _STACK_H
struct _stack {
	int data[MAX_SIZE];
	int top;
};
typedef struct _stack Stack;

Stack *mkStack();
void push(Stack *s, int item);
int pop(Stack *s);
int isEmpty(const Stack *s);
int isFull(const Stack *s);

void error(const char *msg);
#endif
