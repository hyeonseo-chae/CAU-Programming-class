# include <stdio.h>

int main() {
	char aa[4][5] = {"This", "That", "Here", "Hour"};
	char (*ap)[5];
	char **pp;
	char *pa[4] = {"This", "is", "pointer", "array"};
	int i = 0;
	const n1 = sizeof aa / sizeof *aa;
	const n2 = sizeof pa / sizeof*pa;
	
	ap = aa;
	pp = pa;
	
	printf("[Array Pointer]\n");
	for (i = 0; i<n1; i++){
		printf("%p: %s\n", ap + i, ap[i]);
		
	}
	printf("\n");
	printf("[Pointer Pointer]\n");
	for ( i = 0; i<n2; i++){
		printf("%p: %s\n",pp+i, pp[i]);
		
	}
	return 0;
	
	}
