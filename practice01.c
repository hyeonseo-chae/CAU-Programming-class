#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int NUM = 10;
double a[100] = {0, };
double b[100] = {0, };


int fact(int t)
{
	if (t <= 1) return 1;
	return t * fact(t - 1);
}

double bi_dis(int NUM, int k)
{
	double kk;
	kk = (fact(NUM) / fact(k) / fact(NUM - k));
	return kk;

}

void set_seed()
{
	srand((unsigned int)time(NULL));
}

int exp(int start, int end, int tem_sum, int check)
{
	if (start == end)
	{
		if (tem_sum == check) return 1;
		else return 0;
	}
	else
	{
		tem_sum += rand() % 2;
		return exp(start + 1, end, tem_sum, check);
	}
}

int main()
{
	set_seed();
	int i,j;

	for (i = 0; i <= NUM; i++){
		for ( j = 0; j < NUM*NUM; j++) a[i] += exp(0, NUM, 0, i);

		printf("%d[%.3f] : ", i, a[i]);
		for ( j = 0; j < a[i]; j++)	printf("*");
		printf("\n");
	}

	printf("\n");
	printf("Challenge Problem\n");


	for ( i = 0; i <= NUM; i++){
		b[i] = bi_dis(NUM, i) / (2 ^ NUM);

		printf("%d[%.3f] : ", i, b[i]);
		for ( j = 0; j<b[i]; j++){
			printf("*");
		}
			printf("\n");
	}
}
