#include <stdio.h>
#include "hangdraw.h"

const char *map[] = {
	"    ----------     ",
	"    |              ",
	"    |              ",
	"    |              ",
	"    |              ",
	"    |              ",
	"    |              ",
	"    |              ",
	"____|______________",
//	"",
//	"Word : ",
//	"Misses : ",
//	"Guess : ",
};
int nmap = sizeof(map) / sizeof(map[0]);

const char *hangs[] = {
	" |",
	" @",
	"/", "|", ">",
	" | ",
	"/", " )"
};
int nhangs = sizeof(hangs) / sizeof(hangs[0]);

int hangpos[][2] = {
					{ 9, 1 },
					{ 9, 2 }, 
					{ 9, 3 }, { 10, 3 }, { 11, 3 },
					{ 9, 4 },
					{ 9, 5 }, { 10, 5 }
};

const char *winPic[] = {
	"(O/",
	" | ",
	"/ >"
};
int nwinPic = sizeof(winPic) / sizeof(winPic[0]);


void setColor(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

bool getColor(WORD &ret){
	CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
		return false;
	ret = info.wAttributes;
	return true;
}

void clrscr()
{
	system("cls");
}

void gotoxy(int x, int y) //콘솔 화면 특정 위치로 이동
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void drawPic(const char *pic[], int npic, int x, int y)
{
	for (int i = 0; i < npic; i++) {
		gotoxy(x, y + i);
		printf("%s", pic[i]);
	}
}


void drawHangman(int mode)
{
	switch (mode) {
	case 0:
		drawPic(map, nmap, WINX, WINY);
		break;
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
		gotoxy(WINX + hangpos[mode - 1][0], WINY + hangpos[mode - 1][1]);
		printf("%s", hangs[mode-1]);
		if (mode == NCHANCE) {
			gotoxy(WINX + 6, WINY + 6);
			WORD prevColor;
			getColor(prevColor);
			setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

			printf("You Die!!");
			setColor(prevColor);
		}
		break;
	case Win:
		drawPic(map, nmap, WINX, WINY);
		gotoxy(WINX + 6, WINY + 3);
		printf("You Win !!");
		drawPic(winPic, nwinPic, WINX + 9, WINY + 5);
		break;
	default:
		break;
	}
	gotoxy(WINX + 8, WINY + 12);
}

/// drawHangman 사용법 예제
#include <conio.h>

void drawHangmanTest()
{
	clrscr();
	drawHangman(0);
	gotoxy(TEXTX, TEXTY);
	printf("Press any key to start");
	_getch();
	for (int i = 1; i <= NCHANCE; i++) {
		drawHangman(i);
		gotoxy(TEXTX, TEXTY);
		printf("You missed %d letters     ", i);
		_getch();
	}
	drawHangman(Win);
	gotoxy(TEXTX, TEXTY);
	printf("Press any key to continue...");
	_getch();
}