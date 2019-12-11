#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>



void main() {
	srand((unsigned)time(NULL));
    char a1 = '0' + rand() % 10;
	char a2 = '0' + rand() % 10;
	char a3 = '0' + rand() % 10;

	//printf("%c %c %c", a1, a2, a3); //프로그램 검사시 사용하세요.
	int count = 0;
	int strike = 0,ball=0;
	char b1, b2, b3;
	for (int i = 0; i < 10; i++) {
	
		count++;
		printf("0 0 0 형태로 숫자 사이를 띄어서 입력하세요\n");

		scanf(" %c %c %c", &b1, &b2, &b3);
		if (a1 == b1) {
			strike++;
		}
		else if (a1 == b2 || a1 == b3) {
			ball++;
		}
		if (a2==b2) {
			strike++;
		}
		else if (a2 == b3 || a2 == b1) {
			ball++;
		}
		if (a3 == b3) {
			strike++;
		}
		else if (a3 == b2 || a3 == b1) {
			ball++;
		}
		
		

		printf("%dS %dB\n\n",strike,ball );
		
		if (count == 10) {
			printf("\n\nStrike Out!!! \n플레이어가 졌습니다. 정답은 %c %c %c입니다.\n\n", a1, a2, a3);
			exit(0);
		}
		if (strike == 3) {
			printf("\n\n플레이어가 이겼습니다. 축하드립니다.\n\n");
			exit(0);
		}
		strike = 0, ball = 0;

	}
}