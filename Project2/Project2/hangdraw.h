#ifndef _HANGDRAW_H
#define _HANGDRAW_H

#include<windows.h>

#define WINX  5		// �׸��� �׸��� �� ���� ��ġ
#define WINY  2		// �׸��� �׸��� �� ���� ��ġ
#define TEXTX  WINX			// �ؽ�Ʈ�� �׸��� �� ���� ��ġ
#define TEXTY  (WINY+10)	// �ؽ�Ʈ�� �׸��� �� ���� ��ġ
#define Win   100	// �̰��� ���� ��� - drawHangman�� �Է� �Ķ����
#define NCHANCE 8	// ���ڸ� ������ �� �ִ� ��ȸ�� ��

// Functions
void clrscr(); // ȭ���� ����
void gotoxy(int x, int y); //�ܼ� ȭ���� (x, y) ��ġ�� �̵�
void setColor(WORD color); //��Ʈ �� ��� �� ����

// hangman�� �׸�
// mode �� 0: ��ü Ʋ�� �׸�
// mode �� 1~7: �Ŵ޸��� ������ �ϳ��� �׸�
// mode �� 8 == NCHANCE: ���ӿ� ���� ���� ȭ�� ���
// mode �� Win : ���ӿ� �̰��� ���� ȭ�� ���
void drawHangman(int mode); 

void drawHangmanTest(); // drawHangman ��� ����


#endif