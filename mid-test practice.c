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
