/*
* Drawing game board.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "GL/glut.h"
#include "bmp.h"
#include "draw.h"

#define MAX_BUF 1024
#define TEXT_HEIGHT 24

GLuint	gTexture[NUM_ITEM + 1];  // Storage For Textures
int gMousePos[2] = { 0, 0 };
int gScreenSize[2] = { 0, 0 };
int gTileMoving = false;
int gGameOver = false;

Board *gb; // pointer to the Board


AUX_RGBImageRec *LoadBMP(char *Filename)    // Loads A Bitmap Image
{
	FILE *File = NULL;  // File Handle
	if (!Filename)      // Make Sure A Filename Was Given
	{
		return NULL;    // If Not Return NULL
	}

	File = fopen(Filename, "r");    // Check To See If The File Exists
	if (File)                       // Does The File Exist?
	{
		fclose(File);               // Close The Handle
		return auxDIBImageLoad(Filename);   // Load The Bitmap And Return A Pointer
	}

	return NULL;    // If Load Failed Return NULL
}


int LoadGLTextures()    // Load Bitmaps And Convert To Textures
{
	int Status = FALSE; // Status Indicator
	char filename[MAX_BUF];
	AUX_RGBImageRec *TextureImage;  // Create Storage Space For The Texture
	int i, num = gb->nitems + 1;

	//memset(TextureImage, 0, sizeof(void *) * 1);    // Set The Pointer To NULL
	glGenTextures(num, &gTexture[0]);					// Create Three Textures

	for (i = 0; i < num; i++)
	{
		// Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
		sprintf(filename, "data/%d.bmp", i);
		if (TextureImage = LoadBMP(filename))
		{
			Status = TRUE;  // Set The Status To TRUE

			// Create Linear Filtered Texture
			glBindTexture(GL_TEXTURE_2D, gTexture[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
		}

		if (TextureImage)                   // If Texture Exists
		{
			if (TextureImage->data)         // If Texture Image Exists
			{
				free(TextureImage->data);   // Free The Texture Image Memory
			}
			free(TextureImage);             // Free The Image Structure
            TextureImage = 0;
		}
	}

	return Status;  // Return The Status
}


void renderString(float x, float y, const char *string) 
{
	const int font = (int)GLUT_BITMAP_TIMES_ROMAN_24; // GLUT_BITMAP_HELVETICA_18;
	const char *c;

	glRasterPos3f(x, y, 0);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter((void *)font, *c);
	}
}

void drawTexts(Board *board)
{
	char text[MAX_BUF];
	float charWidth = 12.0;

	glColor3f(0.6, 0, 0.6);
	snprintf(text, MAX_BUF, " Score: %3d", board->score);
	renderString(0, 0, text);

	if (gGameOver)
	{
		glColor3f(0.3, 0.3, 0.3);
		renderString(gb->xsize * charWidth * 16 / gScreenSize[0], 0, "Game Over. Try Again? (y/n)");
	}

	glColor3f(0, 0, 1);
	snprintf(text, MAX_BUF, "Time: %3d", gb->time);
	renderString(gb->xsize * (1.0 - (charWidth * 10) / gScreenSize[0]), 0, text);
}



void drawTile(Board *board, int i, int j, int id)
{
	float x = i;
	float y = board->ysize - j - 1;
	float margin = 0.1;

	glBindTexture(GL_TEXTURE_2D, gTexture[id]);

	glPushMatrix();
	glTranslatef(x, y, 0);
	glColor3f(1, 1, 1);

	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0 - margin, margin, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(margin, margin, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0 - margin, 1.0 - margin, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(margin, 1.0 - margin, 0.0);
	glEnd();

	glPopMatrix();
}

void drawBoard(Board *board)
{
	int x, y;
	for (y = 0; y < board->ysize; y++)
		for (x = 0; x < board->xsize; x++)
		{
			drawTile(board, x, y, board->tiles[y][x]);
		}
}


void display(void)
{
	glViewport(0, 0, gScreenSize[0], gScreenSize[1] - TEXT_HEIGHT);

	glClear(GL_COLOR_BUFFER_BIT);  // clear all pixels
	drawBoard(gb);

	glViewport(0, gScreenSize[1] - TEXT_HEIGHT, gScreenSize[0], TEXT_HEIGHT);
	drawTexts(gb);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'y': case 'Y':
		if (gGameOver)
		{
			gameInit(gb);
			gGameOver = false;
		}
		break;
	case 'n': case 'N':
		if (gGameOver)
		{
			exit(0);
		}
		break;
	case 't':
        testRemove(gb);
		break;
	case 27:
		exit(0);
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN && !gGameOver) {
			gMousePos[0] = x;
			gMousePos[1] = y - TEXT_HEIGHT;
			gTileMoving = true;
		}
		break;
	default:
		break;
	}
}

void motion(int x0, int y0) // called when a mouse is in motion with a button down
{
	int x = x0, y = y0 - TEXT_HEIGHT;
    int prev[2], curr[2], move[2];
	if (x < 0 || y < TEXT_HEIGHT)  return;
	if (x >= gScreenSize[0] || y >= gScreenSize[1])  return;

    prev[0] = gMousePos[0] * gb->xsize / gScreenSize[0];
    prev[1] = gMousePos[1] * gb->ysize / gScreenSize[1];
    curr[0] = x*gb->xsize / gScreenSize[0];
    curr[1] = y*gb->ysize / gScreenSize[1];

	if (gTileMoving && (prev[0] != curr[0] || prev[1] != curr[1]))
	{
		if (prev[0] != curr[0] && prev[1] != curr[1])
		{
			if (abs(gMousePos[0] - x) > abs(gMousePos[1] - y))
				curr[1] = prev[1];
			else
				curr[0] = prev[0];
		}

		move[0] = curr[0] - prev[0];
		move[1] = curr[1] - prev[1];
		mouseMotion(gb, prev, move);

		gTileMoving = false;
		glutPostRedisplay();
	}
}


void glInit(void)
{
	LoadGLTextures();
	glClearColor(1.0, 1.0, 1.0, 0.0);  // select clearing color
	glEnable(GL_TEXTURE_2D);
}


void reshape(GLsizei w, GLsizei h)
{
	float xmin = 0.0, ymin = 0.0;
	float xmax = 7.0, ymax = 7.0;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  //Reset corrdinate system

	xmax = gb->xsize*1.0;
	ymax = gb->ysize*1.0;
	glOrtho(xmin, xmax, ymin, ymax, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gScreenSize[0] = w;
	gScreenSize[1] = h;
}

void idle()
{
	static int prev_time = 0;
	int curr_time = glutGet(GLUT_ELAPSED_TIME);

	if (abs(curr_time - prev_time) > 1000)
	{
		gb->time--;
		if (gb->time <= 0)  // 게임 시간이 다 되었을 때
		{
			gb->time = 0;
			gGameOver = true;
		}
		prev_time = curr_time;
	}
	glutPostRedisplay();
}


/*
* Declare initial window size, position, and display mode
* Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
void gameStart(Board *board)
{
	int argc = 1;
	char *argv[] = { "anipang" };
    int maxX = 1024, maxY = 800, step = 100;
    int winSizeX, winSizeY;
	
	gb = board;
    if (gb->ysize*step > maxY)  step = maxY / gb->ysize;
    if (gb->xsize*step > maxX)  step = maxX / gb->xsize;
    winSizeX = gb->xsize * step;
    winSizeY = gb->ysize * step + TEXT_HEIGHT;
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winSizeX, winSizeY);
	glutInitWindowPosition(10, 10);
	glutCreateWindow(argv[0]);
	glInit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glutMainLoop();
}

