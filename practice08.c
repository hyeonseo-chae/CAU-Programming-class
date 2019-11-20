
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <string.h>

#define DIFF_X 2
#define DIFF_Y 1
#define SCREEN_X 80
#define SCREEN_Y 27
#define BOXSIZE_X 9
#define BOXSIZE_Y 5
#define WINRESULTCOLOR FOREGROUND_RED

int mode = 0;
COORD pos[9] = { { 29, 7 }, { 38, 7 }, { 47, 7 }, { 29, 12 }, { 38, 12 }, { 47, 12 }, { 29, 17 }, { 38, 17 }, { 47, 17 } };
COORD CommandPos = { 37,25 };
COORD GameAgainPos = { 25, 25 };
COORD MenuPos = { 0, 9 };
COORD WinResultPos = { 35, 4 };
COORD MenuAIPos = { 0, 17 };


int command = 0;

COORD messageposition = { 34,20 };
int board[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
int boardpattern[8][3] = { 0 };
int heuristicNum[5] = { 1000,100,15,10,1 };
int HeuristicBoard[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

void menuSelection();
void GameAgainMessage();
void GameDrawMessage();
void finish();

int isGameFinished(char OX);
int isEmptyBox(int input);
int isEmpty(int row, int column);

void PlayHumanFirst();
void PlayComputerFirst();
void ComputerTurn();
void HumanTurn(char OX);
void comvscom();


void random(char Ox);
void dumb();
void dumber();
void smart();
void calcHeuristicCell();
void initBoard();

void DrawBox(COORD p, int color);
void drawboard();
void drawmenu();
void ClearHeuristicBoard();
void PutLetter(char ox, int i, int j);
void CursorView();
COORD calcMaxCell();
COORD checkBoxForHeuristic(char OX, int charnum, int ranking);
COORD checkTwoBox(char OX);

void CursorView(char show)//커서숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}



void DrawBox(COORD p, int color) {
	p.X -= DIFF_X;
	p.Y -= DIFF_Y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 0; i < BOXSIZE_Y; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		for (int j = 0; j < BOXSIZE_X; j++) {
			printf(" ");
		}
		p.Y++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void initBoard() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = 0;
}

void drawboard() {
	
	system("mode con cols=80 lines=27");
	char title[] = "###TIC-TAC-TOC GAME###";
	COORD titleposition = { (SCREEN_X - strlen(title)) / 2, 2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), titleposition);
	printf("%s\n\n", title);

	for (int i = 0; i < 9; i++) {
		if (i % 2)
			DrawBox(pos[i], BACKGROUND_GREEN);
		else
			DrawBox(pos[i], BACKGROUND_BLUE);
	}


}

void drawmenu() {
	char* str[3] = { "Play First\n","Play Second\n", "Exit\n" };

	
	system("mode con cols=80 lines=27");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MenuPos);

	for (int i = 0; i < 3; i++) {
		printf("%d: %s", i + 1, str[i]);
	}
	
}

void menuSelection() {
	drawmenu();
	printf("\nEnter Command :");
	scanf("%d", &command);
	if (command == 1) {
		drawboard();
		PlayHumanFirst();
	}
	else if (command == 2) {
		drawboard();
		PlayComputerFirst();
	}
	
	else if (command == 0) {
		finish();
	}


}
int isEmptyBox(int input) {
	int row = 0;
	int column = 0;
	if (input == 1) {
		row = 0;	column = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
	}
	else if (input == 2) {
		row = 0;	column = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	}
	else if (input == 3) {
		row = 0;	column = 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
	}
	else if (input == 4) {
		row = 1;	column = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	}
	else if (input == 5) {
		row = 1;	column = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
	}
	else if (input == 6) {
		row = 1;	column = 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	}
	else if (input == 7) {
		row = 2;	column = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
	}
	else if (input == 8) {
		row = 2;	column = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	}
	else if (input == 9) {
		row = 2;	column = 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
	}
	else;
	if (board[row][column] == 0) {
		return 1;
	}
	else
		return 0;
}

void PutLetter(char ox, int i, int j) {
	board[i][j] = ox;
	COORD p = pos[i * 3 + j];
	p.X += 2; 
	p.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	
	printf("%c", ox);
}

