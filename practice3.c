#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
int main () {
	int b,i,f,l, kk; 
	char a[1000];
	char s[1000];
	char o[1000];
	printf("암호화 할 규칙(숫자)을 입력해 주세요.\n");
	scanf("%d",&b);
	scanf("%*c",kk);
	printf("암호화 할 문자열을 입력해 주세요.\n");
	gets(a);
	l = strlen(a);
	for (i = 0; i<l;i++){
		if (a[i]==32){
		
			s[i]=32;
		}
		else if (a[i]+b<=122 && a[i]+b>=97){
		
			s[i]=a[i]+b;
		}
		else if (a[i]+b>122){
		
			s[i]=a[i]+b-26;
		}
		else if (a[i]+b>=65 && a[i]+b<=90){
	
			s[i]=a[i]+b;
		}
		else if (a[i]+b>90 && a[i]+b<97){
		
			s[i]=a[i]+b-26;
		}
	}
	printf("암호화 문자열을 아래와 같습니다.\n"); 
	printf("%s",s);
	printf("\n복호화 문화자열을 아래와 같습니다.\n"); 
	l = strlen(s);
	for (i = 0; i<l;i++){
		if (s[i]==32){
		
			o[i]=32;
		}
		else if (s[i]<=125&& s[i]>=100){
		
		
			o[i]=s[i]-b;
		}
		else if(s[i]>125){
		
			o[i]=s[i]-b+26;
		}
		else if (s[i]>=68 && s[i]<=93){
	
			o[i]=s[i]-b;
		}
		else if (s[i]>93 && s[i]<100){
		
			o[i]=s[i]-b+26;
		}
	}
	prinf("챌린지\n")
	printf("%s\n",o);
	swap_char (s);
	
	
	return 0;
}

void swap_char (char s[1000]) {
	srand(time(NULL));
	int ran1 = rand() % strlen(s);
	int ran2 = rand() % strlen(s);

	int tmp;
	tmp = s[ran1];
	s[ran1] = s[ran2];
	s[ran2] = tmp;
	
	printf("%s",s);
}
