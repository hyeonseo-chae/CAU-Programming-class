#include<stdio.h>
#include <string.h>
#define MAX_STR 100
#include <time.h>
#include <stdlib.h>
FILE *fp;

typedef struct struct_date {
int year, month, day;
} Sdate;

typedef struct struct_person {
char name[MAX_STR];
int telephone; 
Sdate birthday;
} Sperson;

int i = 0;
Sperson *p[100];
int pnumber=0;

void main(){
	fp = fopen("1.txt", "w+");

    if (fp==0){

        printf("파일 로딩에서 에러가 발생했습니다.");

    }

	while(1){	
		printf("\n1. Add a person\n");
	printf("2. Print the list\n");
	printf("3. Name search\n");
	printf("4. Birthday this month!\n");
	printf("5. Sort the phone book\n");
    printf("6. Save the phone book\n");
    printf("7. Load the phone book\n");
	printf("0. Quit the program\n");
	printf("\nEnter the command: ");
	int a;
	scanf("%d",&a);
	fflush(stdin);
	switch (a){
		case 1: one(); break;
		case 2: print(); break;
		case 3: three(); break;
		case 4: four(); break;
		case 5: five();break;
		case 6: six(); break;
		case 7: seven(); break;
		case 0: exit(0); fclose(fp); break;
	}
}	



}

void one() {
	
	input();
}


void three(){
	printf("찾을 이름 입력하세요.\n");

    char getname[MAX_STR];

    scanf("%s",getname);

    int got=0;
    int a; 

    for (a = 0; a <= (i-1); a++) {

        got = strcmp(p[a]->name, getname);

        if (got == 0) {

            printf("[%d] %s",a, getname);

            printf("0%d",p[a]->telephone);

            printf("%4d.%2d.%2d.\n", p[a]->birthday.year, p[a]->birthday.month, p[a]->birthday.day);

        }

        else{

            printf("검색된 이름이 없습니다.\n");

        }

    }
	
}

void four(){
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int m;
    int noone=0;
        for ( m = 0; m <=i-1; m++) {

        if ((p[m]->birthday.month) == (tm.tm_mon+1)) {
        	printf("Happy Birthdays!!!\n");

            printf("[%d] %s, 0%d, %4d.%2d.%2d.\n", m,p[m]->name,p[m]->telephone,p[m]->birthday.year, p[m]->birthday.month, p[m]->birthday.day);

        }

        else{

            noone++;

        }

    }

    if (noone==i){

     printf("%d달에 생일인 사람이 없습니다.\n",(tm.tm_mon+1));

    }
    
    
}



int compare(void *a, void *b)    

{
    return strcmp((char*)a,(char*)b);
}






void five(){


	qsort(p, i, sizeof(Sperson), compare);

    printf("Sorted!\n");
}

void six(){
	
	fp = fopen("1.txt", "w+");

    if (fp == NULL) {

        printf("파일 열기에서 에러가 발생했습니다\n");

    }
    
	int b=0;

    for (b=0; b<i; b++){

    fprintf(fp, "%s\n0%d\n%04d%02d%02d\n",p[b]->name,p[b]->telephone, p[b]->birthday.year,p[b]->birthday.month, p[b]->birthday.day);

    }


    fclose(fp);

}

void seven(){
	int f=0;

    

    for(f=0; f<pnumber; f++){

        fscanf(fp, "%s\n0%d\n%04d%02d%02d\n", &p[f]->name, &p[f]->telephone, &p[f]->birthday.year, &p[f]->birthday.month, &p[f]->birthday.day);

        }

    printf("로드 성공! 2를 작성해 출력해 보세요.\n");
}




void input(){
	 p[i] = malloc(sizeof(Sperson));

    

    char str[100];

    int num;

    int year, month, day;

    fflush(stdin);
	printf("Enter the name:");
	gets(str);
	strcpy(p[i]->name, str);
    fflush(stdin);
    printf("Enter the phone number:");
	scanf("%d",&num);
	p[i]->telephone = num;

    printf("Enter the birthday (yyyymmdd):"); //생년월일 8자리만 인식 가 능  
	scanf("%4d",&year);
	p[i]->birthday.year = year;
	
	scanf("%2d",&month);
	p[i]->birthday.month = month;
	scanf("%2d",&day);
   p[i]->birthday.day = day;
  
    printf("\n");


    i++;

    pnumber++;


}




	
	


void print() {
	int k;
	 for (k = 0; k <= (i-1); k++) {
	 	if(p[k]->birthday.year>=0 && p[k]->birthday.month>=1 && p[k]->birthday.month<=12 && p[k]->birthday.day>=1 && p[k]->birthday.day<=31){
		printf("[%d] Name: %s\n", k + 1, p[k]->name);

        printf("telephone: 0%d\n", p[k]->telephone);

        printf("Birthday: %d.%d.%d\n", (p[k]->birthday.year),(p[k]->birthday.month), (p[k]->birthday.day));
	}
	
	else{
		printf("생년월일이 잘못 입력되었습니다.\n");
		break;
	}
        

    }


}


