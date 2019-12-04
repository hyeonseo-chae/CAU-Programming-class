/*
* AniPang:
* This is a basic graphical interface of AniPang game.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "anipang.h"
#include "draw.h"


void check_three(Board *board,int tile[2],int move[2]);

void mkBoard(Board *board, int xsize, int ysize, int nitems)
{
	int i, j;

	board->xsize = xsize;
	board->ysize = ysize;
	board->nitems = nitems;
	board->timeout = 60;  // in seconds
	board->time = board->timeout;
	board->score = 0;
	for (i = 0; i < ysize; i++)
		for (j = 0; j < xsize; j++)
		{
			board->tiles[i][j] = rand() % nitems + 1;
		}
	// 생성된 보드에서 3개 이상 연속된 값이 없도록 만들어야 한다
}


void gameInit(Board *board)
{
    srand((unsigned)time(0));
    mkBoard(board, XSIZE, YSIZE, NUM_ITEM);
}


// curr: 마우스가 클릭된 타일 위치를 알려준다.
// move: 마우스가 움직인 방향을 알려준다. (0, 1), (0, -1), (1, 0), (-1, 0) 중의 하나이다.
void mouseMotion(Board* board, int tile[2], int move[2])
{
	
	// 마우스를 이용하여 타일을 움직였을 때 해당 내용을 구현해야 한다
	printf("(%d, %d) move by (%d, %d)\n", tile[0], tile[1], move[0], move[1]); // 디버깅 코드. 지워도 됩니다.
	int swap1;
	swap1 = board->tiles[tile[1]][tile[0]];
	board->tiles[tile[1]][tile[0]] =board->tiles[tile[1]+move[1]][tile[0]+move[0]];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = swap1; //swqp으로 마우스 드래그 전환
	Sleep(100);
	display();
	check_three(board, tile, move);
	
}


// 보드를 변화시키고 화면에 반영하는 예제 코드
void testRemove(Board *board)
{
    int i, k, n = 3;

    for (k = 0; k < n; k++)
        board->tiles[5 - k][5] = 0;  // 타일 값이 0일 경우 폭발 그림이 출력된다
    display();  // 화면에 변화된 보드를 그린다
    Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
    for (i = 0; i < n; i++) {
        for (k = 5; k > 0; k--) {
            board->tiles[k][5] = board->tiles[k - 1][5];
        }
        board->tiles[0][5] = rand() % board->nitems + 1;
        display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
		            // 내용이 변화되어도 화면에 나타나지 않는다.
        Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
    }
}

void RemoveDown(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[1] + move[1];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1] + 1][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1] + 2][tile[0] + move[0]] = 0;
	display();  // 화면에 변화된 보드를 그린다
	Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	for (i = 0; i < n; i++) {
		for (k = tile[1] + move[1] + 2; k > 0; k--) {
			board->tiles[k][f] = board->tiles[k - 1][f];
		}
		board->tiles[0][f] = rand() % board->nitems + 1;
		display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
					// 내용이 변화되어도 화면에 나타나지 않는다.
		Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	}
}
	void RemoveUp(Board * board, int f, int tile[2], int move[2]) {
		int i, k, n = 3;
		k = tile[1] + move[1];
		board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] - 2][tile[0] + move[0]] = 0;
		display();  // 화면에 변화된 보드를 그린다
		Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		for (i = 0; i < n; i++) {
			for (k = tile[1] + move[1]; k > 0; k--) {
				board->tiles[k][f] = board->tiles[k - 1][f];
			}
			board->tiles[0][f] = rand() % board->nitems + 1;
			display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
						// 내용이 변화되어도 화면에 나타나지 않는다.
			Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		}
	}

	void RemoveUpM(Board* board, int f, int tile[2], int move[2]) {
		int i, k, n = 3;
		k = tile[1] + move[1];
		board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] +1][tile[0] + move[0]] = 0;
		display();  // 화면에 변화된 보드를 그린다
		Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		for (i = 0; i < n; i++) {
			for (k = tile[1] + move[1]+1; k > 0; k--) {
				board->tiles[k][f] = board->tiles[k - 1][f];
			}
			board->tiles[0][f] = rand() % board->nitems + 1;
			display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
						// 내용이 변화되어도 화면에 나타나지 않는다.
			Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		}
	}
	
void RemoveCrossM(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[0] + move[0];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] - 1 + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] = 0;
	display();  // 화면에 변화된 보드를 그린다
	Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	for (i = 0; i < n; i++) {
		for (k = tile[0] + move[0]+1; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k-1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
					// 내용이 변화되어도 화면에 나타나지 않는다.
		Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	}
}

void RemoveCrossL(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[0] + move[0];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] -1+ move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] - 2 + move[0]] = 0;
	display();  // 화면에 변화된 보드를 그린다
	Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	for (i = 0; i < n; i++) {
		for (k = tile[0] + move[0] ; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k - 1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
					// 내용이 변화되어도 화면에 나타나지 않는다.
		Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	}
}

void RemoveCrossR(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[0] + move[0];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] + 1 + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] + 2 + move[0]] = 0;
	display();  // 화면에 변화된 보드를 그린다
	Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	for (i = 0; i < n; i++) {
		for (k = tile[0] + move[0]+2; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k - 1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
					// 내용이 변화되어도 화면에 나타나지 않는다.
		Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	}
}

void check_three(Board* board,int tile[2],int move[2]) {
	
	if (board->tiles[tile[1]+move[1]][tile[0]+move[0]] == board->tiles[tile[1] + move[1]][tile[0] - 1+move[0]] && board->tiles[tile[1] + move[1]][tile[0]-1+move[0]] == board->tiles[tile[1] + move[1]][tile[0]-2+move[0]]) {
		printf("왼쪽 3개 일치합니다.\n"); // 왼쪽으로 드래그 후 드래그 기준 왼쪽 3개 판단
		RemoveCrossL(board, tile[1] + move[1], tile, move);
		
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] && board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] +2 + move[0]]) {
		printf("오른쪽 3개 일치합니다.\n"); // 오른쪽으로 드래그 후 드래그 기준 오른쪽 3개 판단
		RemoveCrossR(board, tile[1] + move[1], tile, move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0]+1] && board->tiles[tile[1] + move[1]][tile[0] -1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0]]) {
		printf("가로 가운대 3개 일치합니다.\n"); // 위아래로 드래그 후 드래그 기준 가운데 3개 판단
		RemoveCrossM(board, tile[1] + move[1], tile, move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]-1][tile[0]+ move[0]] && board->tiles[tile[1] + move[1]-1][tile[0] + move[0]] == board->tiles[tile[1] + move[1]-2][tile[0] + move[0]]) {
		printf("위쪽 3개 일치합니다.\n"); // 옆으로 드래그 후 드래그 기준 위쪽 3개 판단
		RemoveUp(board, tile[0] + move[0],tile,move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]+1][tile[0] + move[0]] && board->tiles[tile[1] + move[1]+1][tile[0] + move[0]] == board->tiles[tile[1] + move[1]+2][tile[0] + move[0]]) {
		printf("아래쪽 3개 일치합니다.\n"); //옆으로 드래그 후 드래그 기준 아래 3개 판단
		RemoveDown(board, tile[0] + move[0], tile, move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + 1][tile[0] + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] +-1][tile[0] + move[0]]) {
		printf("세로 가운데 3개 일치합니다.\n"); //옆 드래그 후 드래그 기준 세로 가운데 3개 판단
		RemoveUpM(board, tile[0] + move[0],  tile, move);
	}
	else {
		Sleep(100);
		int swap1;
		swap1 = board->tiles[tile[1] + move[1]][tile[0] + move[0]];
		board->tiles[tile[1] + move[1]][tile[0] + move[0]] = board->tiles[tile[1]][tile[0]];
		board->tiles[tile[1]][tile[0]] = swap1;
		display();
	}
	return;
}


int main(int argc, char** argv)
{
    Board board;

    gameInit(&board);
    gameStart(&board);

    return 0;
}
