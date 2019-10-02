#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#define C 10
#define SIZE 1000
int main() {
	replace();
}

void replace(){
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
token=strtok(text,seps);
while(token!=NULL)
{
    strcpy(b[count],token);
    count++;
token=strtok(NULL,seps);
}
for(j=0;j<count;j++)
{
if(strcmp(b[j],target)==0)
    {strcpy(b[j],replace);
break;}
}

for(j=0;j<count;j++)
{

strcat(kk,b[j]);
strcat(kk," ");
}
scroll(kk,C);
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
		system("cls"); Sleep(10);
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


