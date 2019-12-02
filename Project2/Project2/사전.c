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
/*char *ptr = strtok(s1, " ");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        printf("%s\n", ptr);          // 자른 문자열 출력
        ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환
    }*/

int main()
{
	FILE* fp;
	char buffer[300], word[20];
	int line_num = 0;
	char fname[30] = "voca13000.txt";
	printf("검색할 단어는 ? : ");
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
		fprintf(stderr, "파일%s를 열 수 없어요 \n", fname);
		exit(1);
	}
	char* ptr=0;
	int listt[2];
	
	while (fgets(buffer, 300, fp)) {
		line_num++;
		
		if (strstr(buffer, word))//문자열 찾아주는 함수
			* ptr = strtok(buffer, "	");
		int kk=0;
		while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
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

