//1번 문 제  
/* 
#include <stdio.h>

int gcd(int m,int n);

void main(){
	printf("%d",gcd(12,3));
}

int gcd(int m,int n){
	int ans;
	int temp;
	if(m%n==0){
		ans = n;
	}
	else {
		//ans = gcd(n,m%n);
		while(m%n!=0){
			temp = n;
			n = m%n;
			m = temp;
			if(m%n==0){
				ans = n;
			}
		}
	}
	return ans;
}
*/ 

//2번 문제
/*
#include<stdio.h>

void printSum(int n);

void main(){
	printSum(11);
} 

void printSum(int n){
	int i;
	int sum=0, val=0,k=0;
	for (i=0;i<n;i=i+2){
		sum = sum + i;
		k++;
	}
	val = sum/k;
	printf("합 : %d\n",sum);
	printf("평균 : %d",val);

}*/

//3번 문제 
/*#include<stdio.h>

//135 357 579
#define num 9
void tree();
void main(){
	 tree();
	
}

void tree(){
	int i,j,l,k=0;
	for (i=1;i<=3;i++){
	
		for (j=2*i-1;j<=2*i+3;j=j+2){
			for(k=num/2-j/2;k>0;k--){
				printf(" ");
			}
			for( l=0;l<j;l++){
				printf("*");
			}
			printf("\n");
		}
	
	}
}*/


//4번 문제
/* 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define count 1000
void dice();
void main(){
	dice();
}
void dice(){
	int dice[7]={0,};
	srand((unsigned)time(NULL));
	int i,num;
	for(i=0;i<count;i++){
		num = 1+ (rand()%6);
		dice[num]++;
	}
	for (i=1;i<7;i++){
		printf("[%d] %d, %6f\n",i,dice[i],(float)dice[i]/1000);
	}
}
*/

//6번 문제  
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex2dec(char *hex, int ck){
    int tmp;
    if(*hex=='0') tmp=0;
    else if(*hex=='1') tmp=1;
    else if(*hex=='2') tmp=2;
    else if(*hex=='3') tmp=3;
    else if(*hex=='4') tmp=4;
    else if(*hex=='5') tmp=5;
    else if(*hex=='6') tmp=6;
    else if(*hex=='7') tmp=7;
    else if(*hex=='8') tmp=8;
    else if(*hex=='9') tmp=9;
    else if(*hex=='A') tmp=10;
    else if(*hex=='B') tmp=11;
    else if(*hex=='C') tmp=12;
    else if(*hex=='D') tmp=13;
    else if(*hex=='E') tmp=14;
    else if(*hex=='F') tmp=15;
   tmp=tmp* (int)pow(16,ck);
   if(*hex==NULL) return;
   else return tmp+hex2dec(hex+1,ck-1);
}

int main(){
    char hex[10000];
    scanf("%s", &hex);
    printf("%d", hex2dec(hex,strlen(hex)-1));
}
*/