void HumanTurn(char OX) {
	int input = 0;
	while (1) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CommandPos);
		printf("Your turn :        ");
		scanf("%d", &input);
		if (isEmptyBox(input)) {
			break;
		}
	}
	int row = ((input - 1) / 3);
	int column = (input - 1) % 3;
	PutLetter(OX, row, column);

	if (isGameFinished(OX)) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), WinResultPos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WINRESULTCOLOR);
		printf("Human Win");
		GameAgainMessage();
	}

}


COORD checkTwoBox(char OX) {
	
	int count;
	int zero;
	COORD pos = { -1, -1 };
	for (int j = 0; j < 3; j++) {
		count = 0;
		zero = 0;
		for (int i = 0; i < 3; i++) {
			
			if (board[j][i] == OX) {
				count++;
				
			}
			else if (board[j][i] == 0) {
				zero++;
				pos.Y = i;
				pos.X = j;
				
			}
		}
		if (count == 2 && zero == 1) {

			
			return pos; 
		}
	}
	
	int j;
	for (int i = 0; i < 3; i++) {
		count = 0;
		zero = 0;
		for (j = 0; j < 3; j++) {
			
			if (board[j][i] == OX) {
				count++;
				
			}
			else if (board[j][i] == 0) {
				zero++;
				pos.X = j;
				pos.Y = i;
				
			}
		}
		if (count == 2 && zero == 1) {
			
			return pos; 
		}
	}


	count = 0;
	zero = 0;

	for (int i = 0; i < 3; i++) {
		if (board[i][i] == OX) {
			count++;
			
		}
		else if (board[i][i] == 0) {
			zero++;
			
		}
		if (count == 2 && zero == 1) {
			
			pos.X = i;
			pos.Y = i;
			
			return pos;
		}

	}
	
	count = 0;
	zero = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][2 - i] == OX)
			count++;
		else if (board[i][2 - i] == 0) {
			zero++;
			pos.Y = 2 - i;
			pos.X = i;
		}
		if (count == 2 && zero == 1) {
			
			return pos;
		}
		else;
		
	}
	pos.X = -1;
	pos.Y = -1;
	return pos;
}
int isGameFinished(char OX) {
	
	int count;
	for (int j = 0; j < 3; j++) {
		count = 0;
		for (int i = 0; i < 3; i++) {
			if (board[j][i] == OX)
				count++;
		}
		if (count == 3)
			return 1; 
	}

	
	for (int j = 0; j < 3; j++) {
		count = 0;
		for (int i = 0; i < 3; i++) {
			if (board[i][j] == OX)
				count++;
		}
		if (count == 3)
			return 1; 
	}
	
	count = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][i] == OX)
			count++;
		if (count == 3)
			return 1; 
	}

	
	count = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][2 - i] == OX)
			count++;
		if (count == 3)
			return 1; 
	}
	return 0; 
}


void random(char OX) {
	int randnum = 0;
	srand(time(NULL));
	while (1) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CommandPos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("                                                          ");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CommandPos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("컴퓨터가 두는중...");
		randnum = rand() % 9 + 1;
		if (isEmptyBox(randnum)) {
			break;
		}
		else
			continue;
	}
	randnum--;
	int row = (randnum / 3);
	int column = randnum % 3;
	COORD p = pos[randnum];
	p.X += 2;
	p.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	
	Sleep(1000);
	printf("%c", OX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	board[row][column] = OX;
}

int isEmpty(int row, int column) {
	if (board[row][column] == 0) {
		return 1;
	}
	else
		return 0;
}


