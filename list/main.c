#include "list.h"

int main(){
	int n;
	pStudent_t head = NULL, tail = NULL;
	while (scanf("%d", &n)!=EOF){
		insertToHead(&head,&tail, n);//记得取地址
	}
	print(head);
	system("pause");
}
