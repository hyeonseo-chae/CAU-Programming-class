// �Լ��� Ȱ���Ͽ� ���丮���� ���ϴ� ���α׷��� ����ÿ�
/*
include <stdio.h>
int factorial(int n);
int main(){
	int n;
	printf("���丮���� ���ϰ� ���� ���ڸ� �Է��Ͻÿ�.: ");
	scanf("%d",&n);
	printf("%d�� ���丮���� %d�Դϴ�.",n,factorial(n)); 
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
// ���� ���� ����ϱ� 5���� 
#include <stdio.h>
#include <stdlib.h> //srand �� rand �Լ� 
#include <time.h> // time �Լ� 

int main () {
	int i;
	srand((unsigned int)time(NULL)); //time�� ��ȯ�� calendar time�� srand�� �μ��� ���� 
	for (i = 0; i<5;i++){
		printf("%d ",rand()%10);
		
	}
	return 0;
} */

// �� ���� Swap �ϴ� ���α׷��� �Լ��� ���� �����ض�
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
���ڿ� ���� ���̺귯�� �Լ�
strlen() => ���ڿ� ���� ����
strcpy(1,2) => ���ڿ� 2�� 1�� �����Ѵ�.
strcat(1,2) => ���ڿ� 2�� 1�� �����Ѵ�.
strcmp(1,2) => ���ڿ� 1�� 2�� ���Ѵ�. => ���ڿ��� ������ 0����, �ƴϸ� ascii �ڵ尪 ���� ���� 
strchr(1,ch) => ���ڿ� 1���� ch�� ó�� ��Ÿ�� ��ġ�� �����Ѵ�.
strstr(1,2) => ���ڿ� 1���� 2�� ó����Ÿ�� ��ġ�� �����Ѵ�.
strtok(1,2) => ���ڿ� 1���� 2���� ���ڸ� ��ū���� �Ͽ� ���� ��ū�� �����͸� �����Ѵ�.
atoi(1) => ���ڿ� 1�� int ������ ��ȭ�Ͽ� �����Ѵ�.
atol(1) => ���ڿ� 1�� long int ������ ��ȯ�Ͽ� �����Ѵ�.
atof(1) => ���ڿ� double �ε��������� ���� ��ȯ�Ͽ� �����Ѵ�.
*/


/*
����ü ����

struct student{
char name[20];
int stud_id;
};

����ü ���� ����
struct student s1, s2;

������(typedef)�� ����� ����ü �ڷ��� �̸� ����
typedef struct{
char name[20];
int stud_id;
} STUD;

STUD s1. s2;

����ü ���ǽ� ������ �Բ� ����
struct student{
char name[20];
int stud_id;
}s1,s2;

����ü �̸��� ������ �ʰ� ����ü�� ���� ���� ����
struct{
char name[20];
int stud_id;
}s1,s2;
 
*/
 
 //����ü & ������ ���� ���
 
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
    printf("Enter the birthday (yyyymmdd):"); //������� 8�ڸ��� �ν� �� ��  
	scanf("%4d",&a1->birthday.year);
	scanf("%2d",&a1->birthday.month);
	scanf("%2d",&a1->birthday.day);

}



void check(Sperson *a1){
	if(a1->birthday.year>=0 && a1->birthday.month>=1 && a1->birthday.month<=12 && a1->birthday.day>=1 && a1->birthday.day<=31){
		print(*a1);
	}
	else{
		printf("��������� �߸� �ԷµǾ����ϴ�.\n");
	}
}

void print(Sperson *a1) {
	printf("Name: %s\n",a1->name);
	printf("Telephone: %s\n",a1->telephone);//���� ��ȭ��ȣ - ��� �� �� 
	printf("Birthday: %4d.%2d.%2d\n",a1->birthday.year,a1->birthday.month,a1->birthday.day);
}

*/

//���� �Ҵ��� �̿��� ���� ���� ������ �Է¹��� �� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
/*
#include<stdio.h>
#include<stdlib.h>

int main (){
	int *p;
	int n, i;
	printf("��� ������ �Է��ϰ� �����ʴϱ�?\n");
	scanf("%d",&n);
	
	p = (int*)malloc(n* sizeof(int));
	
	printf("%d���� ������ �Է��� �ּ���.:\n",n);
	for(i = 0; i<n;i++){
		scanf("%d",&p[i]);
	}
	printf("����� �Է��� ������ �������� ����մϴ�.\n");
	for(i=n-1;i>=0;i--){
		printf("%d\n",p[i]);
	}
	return 0;
} 
*/

//assert(����); => ������ ���̸� ���ϸ�, �� ��ȣ�� ���� �޽��� ��� 