void dumber() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CommandPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("                                                           ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CommandPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("컴퓨터가 두는중...");
	Sleep(1000);
	
	COORD pos = { -1, -1 };
	pos = checkTwoBox('O');
	if (pos.X != -1 && pos.Y != -1) {
		PutLetter('O', pos.X, pos.Y);
		return;
	}
	
	pos = checkTwoBox('X');
	if (pos.X != -1 && pos.Y != -1) {
		PutLetter('O', (int)pos.X, (int)pos.Y);
		return;
	}

	if (isEmptyBox(5)) {
		PutLetter('O', 1, 1);
		return;
	}
	else if (isEmptyBox(2)) {
		PutLetter('O', 0, 1);
		return;
	}
	else if (isEmptyBox(4)) {
		PutLetter('O', 1, 0);
		return;
	}
	else if (isEmptyBox(6)) {
		PutLetter('O', 1, 2);
		return;
	}
	else if (isEmptyBox(8)) {
		PutLetter('O', 2, 1);
		return;
	}
	else if (isEmptyBox(1)) {
		PutLetter('O', 0, 0);

		return;
	}
	else if (isEmptyBox(3)) {
		PutLetter('O', 0, 2);
		return;
	}
	else if (isEmptyBox(7)) {
		PutLetter('O', 2, 0);
		return;
	}
	else if (isEmptyBox(9)) {
		PutLetter('O', 2, 2);
		return;
	}
	//2 4 6 8
	//1 3 7 9

}


void ClearHeuristicBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			HeuristicBoard[i][j] = 0;
		}
	}
}

COORD checkBoxForHeuristic(char OX, int charnum, int ranking) {
	
	int count;
	int zero;
	COORD pos = { -1, -1 };
	for (int j = 0; j < 3; j++) {
		count = 0;
		zero = 0;
		for (int i = 0; i < 3; i++) {
			if (board[j][i] == OX) {
				count++;
				HeuristicBoard[j][i] += heuristicNum[ranking];
			}
			else if (board[j][i] == 0) {
				zero++;
				HeuristicBoard[j][i] += heuristicNum[ranking];
			}
		}
		if (count != charnum || zero != (2 - charnum)) {
			ClearHeuristicBoard();
		}
	}
	
	int j;
	for (int i = 0; i < 3; i++) {
		count = 0;
		zero = 0;
		for (j = 0; j < 3; j++) {
			if (board[j][i] == OX) {
				count++;
				HeuristicBoard[j][i] += heuristicNum[ranking];
			}
			else if (board[j][i] == 0) {
				zero++;
				HeuristicBoard[j][i] += heuristicNum[ranking];
			}
		}
		if (count != charnum || zero != (2 - charnum)) {
			ClearHeuristicBoard();
		}
	}
	

	count = 0;
	zero = 0;

	for (int i = 0; i < 3; i++) {
		if (board[i][i] == OX) {
			count++;
			HeuristicBoard[i][i] += heuristicNum[ranking];

			
		}
		else if (board[i][i] == 0) {
			zero++;
			HeuristicBoard[i][i] += heuristicNum[ranking];
			
		}
		if (count != charnum || zero != (2 - charnum)) {
			ClearHeuristicBoard();
		}

	}
	
	count = 0;
	zero = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][2 - i] == OX) {
			count++;
			HeuristicBoard[i][2 - i] += heuristicNum[ranking];
		}
		else if (board[i][2 - i] == 0) {
			zero++;
			HeuristicBoard[i][2 - i] += heuristicNum[ranking];
		}
		if (count != charnum || zero != 2 - charnum) {
			ClearHeuristicBoard();
		}
		else;
	}

	
	int max = 0;
	int maxX = 0;
	int maxY = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((isEmpty(i, j)) && (HeuristicBoard[i][j] >= max)) {
				max = HeuristicBoard[i][j];
				maxX = i;
				maxY = j;
			}
		}
	}
	

	COORD maxcoord = { -1,-1 };
	maxcoord.X = maxX;
	maxcoord.Y = maxY;

	return maxcoord;
}

void calcHeuristicCell() {
	
	if (checkBoxForHeuristic('O', 2, 0).X != -1 && checkBoxForHeuristic('O', 2, 0).Y != -1) {
		COORD a = checkBoxForHeuristic('O', 2, 0);
		PutLetter('O', a.X, a.Y);
	}
	else if (checkBoxForHeuristic('X', 2, 1).X != -1 && checkBoxForHeuristic('X', 2, 1).Y != -1) {
		COORD b = checkBoxForHeuristic('X', 2, 1);
		PutLetter('O', b.X, b.Y);
	}
	else if (checkBoxForHeuristic('O', 1, 2).X != -1 && checkBoxForHeuristic('O', 1, 2).Y != -1) {
		COORD c = checkBoxForHeuristic('O', 1, 2);
		PutLetter('O', c.X, c.Y);
	}
	else if (checkBoxForHeuristic('X', 1, 3).X != -1 && checkBoxForHeuristic('X', 1, 3).Y != -1) {
		COORD d = checkBoxForHeuristic('X', 1, 3);
		PutLetter('O', d.X, d.Y);
	}
	else if (checkBoxForHeuristic('O', 0, 4).X != -1 && checkBoxForHeuristic('O', 0, 4).X != -1) {
		COORD e = checkBoxForHeuristic('O', 0, 4);
		PutLetter('O', e.X, e.Y);
	}
	return;
}


