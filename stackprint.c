// 스택을 이용하여 입력받은 정수를 역순으로 출력하는 프로그램을 만드시오

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main() {
	int data;
	int n, i;
	Stack *s; //스택을 가리킬 포인터 
	
	printf("몇 개의 정수를 입력하고 싶으십니까?\n");
	printf("1이상 10이하로 입력해 주세요.");
	scanf("%d",&n);
	
	s = mkStack();  //스택을 생성함
	printf("%d개의 정수를 입력해 주세요.: ",n);
	for (i = 0; i<n;i++){
		scanf("%d",&data);
		push(s,data);
	} 
	
	printf("당신이 입력한 정수를 역순으로 출력합니다.: ");
	while(! isEmpty(s)){
		
		data = pop(s);
		printf("%d\n",data);
		
	}
	return 0;
	 
}
