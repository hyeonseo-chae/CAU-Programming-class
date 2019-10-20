#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void error (const char *msg){
	printf("����: %s: ");
	printf("���α׷��� �����մϴ�.\n");
	exit(-1); 
}

Stack *mkStack(){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->top = 0;
	return s;
	
}

void push (Stack *s, int item){
	if(isFull(s)) error("���� ������ ���ڶ�.");
	s->data[s->top++] = item;
}

int pop(Stack *s){
	if(isEmpty(s)) error("������ �����.");
	return s->data[--s->top];
	
}

int isEmpty(const Stack *s){
	if(s->top == 0) return 1;
	else return 0;
}

int isFull(const Stack *s){
	if(s->top==MAX_SIZE) return 1;
	else return 0;
}