COORD calcMaxCell() {
	int value[3][3] = { 0 };


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X') {
				value[i][0]++;
				value[i][1]++;
				value[i][2]++;
			}
			else if (board[i][j] == 'O') {
				value[i][0]--;
				value[i][1]--;
				value[i][2]--;
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[j][i] == 'X') {
				value[0][i]++;
				value[1][i]++;
				value[2][i]++;
			}
			else if (board[j][i] == 'O') {
				value[0][i]--;
				value[1][i]--;
				value[2][i]--;
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		if (board[i][i] == 'X') {
			value[0][0]++;
			value[1][1]++;
			value[2][2]++;
		}
		else if (board[i][i] == 'O') {
			value[0][0]--;
			value[1][1]--;
			value[2][2]--;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		if (board[i][2 - i] == 'X') {
			
			value[0][2]++;
			value[1][1]++;
			value[2][0]++;
		}
		else if (board[i][2 - i] == 'O') {
			
			value[0][2]--;
			value[1][1]--;
			value[2][0]--;
		}
	}

	int max = 0;
	int maxX = 0;
	int maxY = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((isEmpty(i, j)) && (value[i][j] >= max)) {
				
				max = value[i][j];
				maxX = i;
				maxY = j;
			}
		}
	}
	

	COORD maxcoord;
	maxcoord.X = maxX;
	maxcoord.Y = maxY;

	return maxcoord;
}

void dumb() {
	

	COORD a = calcMaxCell();
	int x = a.X;
	int y = a.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CommandPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("                              ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CommandPos);
	printf("#$%#$#%");
	Sleep(1000);
	PutLetter('O', x, y);
}

void smart() {
	Sleep(1000);
	calcHeuristicCell();

}

void ComputerTurn() {
	switch (mode) {
	case 0: random('O');
		break;
	case 1:	dumber();
		break;
	case 2: dumb();
		break;
	case 3: smart();
		break;
	}
	if (isGameFinished('O')) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), WinResultPos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WINRESULTCOLOR);
		printf("Computer Win");
		GameAgainMessage();
	}
}

void GameAgainMessage()
{
	int input;

	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), GameAgainPos);
		printf("Game Menu(1), Quit(0):                          ");
		scanf("%d", &input);
		if (input == 1) {
			system("cls");
			menuSelection();
		}
		else if (input == 0) {
			finish();
		}
	}
}

void GameDrawMessage() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), WinResultPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WINRESULTCOLOR);
	printf("Draw!!");
}

void PlayHumanFirst() {
	initBoard();

	for (int i = 0; i < 4; i++) {
		HumanTurn('X');
		ComputerTurn();
	}
	HumanTurn('X');

	GameDrawMessage();
	GameAgainMessage();
}

void PlayComputerFirst() {
	initBoard();

	for (int i = 0; i < 4; i++) {
		ComputerTurn();
		HumanTurn('X');
	}
	ComputerTurn();
	if (isGameFinished('O'))
		return;
	GameDrawMessage();
	GameAgainMessage();
}

void comvscom() {
	initBoard();

	for (int i = 0; i < 4; i++) {
		ComputerTurn();
		random('X');
		if (isGameFinished('X')) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), WinResultPos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WINRESULTCOLOR);
			printf("X(Random Computer) Win");
			GameAgainMessage();
		}
	}
	ComputerTurn();
	GameDrawMessage();
	GameAgainMessage();
}



void finish() {
	system("cls");
	exit(1);
}

int main() {
	CursorView(0);
	menuSelection();
}
