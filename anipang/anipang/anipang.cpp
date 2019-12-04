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
	// ������ ���忡�� 3�� �̻� ���ӵ� ���� ������ ������ �Ѵ�
}


void gameInit(Board *board)
{
    srand((unsigned)time(0));
    mkBoard(board, XSIZE, YSIZE, NUM_ITEM);
}


// curr: ���콺�� Ŭ���� Ÿ�� ��ġ�� �˷��ش�.
// move: ���콺�� ������ ������ �˷��ش�. (0, 1), (0, -1), (1, 0), (-1, 0) ���� �ϳ��̴�.
void mouseMotion(Board* board, int tile[2], int move[2])
{
	
	// ���콺�� �̿��Ͽ� Ÿ���� �������� �� �ش� ������ �����ؾ� �Ѵ�
	printf("(%d, %d) move by (%d, %d)\n", tile[0], tile[1], move[0], move[1]); // ����� �ڵ�. ������ �˴ϴ�.
	int swap1;
	swap1 = board->tiles[tile[1]][tile[0]];
	board->tiles[tile[1]][tile[0]] =board->tiles[tile[1]+move[1]][tile[0]+move[0]];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = swap1; //swqp���� ���콺 �巡�� ��ȯ
	Sleep(100);
	display();
	check_three(board, tile, move);
	
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

void RemoveDown(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[1] + move[1];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1] + 1][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1] + 2][tile[0] + move[0]] = 0;
	display();  // ȭ�鿡 ��ȭ�� ���带 �׸���
	Sleep(300); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	for (i = 0; i < n; i++) {
		for (k = tile[1] + move[1] + 2; k > 0; k--) {
			board->tiles[k][f] = board->tiles[k - 1][f];
		}
		board->tiles[0][f] = rand() % board->nitems + 1;
		display();  // ȭ�鿡 ��ȭ�� ���带 �׸���. �� �Լ��� ȣ������ ������ 
					// ������ ��ȭ�Ǿ ȭ�鿡 ��Ÿ���� �ʴ´�.
		Sleep(100); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	}
}
	void RemoveUp(Board * board, int f, int tile[2], int move[2]) {
		int i, k, n = 3;
		k = tile[1] + move[1];
		board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] - 2][tile[0] + move[0]] = 0;
		display();  // ȭ�鿡 ��ȭ�� ���带 �׸���
		Sleep(300); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
		for (i = 0; i < n; i++) {
			for (k = tile[1] + move[1]; k > 0; k--) {
				board->tiles[k][f] = board->tiles[k - 1][f];
			}
			board->tiles[0][f] = rand() % board->nitems + 1;
			display();  // ȭ�鿡 ��ȭ�� ���带 �׸���. �� �Լ��� ȣ������ ������ 
						// ������ ��ȭ�Ǿ ȭ�鿡 ��Ÿ���� �ʴ´�.
			Sleep(100); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
		}
	}

	void RemoveUpM(Board* board, int f, int tile[2], int move[2]) {
		int i, k, n = 3;
		k = tile[1] + move[1];
		board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]] = 0;
		board->tiles[tile[1] + move[1] +1][tile[0] + move[0]] = 0;
		display();  // ȭ�鿡 ��ȭ�� ���带 �׸���
		Sleep(300); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
		for (i = 0; i < n; i++) {
			for (k = tile[1] + move[1]+1; k > 0; k--) {
				board->tiles[k][f] = board->tiles[k - 1][f];
			}
			board->tiles[0][f] = rand() % board->nitems + 1;
			display();  // ȭ�鿡 ��ȭ�� ���带 �׸���. �� �Լ��� ȣ������ ������ 
						// ������ ��ȭ�Ǿ ȭ�鿡 ��Ÿ���� �ʴ´�.
			Sleep(100); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
		}
	}
	
