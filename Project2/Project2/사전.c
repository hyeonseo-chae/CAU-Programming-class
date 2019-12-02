#define _CRT_SECURE_NO_WARNINGS

#define MAX_WORDLEN 99999
#define MAX_MEANING 99999
#define MAX_WORDS 9999
#include <stdio.h>
#include <stdlib.h> //for exit(1)	
#include <string.h>

#include <ctype.h>

typedef struct _word {
	char word[MAX_WORDLEN];
	char meaning[MAX_MEANING];
} Sword;

Sword dictionary[MAX_WORDS];
int nwords = 0;
int ff = 0;
/*char *ptr = strtok(s1, " ");      // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ

    while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
    {
        printf("%s\n", ptr);          // �ڸ� ���ڿ� ���
        ptr = strtok(NULL, " ");      // ���� ���ڿ��� �߶� �����͸� ��ȯ
    }*/

int main()
{
	FILE* fp;
	char buffer[300], word[20];
	int line_num = 0;
	char fname[30] = "voca13000.txt";
	printf("�˻��� �ܾ�� ? : ");
	scanf("%s", word);
int i;
	for ( i = 0; i < strlen(word); i++)
	{
		if (isupper(word[i]))
		{
			word[i] = tolower(word[i]);
		}
		
	}
	fp = fopen(fname, "r");
	if (fp == NULL) {
		fprintf(stderr, "����%s�� �� �� ����� \n", fname);
		exit(1);
	}
	char* ptr=0;
	int listt[2];
	
	while (fgets(buffer, 300, fp)) {
		line_num++;
		
		if (strstr(buffer, word))//���ڿ� ã���ִ� �Լ�
			* ptr = strtok(buffer, "	");
		int kk=0;
		while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
		{
			
			listt[kk] = ptr;
			kk++;
		}
		strcpy(dictionary[ff].word, listt[0]);
		strcpy(dictionary[ff].meaning, listt[1]);
		ff++;
			printf("%s ", dictionary[ff-1].word);

	}

	
	fclose(fp);
	puts("complete");

	return 0;
}

