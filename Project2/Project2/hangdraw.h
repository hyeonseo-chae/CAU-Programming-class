#ifndef _HANGDRAW_H
#define _HANGDRAW_H

#include<windows.h>

#define WINX  5		// 그림을 그리는 맨 왼쪽 위치
#define WINY  2		// 그림을 그리는 맨 위쪽 위치
#define TEXTX  WINX			// 텍스트를 그리는 맨 왼쪽 위치
#define TEXTY  (WINY+10)	// 텍스트를 그리는 맨 위쪽 위치
#define Win   100	// 이겼을 때의 모드 - drawHangman의 입력 파라미터
#define NCHANCE 8	// 글자를 추측할 수 있는 기회의 수

// Functions
void clrscr(); // 화면을 지움
void gotoxy(int x, int y); //콘솔 화면의 (x, y) 위치로 이동
void setColor(WORD color); //폰트 및 배경 색 지정

// hangman을 그림
// mode 값 0: 전체 틀을 그림
// mode 값 1~7: 매달리는 부위를 하나씩 그림
// mode 값 8 == NCHANCE: 게임에 졌을 때의 화면 출력
// mode 값 Win : 게임에 이겼을 때의 화면 출력
void drawHangman(int mode); 

void drawHangmanTest(); // drawHangman 사용 예제


#endif