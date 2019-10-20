// 함수를 활용하여 펙토리얼을 구하는 프로그램을 만드시오
/*
include <stdio.h>
int factorial(int n);
int main(){
	int n;
	printf("펙토리얼을 구하고 싶은 숫자를 입력하시오.: ");
	scanf("%d",&n);
	printf("%d의 펙토리얼은 %d입니다.",n,factorial(n));
	return 0;
}

int factorial(int n){
	int fac = 1;
	if(n==0){
		return fac;
	}
	else{
		fac = factorial(n-1)*n;
		return fac;
	}
}
*/

/*
// 랜덤 숫자 출력하기 5개씩
#include <stdio.h>
#include <stdlib.h> //srand 와 rand 함수
#include <time.h> // time 함수

int main () {
	int i;
	srand((unsigned int)time(NULL)); //time이 반환한 calendar time를 srand의 인수로 전달
	for (i = 0; i<5;i++){
		printf("%d ",rand()%10);

	}
	return 0;
} */

// 두 수를 Swap 하는 프로그램을 함수를 만들어서 제작해라
/*
#include<stdio.h>
void swap(int *a, int *b);

int main(){
	int A=5,B=2;
	swap(&A,&B);
	printf("%d %d",A,B);
	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
*/

/*
문자열 관련 라이브러리 함수
strlen() => 문자열 길이 리턴
strcpy(1,2) => 문자열 2를 1로 복사한다.
strcat(1,2) => 문자열 2를 1에 접합한다.
strcmp(1,2) => 문자열 1과 2를 비교한다. => 문자열이 같으면 0리턴, 아니면 ascii 코드값 차이 리턴
strchr(1,ch) => 문자열 1에서 ch가 처음 나타난 위치를 리턴한다.
strstr(1,2) => 문자열 1에서 2가 처음나타난 위치를 리턴한다.
strtok(1,2) => 문자열 1에서 2내의 문자를 토큰으로 하여 다음 토큰의 포인터를 리턴한다.
atoi(1) => 문자열 1을 int 정수로 변화하여 리턴한다.
atol(1) => 문자열 1을 long int 정수로 변환하여 리턴한다.
atof(1) => 문자열 double 부동수수점을 수로 변환하여 리턴한다.
*/


/*
구조체 정의

struct student{
char name[20];
int stud_id;
};

구조체 변수 선언
struct student s1, s2;

형정의(typedef)를 사용해 구조체 자료형 이름 정의
typedef struct{
char name[20];
int stud_id;
} STUD;

STUD s1. s2;

구조체 정의시 변수와 함께 선언
struct student{
char name[20];
int stud_id;
}s1,s2;

구조체 이름을 붙이지 않고 구조체와 변수 동시 선언
struct{
char name[20];
int stud_id;
}s1,s2;

*/

//구조체 & 포인터 복합 사용

/*#include<stdio.h>
#include <string.h>
#define MAX_STR 100

typedef struct struct_date {
int year, month, day;
} Sdate;

typedef struct struct_person {
char name[MAX_STR];
char telephone[MAX_STR];
Sdate birthday;
} Sperson;

void main(){

	Sperson a1;
	input(&a1);
	check(&a1);
	return 0;
}

void input(Sperson *a1){
	printf("Enter the name:");
	gets(a1->name);
	printf("Enter the phone number:");
	gets(a1->telephone);
    printf("Enter the birthday (yyyymmdd):"); //생년월일 8자리만 인식 가 능
	scanf("%4d",&a1->birthday.year);
	scanf("%2d",&a1->birthday.month);
	scanf("%2d",&a1->birthday.day);

}



void check(Sperson *a1){
	if(a1->birthday.year>=0 && a1->birthday.month>=1 && a1->birthday.month<=12 && a1->birthday.day>=1 && a1->birthday.day<=31){
		print(*a1);
	}
	else{
		printf("생년월일이 잘못 입력되었습니다.\n");
	}
}

void print(Sperson *a1) {
	printf("Name: %s\n",a1->name);
	printf("Telephone: %s\n",a1->telephone);//아직 전화번호 - 출력 안 됨
	printf("Birthday: %4d.%2d.%2d\n",a1->birthday.year,a1->birthday.month,a1->birthday.day);
}

*/

