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
