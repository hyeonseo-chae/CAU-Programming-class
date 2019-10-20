#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void error (const char *msg){
	printf("오류: %s: ");
	printf("프로그램을 종료합니다.\n");
	exit(-1); 
}

Stack *mkStack(){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->top = 0;
	return s;
	
}

void push (Stack *s, int item){
	if(isFull(s)) error("스택 공간이 모자람.");
	s->data[s->top++] = item;
}

int pop(Stack *s){
	if(isEmpty(s)) error("스택이 비었음.");
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