//동적 할당을 이용해 임의 개수 정수를 입력받은 후 역순으로 출력하는 프로그램을 작성하시오
/*
#include<stdio.h>
#include<stdlib.h>

int main (){
	int *p;
	int n, i;
	printf("몇개의 정수를 입력하고 싶으십니까?\n");
	scanf("%d",&n);

	p = (int*)malloc(n* sizeof(int));

	printf("%d개의 정수를 입력해 주세요.:\n",n);
	for(i = 0; i<n;i++){
		scanf("%d",&p[i]);
	}
	printf("당신이 입력한 정수를 역순으로 출력합니다.\n");
	for(i=n-1;i>=0;i--){
		printf("%d\n",p[i]);
	}
	return 0;
}
*/



//assert(수식); => 수식이 참이면 파일명, 행 번호로 오류 메시지 출력

// 스택을 이용하여 입력받은 정수를 역순으로 출력하는 프로그램을 만드시오
/*

//stack.h 파 일  
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
*/

//stack.c 파일 
/*#include "stack.h"
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
}*/

//printf.c
/* 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main() {
	int data;
	int n, i;
	Stack *s; //스택을 가리킬 포인터 
	
	printf("몇 개의 정수를 입력하고 싶으십니까?\n");
	printf("1이상 10이하로 입력해 주세요.");
	scanf("%d",&n);
	
	s = mkStack();  //스택을 생성함
	printf("%d개의 정수를 입력해 주세요.: ",n);
	for (i = 0; i<n;i++){
		scanf("%d",&data);
		push(s,data);
	} 
	
	printf("당신이 입력한 정수를 역순으로 출력합니다.: ");
	while(! isEmpty(s)){
		
		data = pop(s);
		printf("%d\n",data);
		
	}
	return 0;
	 
}
*/
/*

#include<stdio.h>

int main(int argc, char *argv[]){
	char c;
	FILE *fp1, *fp2;
	
	fp1 = fopen(argv[1],"r");
	if(fp1==NULL){
		printf("파일 %s 열기 오류!\n", argv[1]);
		exit(1);
	}
	
	fp2 = fopen(argv[2],"w");
	while((c = fgetc(fp1))!=EOF){
		fputc(c,fp2);
		
	}
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
*/

// 표준 입출력함수     표준 파일 입출력 함수    기능
/*
  getchar()				fgetc(), gets()			문자단위로 입력하는 함수
  getchar()				fputc(), putc()			문자단위로 출력하는 함수
  gets()				fgets()					문자열을 입력하는 함수
  puts()				fputs()					문자열을 출력하는 함수
  scanf()				fscanf()				자료형에 따라 자료를 입력하는 함수
  printf()				fprintf()				자료형에 따라 자료를 출력하는 함수
  */
  
  /*
  포맷 입출력
 int fprintf(FILE *fp, const char *format, ...);
 fpritf 함수의 첫번째 인수 fp는 출력할 파일에 대한 FILE포인터 
 두번째부터의 인수는 printf 함수와 동일
  
 int fscanf(FILE *fp, const char *format, ...);
 fscanf 함수의 첫 번째 인수 fpsms 입력받을 파일에 대한 FILE 포인터
 두 번째부터의 인수는 scanf 함수와 동일
 
 fseek(FILE *fp, long offset, int mode)
 FILE 포인터 fp가 가리키고 파일의 파일 위치를 모드(mode) 기준으로 오프셋만큼 옮긴다.
 
 SEEK_SET   0    파일 시작
 SEEK_CUR   1    현재 위치
 SEEK_END   2    파일 끝
 fseek(fp,100L,SEEK_CUR) 현재 위치에서 100바이트 우로 이동
 
 rewind(FILE *fp) => 파일 위치를 파일 시작점에 위치시켜 처음부터 다시 읽을 수 있게 한다.
 ftell(FILE *fp) => 파일의 현재 파일 위치를 나타내는 파일 위치 지정자 값 리턴
 */
  		 

