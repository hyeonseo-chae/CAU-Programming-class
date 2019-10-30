#include<stdio.h>
#include <string.h>
#define MAX_STR 100
#include <time.h>
#include <stdlib.h>

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
	printf("1. Add a person\n");
	printf("2. Print the list\n");
	printf("3. Name search\n");
	printf("4. Birthday this month!\n");
	printf("0. Quit the program\n");
	while(1){	
	printf("Enter the command: ");
	int a;
	scanf("%d",&a);
	fflush(stdin);
	switch (a){
		case 1: one(&a1); break;
		case 2: two(&a1); break;
		case 3: three(&a1); break;
		case 4: four(&a1); break;
		case 0: exit(0); break;
	}
}	



}

void one(Sperson *a1) {
	
	input(&a1);
}

void two(Sperson *a1){
	check(&a1);
}

void three(Sperson *a1){
	char kk[20];
	scanf("%s",kk);
	char * ptr = strstr((a1->name),kk);
	if(ptr != NULL){
		printf("%s, %s, %4d.%2d.%2d.\n",a1->name,a1->telephone,a1->birthday.year,a1->birthday.month,a1->birthday.day);
	}
	
}

void four(Sperson *a1){
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
	if((a1->birthday.month )== (tm.tm_mon+1)){
		printf("Happy Birthdays!!!\n");
			printf("%s, %s, %4d.%2d.%2d.\n",a1->name,a1->telephone,a1->birthday.year,a1->birthday.month,a1->birthday.day);
	}
}
void input(Sperson *a1){
	fflush(stdin);
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
	printf("Birthday: %4d.%2d.%2d.\n",a1->birthday.year,a1->birthday.month,a1->birthday.day);
}


