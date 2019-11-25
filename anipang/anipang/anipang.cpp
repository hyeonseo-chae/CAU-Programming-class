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
void mouseMotion(Board *board, int tile[2], int move[2])
{
	// 마우스를 이용하여 타일을 움직였을 때 해당 내용을 구현해야 한다
	printf("(%d, %d) move by (%d, %d)\n", tile[0], tile[1], move[0], move[1]); // 디버깅 코드. 지워도 됩니다.
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



int main(int argc, char** argv)
{
    Board board;

    gameInit(&board);
    gameStart(&board);

    return 0;
}
