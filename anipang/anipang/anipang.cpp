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
	// ������ ���忡�� 3�� �̻� ���ӵ� ���� ������ ������ �Ѵ�
}


void gameInit(Board *board)
{
    srand((unsigned)time(0));
    mkBoard(board, XSIZE, YSIZE, NUM_ITEM);
}


// curr: ���콺�� Ŭ���� Ÿ�� ��ġ�� �˷��ش�.
// move: ���콺�� ������ ������ �˷��ش�. (0, 1), (0, -1), (1, 0), (-1, 0) ���� �ϳ��̴�.
void mouseMotion(Board *board, int tile[2], int move[2])
{
	// ���콺�� �̿��Ͽ� Ÿ���� �������� �� �ش� ������ �����ؾ� �Ѵ�
	printf("(%d, %d) move by (%d, %d)\n", tile[0], tile[1], move[0], move[1]); // ����� �ڵ�. ������ �˴ϴ�.
}


// ���带 ��ȭ��Ű�� ȭ�鿡 �ݿ��ϴ� ���� �ڵ�
void testRemove(Board *board)
{
    int i, k, n = 3;

    for (k = 0; k < n; k++)
        board->tiles[5 - k][5] = 0;  // Ÿ�� ���� 0�� ��� ���� �׸��� ��µȴ�
    display();  // ȭ�鿡 ��ȭ�� ���带 �׸���
    Sleep(300); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
    for (i = 0; i < n; i++) {
        for (k = 5; k > 0; k--) {
            board->tiles[k][5] = board->tiles[k - 1][5];
        }
        board->tiles[0][5] = rand() % board->nitems + 1;
        display();  // ȭ�鿡 ��ȭ�� ���带 �׸���. �� �Լ��� ȣ������ ������ 
		            // ������ ��ȭ�Ǿ ȭ�鿡 ��Ÿ���� �ʴ´�.
        Sleep(100); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
    }
}



int main(int argc, char** argv)
{
    Board board;

    gameInit(&board);
    gameStart(&board);

    return 0;
}
