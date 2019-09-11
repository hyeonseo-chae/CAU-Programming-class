// 소프트웨어학부 20195447 채현서 

#include <stdio.h>
#define N 10


void spiralArray(int(*a)[N], int n) {
int i=0,j=-1,k,l=N,s=1,number = 1;
     
    while(1){
     
        for(k=0;k<l;k++){ 
            j += s;
            a[i][j] = number;
            number++;
        }
     
        l--; 
         
        if(l<0) break;
         
        for(k=0;k<l;k++){ 
            i += s;
            a[i][j] = number;
            number++;
        }
         
        s = -s; 
    }
}

void printArray(int(*a)[N], int n) {
	int i, k;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++) {
			printf("%5d", a[k][i]);
		}
		printf("\n");
	}
}

int main() {
	int Array[N][N] = {0, };
	spiralArray(Array, N);
	printArray(Array, N);
	return 0;
}
