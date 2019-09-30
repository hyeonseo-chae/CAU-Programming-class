#include<stdio.h>
#include<string.h>
#define MAX_WORD 1000
#define MAX_STR 1000
int main() {
	int i = 0, j = 0;
	int types[MAX_WORD];
	char words[MAX_WORD][MAX_STR];
	int data[10000];

	printf("문자열을 입력하세요.\n");
	while (scanf("%s", words[i]) != EOF) {
		int m = 9;


		int len = strlen(words[i]);
		for (j = 0; j < len; j++) {

			if (m == 9 || m <= 4 && m >= 0) {

				if (words[i][j] <= 90 && words[i][j] >= 65 || words[i][j] <= 122 && words[i][j] >= 97) {

					if (m == 1 || m == 9) {

						m = 1;
					}
					else {

						m = 0;

					}

				}
				else if (words[i][j] <= 57 && words[i][j] >= 48) {
					if (m == 2 || m == 9) {
						m = 2;
					}
					else {

						m = 0;

					}

				}
				else if (words[i][j] == 42 || words[i][j] == 47 || words[i][j] == 94) {
					if (m == 3 || m == 9) {
						m = 3;
					}
					else {

						m = 0;

					}
				}
				else if (words[i][0] == 43 || words[i][0] == 45) {
					if(len==1){
						m = 3;
					}
					if (j > 0) {
						if (words[i][j] <= 57 && words[i][j] >= 48) {  
							if (m == 4 || m == 9) {
								m = 4;
							}
							else {

								m = 0;

							}
						}
						else if (words[i][1] == 46) {
						  
							if (words[i][j] <= 57 && words[i][j] >= 48) {
								if (m == 4 || m == 9) {
									m = 4;
								}
								else {

									m = 0;

								}
							}
						}
						else if (words[i][j] == 43 || words[i][j] == 45) { 
							if (m == 4 || m == 9 || m == 3) {
								m = 3;
							}
							else {

								m = 0;

							}

						}
					}
					
					


				}


			}




		}

		switch (m) {
		case 0:	data[i]=0;  break;
		case 1:	data[i]=1;  break;
		case 2:	data[i]=2;  break;
		case 3:	data[i]=3;  break;
		case 4:	data[i]=4;  break;
		}
		i++;
}

int kk;
for(kk=0;kk<i;kk++){
	switch (data[kk]) {
		case 0:	printf("[%d] %s (Others)\n", kk+1,words[kk]); break;
		case 1:	printf("[%d] %s (Alphabets)\n",kk+1, words[kk]); break;
		case 2:	 printf("[%d] %s (Numbers)\n", kk+1,words[kk]); break;
		case 3:	 printf("[%d] %s (Operators)\n",kk+1, words[kk]); break;
		case 4:	 printf("[%d] %s (Numbers)\n", kk+1,words[kk]); break;
		}
}
	return 0;
}
