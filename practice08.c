#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

void gotoxy(int x, int y);
void console_center();
int columns, rows;
int kk = 0;
int main(void)

{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);


	
	int i,j,k;
	int ff = 0;
	console_center();
	gotoxy(columns, rows-6);
	char str[30] = "### Tic - Tac - Toe ###";
	gotoxy(columns-strlen(str)/2 +6 , rows - 6);
	printf("%s",str);
	char str1[50] = "Plater 1 : Human, Player 2 : Computer";
	gotoxy(columns - strlen(str1) / 2 +6, rows-3);
	printf("%s", str1);
	for (j = 0; j < 3; j++) {
		for (i = 0; i < 3; i++) {

			for (k = 0; k < 3; k++) {
				if (kk % 2 == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224); //노랑
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160); //초록
				}

				gotoxy(columns + 5 * i, rows + k + j * 3);
				if (ff==1) {
					printf("  O  ");

				}
				else if (ff==13){
					printf("  X  ");
				}
				else {
					printf("     ");
				}
				ff++;

			}
			kk++;
		}
	}
	
		
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //배경색 복구 

	
	

	return 0;

}

void console_center() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	columns = (columns / 2) -8;
	rows = (rows / 2) -5;

}

void gotoxy(int x, int y)

{

	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
