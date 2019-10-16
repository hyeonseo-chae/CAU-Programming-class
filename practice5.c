#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include <windows.h>
#define C 10 // ¹Ýº¹È½¼ö  
#define SIZE 1000
int main() {
	int text[SIZE];
int target[1000];
int replace[1000];
char seps[]=" ";
int b[10][20];
char *token;
int kk[1000];
int j,count;
count=0;
printf("text:");
gets(text);
printf("target:");
gets(target);
printf("replace:");
gets(replace);
	replaceText(text,target,replace);
	 
}

void replaceText(char *text, char *target, char *replace) {
	char* fin = strstr(text, target);
	char buff[99] = "";
	char* point = text;
	int i,k,lenre, lenta, lente;
	for ( i = 0; replace[i]; i++) {
		lenre = i + 1;
	}
	for (i = 0; text[i]; i++) {
		lente = i + 1;
	}
	for ( i = 0; target[i]; i++) {
		lenta = i + 1;
	}
	 i = 0;
	while (fin != NULL) {
		int d = fin - text;
		char temp[99] = "";
		for (i = 0; i < fin - text; i++) {
			temp[i] = text[i];
		}
		for ( k = 0; k < lenre ; k++,i++) {
			temp[i] = replace[k];
		}
		strcat(buff, temp);
		text += d + lenta;

		fin = strstr(text, target);
	}
	strcpy(point, buff);
	strcat(point, " ");
	system("cls"); 
	scroll(point,C);
}

void CursorView(char show)//Ä¿¼­¼û±â±â 	
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void scroll(char *str,int n){
	printf("\n");
	int count=0,i,temp,k;
	int len = strlen(str);
	for(k=0;k<n;k++){
	
	while(count<=len)
    {
  
        for(i=0;i<len;i++)
        {printf("%c", str[i]);} 
		CursorView(0); Sleep(100); system("cls"); 
        for(i=0;i<len;i++)
        {
            if(i==0)
                {temp = str[len];
                str[len]=str[i];
                str[i]=str[i+1];}
            else if(i==len-1)
                str[i]=temp;
        str[i]=str[i+1];
        }
    count++;
    }
    count = 0;
}
	
}


