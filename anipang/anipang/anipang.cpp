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


void check_t(Board* board,int tile[2],int move[2]);
void first_check(Board *board);
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
	// first_check 함수로 없도록 만듬.
	
}


void gameInit(Board *board)
{
    srand((unsigned)time(0));
    mkBoard(board, XSIZE, YSIZE, NUM_ITEM);
	first_check(board);// first_check 함수로 처음 3개 이상 중복 없도록 만듬.
	
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
	check_t(board, tile, move);
	
}


// 보드를 변화시키고 화면에 반영하는 예제 코드


void testRemove(Board* board) {

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
		board->score = board->score + 3;
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
		board->score = board->score + 3;
	}

	void RemoveUp41(Board* board, int f, int tile[2], int move[2]) {
		int i, k, n = 7;
		k = tile[1] + move[1];
		for (int i = 0; i <= 6; i++) {
			board->tiles[i][tile[0] + move[0]] = 0;
		}

		
		display();  // 화면에 변화된 보드를 그린다
		Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		for (i = 0; i < n; i++) {
			for (k =6; k > 0; k--) {
				board->tiles[k][f] = board->tiles[k - 1][f];
			}
			board->tiles[0][f] = rand() % board->nitems + 1;
			display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
						// 내용이 변화되어도 화면에 나타나지 않는다.
			Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		}
		board->score = board->score + 7;
	}

	void RemoveUp42(Board* board, int f, int tile[2], int move[2]) {
		int i, k, n = 7;
		k = tile[1] + move[1];
		for (int i = 0; i <= 6; i++) {
			board->tiles[i][tile[0] + move[0]] = 0;
		}

		display();  // 화면에 변화된 보드를 그린다
		Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		for (i = 0; i < n; i++) {
			for (k = 6; k > 0; k--) {
				board->tiles[k][f] = board->tiles[k - 1][f];
			}
			board->tiles[0][f] = rand() % board->nitems + 1;
			display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
						// 내용이 변화되어도 화면에 나타나지 않는다.
			Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		}
		board->score = board->score + 7;
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
		board->score = board->score + 3;
	}

	void RemoveUpM5(Board* board, int f, int tile[2], int move[2]) {
		int i, k, n = 7;
		k = tile[1] + move[1];
		for (int i = 0; i <= 6; i++) {
			board->tiles[i][tile[0] + move[0]] = 0;
		}
		
		display();  // 화면에 변화된 보드를 그린다
		Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		for (i = 0; i < n; i++) {
			for (k = 6; k > 0; k--) {
				board->tiles[k][f] = board->tiles[k - 1][f];
			}
			board->tiles[0][f] = rand() % board->nitems + 1;
			display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
						// 내용이 변화되어도 화면에 나타나지 않는다.
			Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
		}
		board->score = board->score + 7;
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
	board->score = board->score + 3;
}


