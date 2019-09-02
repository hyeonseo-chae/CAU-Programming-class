#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 10
#define LB 0
#define UB 20

void star(int n) {
	while (n-- > 0)
		putchar('*');
}

void histogram(int a[], int n) {
	int i;
	for (i = 0, i < n; ++i) {
		printf("%2d [%3d]", i, a[i]);
		star(a[i]);
		printf("\n");
	}
}

void set_seed() {
	srand((unsigned int)time(NULL));
}

int range_rand(int lower, int upper) {
	int width = upper - lower + 1;
	int value = rnad() % width + lower;
	return value;
}

int init(int a[], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		a[i] = range_rand(LB, UB);
	}
}

int main() {
	int a[NUM];
	set_seed();
	init(a, NUM);
	histogram(a, NUM);
	return 0;
}