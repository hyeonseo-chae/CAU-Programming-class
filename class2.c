/*
#include <stdio.h>

void printIntVar(char *name, int value){
	printf("%s\t = %d\n", name, value);
}

int main () {
	int one = 1;
	int *to_one;
	
	to_one = &one;
	printIntVar("one", one);
	*to_one = one +1 ;
	printIntVar("one", one);
	*to_one = *to_one + 1 ;
	printIntVar("one", one);
	(*to_one)++;
	printIntVar("one", one);
	return 0;
	
}
*/

/*
#include <stdio.h>

void printIntVar(char *name, int value){
	printf("%s\t = %d\n", name, value);
}

int main ()
{
	int n;
	
	printf("���� n�� �Է��� �ּ���.\n");
	scanf("%d", &n);
	
	printIntVar("n",n);
	printIntVar("*&n", *&n);
	
	return 0; 
}
*/

/*
#include <stdio.h>
void printAB(int a, int b)
{
	printf("�� ���� ���� ������� ����ϸ� %d, %d�Դϴ�.\n", a,b);
}

int main () {
	int a = 2;
	int b = 3;
	
	int tmp;
	
	printAB(a,b);
	tmp = a;
	a = b;
	b = tmp;
	printAB(a,b);
	
	return 0;
}
*/


//�߿� !!! 
/*
#include <stdio.h>
void printAB(int a, int b)
{
	printf("�� ���� ���� ������� ����ϸ� %d, %d�Դϴ�.\n", a,b);
}

void change (int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

}

int main () {
	int a = 2;
	int b = 3;
	
	int tmp;
	
	printAB(a,b);
	change(&a,&b);
	printAB(a,b);
	
	return 0;
}
*/