void RemoveCrossM(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[0] + move[0];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] - 1 + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] = 0;
	display();  // ȭ�鿡 ��ȭ�� ���带 �׸���
	Sleep(300); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	for (i = 0; i < n; i++) {
		for (k = tile[0] + move[0]+1; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k-1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // ȭ�鿡 ��ȭ�� ���带 �׸���. �� �Լ��� ȣ������ ������ 
					// ������ ��ȭ�Ǿ ȭ�鿡 ��Ÿ���� �ʴ´�.
		Sleep(100); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	}
}

void RemoveCrossL(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[0] + move[0];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] -1+ move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] - 2 + move[0]] = 0;
	display();  // ȭ�鿡 ��ȭ�� ���带 �׸���
	Sleep(300); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	for (i = 0; i < n; i++) {
		for (k = tile[0] + move[0] ; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k - 1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // ȭ�鿡 ��ȭ�� ���带 �׸���. �� �Լ��� ȣ������ ������ 
					// ������ ��ȭ�Ǿ ȭ�鿡 ��Ÿ���� �ʴ´�.
		Sleep(100); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	}
}

void RemoveCrossR(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 3;
	k = tile[0] + move[0];
	board->tiles[tile[1] + move[1]][tile[0] + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] + 1 + move[0]] = 0;
	board->tiles[tile[1] + move[1]][tile[0] + 2 + move[0]] = 0;
	display();  // ȭ�鿡 ��ȭ�� ���带 �׸���
	Sleep(300); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	for (i = 0; i < n; i++) {
		for (k = tile[0] + move[0]+2; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k - 1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // ȭ�鿡 ��ȭ�� ���带 �׸���. �� �Լ��� ȣ������ ������ 
					// ������ ��ȭ�Ǿ ȭ�鿡 ��Ÿ���� �ʴ´�.
		Sleep(100); // �ʹ� ������ ������ �Ⱥ��̹Ƿ� ������ �ð����� ��ٸ���
	}
}

void check_three(Board* board,int tile[2],int move[2]) {
	
	if (board->tiles[tile[1]+move[1]][tile[0]+move[0]] == board->tiles[tile[1] + move[1]][tile[0] - 1+move[0]] && board->tiles[tile[1] + move[1]][tile[0]-1+move[0]] == board->tiles[tile[1] + move[1]][tile[0]-2+move[0]]) {
		printf("���� 3�� ��ġ�մϴ�.\n"); // �������� �巡�� �� �巡�� ���� ���� 3�� �Ǵ�
		RemoveCrossL(board, tile[1] + move[1], tile, move);
		
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] && board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] +2 + move[0]]) {
		printf("������ 3�� ��ġ�մϴ�.\n"); // ���������� �巡�� �� �巡�� ���� ������ 3�� �Ǵ�
		RemoveCrossR(board, tile[1] + move[1], tile, move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0]+1] && board->tiles[tile[1] + move[1]][tile[0] -1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0]]) {
		printf("���� ����� 3�� ��ġ�մϴ�.\n"); // ���Ʒ��� �巡�� �� �巡�� ���� ��� 3�� �Ǵ�
		RemoveCrossM(board, tile[1] + move[1], tile, move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]-1][tile[0]+ move[0]] && board->tiles[tile[1] + move[1]-1][tile[0] + move[0]] == board->tiles[tile[1] + move[1]-2][tile[0] + move[0]]) {
		printf("���� 3�� ��ġ�մϴ�.\n"); // ������ �巡�� �� �巡�� ���� ���� 3�� �Ǵ�
		RemoveUp(board, tile[0] + move[0],tile,move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]+1][tile[0] + move[0]] && board->tiles[tile[1] + move[1]+1][tile[0] + move[0]] == board->tiles[tile[1] + move[1]+2][tile[0] + move[0]]) {
		printf("�Ʒ��� 3�� ��ġ�մϴ�.\n"); //������ �巡�� �� �巡�� ���� �Ʒ� 3�� �Ǵ�
		RemoveDown(board, tile[0] + move[0], tile, move);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + 1][tile[0] + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] +-1][tile[0] + move[0]]) {
		printf("���� ��� 3�� ��ġ�մϴ�.\n"); //�� �巡�� �� �巡�� ���� ���� ��� 3�� �Ǵ�
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
