// ������ �̿��Ͽ� �Է¹��� ������ �������� ����ϴ� ���α׷��� ����ÿ�

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main() {
	int data;
	int n, i;
	Stack *s; //������ ����ų ������ 
	
	printf("�� ���� ������ �Է��ϰ� �����ʴϱ�?\n");
	printf("1�̻� 10���Ϸ� �Է��� �ּ���.");
	scanf("%d",&n);
	
	s = mkStack();  //������ ������
	printf("%d���� ������ �Է��� �ּ���.: ",n);
	for (i = 0; i<n;i++){
		scanf("%d",&data);
		push(s,data);
	} 
	
	printf("����� �Է��� ������ �������� ����մϴ�.: ");
	while(! isEmpty(s)){
		
		data = pop(s);
		printf("%d\n",data);
		
	}
	return 0;
	 
}
