#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //for exit(1)	
#include <string.h>
#include<windows.h>
#include <ctype.h>
#include <time.h>
#include "hangdraw.h"


#define MAX_WORDLEN 9999
#define MAX_MEANING 9999
#define MAX_WORDS 20000


typedef struct _word {
	char word[MAX_WORDLEN];
	char meaning[MAX_MEANING];
} Sword;

Sword dictionary[MAX_WORDS];
int wrong[10];
int wrong_num[10];

char buffer[300], word[20];
int nwords = 0;
int ff = 0;
int Lsearch(char arr[], int kk);
void list();
void search();
void game();
void hangman();
int line_num = 0;

FILE* fp;
char fname[30] = "voca13000.txt";

int main() {
	int nn;


	fp = fopen(fname, "r");



	char* ptr;

	if (fp == NULL) {
		fprintf(stderr, "파일%s를 열 수 없어요 \n", fname);
		//exit(1);
	}
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
	printf("### Dictionary###\n1. Search a Word\n2. List Words\n3. Word Game - Find Meaning\n4. Hangman\n0. Exit\n\nEnter the command:");
	scanf("%d", &nn);
	switch (nn) {
	case 1:search();
		break;
	case 2:list(); break;
	case 3: game(); break;
	case 4: hangman(); break;
	case 0:exit(1); break;
	default: printf("숫자를 잘못 입력하셨습니다."); break;

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
		if (i > 9 && i % 10 == 0) {
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
void game() {

	srand(time(NULL));
	int random;
	char arr[10] = { 0, };
	int kk;
	int hh = 1;
	int random1;
	int random2;
	int random3;
	int ff = 1;
	int oo = 0;
	int count = 0;
	int kkk = 0;
	char answer;

	while (1) {

		kk = rand() % 13047;
		random1 = rand() % 13047;
		random2 = rand() % 13047;
		random3 = rand() % 13047;

		int index;
		index = Lsearch(arr, kk);

		if (oo == 0) {
			printf("\n%d. %s\n\n", ff, dictionary[kk].word);
			printf("a. %s\n", dictionary[random1].meaning);
			printf("b. %s\n", dictionary[kk].meaning);
			printf("c. %s\n", dictionary[random2].meaning);
			printf("d. %s\n\n", dictionary[random3].meaning);
			printf("Answer: ");
			scanf("%s", &answer);
			if (answer == 'b') {
				count = count + 10;
				kkk++;
			}
			else {
				wrong[ff - 1] = kk;
				wrong_num[ff - 1] = hh;
			}
			ff++;
			oo++;
			hh++;
			arr[ff - 2] = kk;
		}
		if (index == -1) {
			if (ff <= 10) {
				if (ff % 4 == 0) {

					printf("\n%d. %s\n\n", ff, dictionary[kk].word);
					printf("a. %s\n", dictionary[random1].meaning);
					printf("b. %s\n", dictionary[random2].meaning);
					printf("c. %s\n", dictionary[kk].meaning);
					printf("d. %s\n\n", dictionary[random3].meaning);
					ff++;
					hh++;
					printf("Answer: ");
					scanf("%s", &answer);
					if (answer == 'c') {
						count = count + 10;
						kkk++;
					}
					else {
						wrong[ff - 1] = kk;
						wrong_num[ff - 1] = hh;
					}
					arr[ff - 2] = kk;
				}
				else if (ff % 4 == 1) {

					printf("\n%d. %s\n\n", ff, dictionary[kk].word);
					printf("a. %s\n", dictionary[random1].meaning);
					printf("b. %s\n", dictionary[random3].meaning);
					printf("c. %s\n", dictionary[random2].meaning);
					printf("d. %s\n\n", dictionary[kk].word);
					ff++;
					hh++;
					printf("Answer: ");
					scanf("%s", &answer);
					if (answer == 'd') {
						count = count + 10;
						kkk++;
					}
					else {
						wrong[ff - 1] = kk;
						wrong_num[ff - 1] = hh;
					}

					arr[ff - 2] = kk;
				}
				else if (ff % 4 == 2) {

					printf("\n%d. %s\n\n", ff, dictionary[kk].word);
					printf("a. %s\n", dictionary[kk].meaning);
					printf("b. %s\n", dictionary[random1].meaning);
					printf("c. %s\n", dictionary[random2].meaning);
					printf("d. %s\n\n", dictionary[random3].meaning);
					printf("Answer: ");
					scanf("%s", &answer);
					if (answer == 'a') {
						count = count + 10;
						kkk++;
					}
					else {
						wrong[ff - 1] = kk;
						wrong_num[ff - 1] = hh;
					}
					ff++;
					hh++;
					arr[ff - 2] = kk;
				}
				else if (ff % 4 == 3) {

					printf("\n%d. %s\n\n", ff, dictionary[kk].word);
					printf("a. %s\n", dictionary[random1].meaning);
					printf("b. %s\n", dictionary[kk].meaning);
					printf("c. %s\n", dictionary[random2].meaning);
					printf("d. %s\n\n", dictionary[random3].meaning);
					printf("Answer: ");
					scanf("%s", &answer);
					if (answer == 'b') {
						count = count + 10;
						kkk++;
					}
					else {
						wrong[ff - 1] = kk;
						wrong_num[ff - 1] = hh;
					}
					ff++;
					hh++;
					arr[ff - 2] = kk;
				}
			}
			else {
				printf("Score: %d (correct %d out of 10 problems)", count, kkk);
				printf("\n\nWrong problems\n\n");
				for (int i = 0; i < hh; i++) {
					if (wrong_num[i] != 0) {
						printf("%d. %s\t%s\n", wrong_num[i], dictionary[wrong[i]].word, dictionary[wrong[i]].meaning);
					}
				}

				exit(1); break;
			}

		}

	}

}
void hangman() {
	int kk;
	char d[1];
	char misses[100];
	srand(time(NULL));
	kk = rand() % 13047;
	system("cls");
	drawHangman(0);
	gotoxy(10, 15);
	printf("Word: ");
	int ff =strlen(dictionary[kk].word);
	for (int i = 0; i < ff; i++) {
		printf("-");
	}
	gotoxy(10, 16);
	printf("Misses:%s",misses);
	gotoxy(10, 17);
	printf("Guess : ");
	scanf_s("%c", &d);
	if (strstr(dictionary[kk].word, d)) {
		printf("d있음");
	}

}

int Lsearch(char arr[], int kk) {

	for (int i = 0; i < strlen(arr); i++) {
		if (kk != arr[i]) {
			return -1;
		}

	}
}