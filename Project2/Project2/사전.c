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
			while (ptr != NULL)			//strtok���� �߸� ����
			{

				strcpy(dictionary[line_num].word, ptr);
				ptr = strtok(NULL, "");

				strcpy(dictionary[line_num].meaning, ptr);//ptr ���

				line_num++;
				ptr = strtok(NULL, "");		//NULL�� ������ strtok���� ������ ���ڸ� �ڸ�
													 //�Ŀ� ���� ������ �ּҸ� ��ȯ����.
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
	default: printf("���ڸ� �߸� �Է��ϼ̽��ϴ�."); break;

	}


	if (fp == NULL) {
		fprintf(stderr, "����%s�� �� �� ����� \n", fname);
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
			printf("q�� ������ Ű�� ������ ���� �������� �Ѿ�ϴ�. q�� ������ �����մϴ�.\n");
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