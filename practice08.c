#include<conio.h>
#include<windows.h>
#include<stdio.h>

void gotoxy(int x, int y);
void console_center();
int columns, rows;
int kk = 0;
int main(void)

{
	
	console_center();
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {

			for (int k = 0; k < 3; k++) {
				if (kk % 2 == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224); //³ë¶û
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160); //ÃÊ·Ï
				}

				gotoxy(columns + 4 * i, rows + k+j*3);
				printf("    ");
				

			}
			kk++;
		}
	}
	
	
	
	

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