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

