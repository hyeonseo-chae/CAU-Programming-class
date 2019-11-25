#ifndef _ANIPANG_H
#define _ANIPANG_H

#define XSIZE 7
#define YSIZE 7
#define NUM_ITEM  5

// items(board entry) 0: empty, 1~5: animation characters
typedef struct _board {
	int tiles[YSIZE][XSIZE];
	int xsize;
	int ysize;
	int nitems;
	int timeout;
	int time;
	int score;
} Board;

void gameInit(Board *board);
void mouseMotion(Board *board, int tile[2], int move[2]);

void testRemove(Board *board);

#endif