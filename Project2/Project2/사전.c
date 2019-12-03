#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //for exit(1)	
#include <string.h>
#include<windows.h>
#include <ctype.h>



#define MAX_WORDLEN 9999
#define MAX_MEANING 9999
#define MAX_WORDS 20000


typedef struct _word {
	char word[MAX_WORDLEN] ;
	char meaning[MAX_MEANING];
} Sword;

Sword dictionary[MAX_WORDS];

char buffer[300], word[20];
int nwords = 0;
int ff = 0;

void list();
void search();
int line_num = 0;
int main() {
	int nn;
	FILE* fp;
	char fname[30] = "voca13000.txt";
	fp = fopen(fname, "r");
	


	char* ptr;


	while (1) {


		if (fgets(buffer, 300, fp)) {
			ptr = strtok(buffer, "\t");

			int kk = 0;
			while (ptr != NULL)			//strtok으로 잘린 문자
			{

				strcpy(dictionary[line_num].word, ptr);
				ptr = strtok(NULL, "");

				strcpy(dictionary[line_num].meaning, ptr);//ptr 출력

				line_num++;
				ptr = strtok(NULL, "");		//NULL을 넣으면 strtok에서 이전에 문자를 자른
													 //후에 다음 문자의 주소를 반환해줌.
			}
		}
		else {
			break;
		}




	}
	printf("### Dictionary###\n1. Search a Word\n2. List Words\n3. Exit\n\nEnter the command:");
	scanf("%d", &nn);
	switch (nn) {
	case 1:search();
		 break;
	case 2:list(); break;
	case 3:exit(1); break;
	default: printf("숫자를 잘못 입력하셨습니다."); break;

	}


	if (fp == NULL) {
		fprintf(stderr, "파일%s를 열 수 없어요 \n", fname);
		exit(1);
	}




	fclose(fp);


	search();



	printf("complete");

	return 0;
}

void list() {
	char ll;
	for (int i = 0; i < 13047; i++) {
		
		printf("%s\t", dictionary[i].word);
		printf("%s\n", dictionary[i].meaning);
		if (i>9&&i%10==0) {
			printf("q를 제외한 키를 누르면 다음 페이지로 넘어갑니다. q를 누르면 종료합니다.\n");
			scanf("%s", &ll);
			system("cls");
			if (ll == 'q') {
				exit(1); break;
			}
		}
		
	}
}

void search() {
	printf("Enter the word to search :");
	scanf("%s", &word);
	int i;
	for (i = 0; i < strlen(word); i++)
	{
		if (isupper(word[i]))
		{
			word[i] = tolower(word[i]);
		}

	}
	char kk;
	for (int i = 0; i < line_num; i++) {
		if (strstr(dictionary[i].word, word)) {

			printf("%s\t", dictionary[i].word);
			printf("%s\n", dictionary[i].meaning);

		}
	}
	printf("Do you want to search another word ? (y / n)\n");
	scanf("%s", &kk);
	if (kk == 'y') {
	
		search();
	}
	else { exit(1); }
}