void RemoveCrossM5(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 7;
	k = tile[0] + move[0];
	for (int i = 0; i <= 6; i++) {
		board->tiles[tile[1] + move[1]][i] = 0;
	}

	
	display();  // 화면에 변화된 보드를 그린다
	Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	for (i = 0; i < n; i++) {
		for (k = 6; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k - 1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
					// 내용이 변화되어도 화면에 나타나지 않는다.
		Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	}
	board->score = board->score + 7;
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
	board->score = board->score + 3;
}

void RemoveCrossL4(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 7;
	k = tile[0] + move[0];
	for (int i = 0; i <= 6; i++) {
		board->tiles[tile[1] + move[1]][i] = 0;
	}
	
	display();  // 화면에 변화된 보드를 그린다
	Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	for (i = 0; i < n; i++) {
		for (k = 6; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k - 1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
					// 내용이 변화되어도 화면에 나타나지 않는다.
		Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	}
	board->score = board->score + 7;
}

void RemoveCrossR4(Board* board, int f, int tile[2], int move[2]) {
	int i, k, n = 7;
	k = tile[0] + move[0];
	for (int i = 0; i <= 6; i++) {
		board->tiles[tile[1] + move[1]][i] = 0;
	}
	
	display();  // 화면에 변화된 보드를 그린다
	Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	for (i = 0; i < n; i++) {
		for (k = 6; k > 0; k--) {
			board->tiles[f][k] = board->tiles[f][k - 1];
		}
		board->tiles[f][0] = rand() % board->nitems + 1;
		display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
					// 내용이 변화되어도 화면에 나타나지 않는다.
		Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
	}
	board->score = board->score + 7;
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
	board->score = board->score + 3;
}

void first_check(Board* board) {
	int i, j, k, n = 3;
	for (i = 0; i <= 6; i++) {
		for (j = 1; j <= 5; j++) {
			if (board->tiles[i][j] == board->tiles[i][j - 1] && board->tiles[i][j] == board->tiles[i][j + 1]) {
				board->tiles[i][j] = 0;
				board->tiles[i][j - 1] = 0;
				board->tiles[i][j + 1] = 0;


				for (int g = 0; g < n; g++) {
					for (k = j + 1; k > 0; k--) {
						board->tiles[i][k] = board->tiles[i][k - 1];
					}
					board->tiles[i][0] = rand() % board->nitems + 1;


				}
			}


		}
	}
	for (i = 1; i <= 5; i++) {
		for (j = 0; j <= 6; j++) {
			if (board->tiles[i - 1][j] == board->tiles[i][j] && board->tiles[i][j] == board->tiles[i + 1][j]) {
				board->tiles[i][j] = 0;
				board->tiles[i - 1][j] = 0;
				board->tiles[i + 1][j] = 0;

				for (int g = 0; g < n; g++) {
					for (k = i + 1; k > 0; k--) {
						board->tiles[k][j] = board->tiles[k - 1][j];
					}
					board->tiles[0][j] = rand() % board->nitems + 1;

				}
				first_check(board);
			}


		}
	}

	

}

void double_check(Board* board) {
	int i,j, k, n=3 ;
	for (i = 0; i <= 6; i++) {
		for (j = 1; j <= 5; j++) {
			if (board->tiles[i][j] == board->tiles[i][j - 1] && board->tiles[i][j] == board->tiles[i][j + 1]) {
				board->tiles[i][j] = 0;
				board->tiles[i][j-1] = 0;
				board->tiles[i][j+1] = 0;
				board->score = board->score + 3;
				display();  // 화면에 변화된 보드를 그린다
				Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
				for (int g = 0; g < n; g++) {
					for (k = j + 1; k > 0; k--) {
						board->tiles[i][k] = board->tiles[i][k - 1];
					}
					board->tiles[i][0] = rand() % board->nitems + 1;
					display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
								// 내용이 변화되어도 화면에 나타나지 않는다.
					Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
					
					double_check(board);
				}
			}
			
			
		}
	}
	for (i = 1; i <= 5; i++) {
		for (j = 0; j <= 6; j++) {
			if (board->tiles[i-1][j] == board->tiles[i][j] && board->tiles[i][j] == board->tiles[i+1][j]) {
				board->tiles[i][j] = 0;
				board->tiles[i-1][j] = 0;
				board->tiles[i+1][j] = 0;
				board->score = board->score + 3;
				display();  // 화면에 변화된 보드를 그린다
				Sleep(300); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
				for (int g = 0; g < n; g++) {
					for (k = i + 1; k > 0; k--) {
						board->tiles[k][j] = board->tiles[k-1][j];
					}
					board->tiles[0][j] = rand() % board->nitems + 1;
					display();  // 화면에 변화된 보드를 그린다. 이 함수를 호출하지 않으면 
								// 내용이 변화되어도 화면에 나타나지 않는다.
					
					Sleep(100); // 너무 빠르면 과정이 안보이므로 적당한 시간동안 기다린다
				}
			}


		}
	}
	
	

}

void check_t(Board* board,int tile[2],int move[2]) {
	

     if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0] + 1]&& board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0] + 2]&& board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0] -2] && board->tiles[tile[1] + move[1]][tile[0] - 1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0]]) {
		printf("가로 가운대 5개 일치합니다.\n"); // 위아래로 드래그 후 드래그 기준 가운데 5개 판단
		RemoveCrossM5(board, tile[1] + move[1], tile, move); 
		double_check(board);
	}
	 else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + 1][tile[0] + move[0]]&& board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + 2][tile[0] + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] -2][tile[0] + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + -1][tile[0] + move[0]]) {
		 printf("세로 가운데 5개 일치합니다.\n"); //옆 드래그 후 드래그 기준 세로 가운데 5개 판단
		 RemoveUpM5(board, tile[0] + move[0], tile, move);
		 double_check(board);
	 }
	 else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] - 1 + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + 1 + move[0]] && board->tiles[tile[1] + move[1]][tile[0] - 1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] - 2 + move[0]]) {
		printf("왼쪽 4개 일치합니다.\n"); // 왼쪽으로 드래그 후 드래그 기준 왼쪽 4개 판단
		RemoveCrossL4(board, tile[1] + move[1], tile, move);
		double_check(board);

	}
	 else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + 1 + move[0]]&& board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] -1 + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + 1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + 2 + move[0]]) {
		 printf("오른쪽 4개 일치합니다.\n"); // 오른쪽으로 드래그 후 드래그 기준 오른쪽 4개 판단
		 RemoveCrossR4(board, tile[1] + move[1], tile, move);
		 double_check(board);
	 }
	 else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]]&& board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] +1][tile[0] + move[0]] && board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]] == board->tiles[tile[1] + move[1] - 2][tile[0] + move[0]]) {
		 printf("위쪽 4개 일치합니다.\n"); // 옆으로 드래그 후 드래그 기준 위쪽 4개 판단
		 RemoveUp41(board, tile[0] + move[0], tile, move);
		 double_check(board);
	 }
	 else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + 1][tile[0] + move[0]] && board->tiles[tile[1] + move[1] - 1][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + 2][tile[0] + move[0]]) {
		 printf("아래쪽 4개 일치합니다.\n"); // 옆으로 드래그 후 드래그 기준 아래 4개 판단
		 RemoveUp42(board, tile[0] + move[0], tile, move);
		 double_check(board);
	 }
	else if (board->tiles[tile[1]+move[1]][tile[0]+move[0]] == board->tiles[tile[1] + move[1]][tile[0] - 1+move[0]] && board->tiles[tile[1] + move[1]][tile[0]-1+move[0]] == board->tiles[tile[1] + move[1]][tile[0]-2+move[0]]) {
		printf("왼쪽 3개 일치합니다.\n"); // 왼쪽으로 드래그 후 드래그 기준 왼쪽 3개 판단
		RemoveCrossL(board, tile[1] + move[1], tile, move);
		double_check(board);
		
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] && board->tiles[tile[1] + move[1]][tile[0] +1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] +2 + move[0]]) {
		printf("오른쪽 3개 일치합니다.\n"); // 오른쪽으로 드래그 후 드래그 기준 오른쪽 3개 판단
		RemoveCrossR(board, tile[1] + move[1], tile, move);
		double_check(board);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0]+1] && board->tiles[tile[1] + move[1]][tile[0] -1 + move[0]] == board->tiles[tile[1] + move[1]][tile[0] + move[0]]) {
		printf("가로 가운대 3개 일치합니다.\n"); // 위아래로 드래그 후 드래그 기준 가운데 3개 판단
		RemoveCrossM(board, tile[1] + move[1], tile, move);
		double_check(board);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]-1][tile[0]+ move[0]] && board->tiles[tile[1] + move[1]-1][tile[0] + move[0]] == board->tiles[tile[1] + move[1]-2][tile[0] + move[0]]) {
		printf("위쪽 3개 일치합니다.\n"); // 옆으로 드래그 후 드래그 기준 위쪽 3개 판단
		RemoveUp(board, tile[0] + move[0],tile,move);
		double_check(board);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1]+1][tile[0] + move[0]] && board->tiles[tile[1] + move[1]+1][tile[0] + move[0]] == board->tiles[tile[1] + move[1]+2][tile[0] + move[0]]) {
		printf("아래쪽 3개 일치합니다.\n"); //옆으로 드래그 후 드래그 기준 아래 3개 판단
		RemoveDown(board, tile[0] + move[0], tile, move);
		double_check(board);
	}
	else if (board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] + 1][tile[0] + move[0]] && board->tiles[tile[1] + move[1]][tile[0] + move[0]] == board->tiles[tile[1] + move[1] +-1][tile[0] + move[0]]) {
		printf("세로 가운데 3개 일치합니다.\n"); //옆 드래그 후 드래그 기준 세로 가운데 3개 판단
		RemoveUpM(board, tile[0] + move[0],  tile, move);
		double_check(board);
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
