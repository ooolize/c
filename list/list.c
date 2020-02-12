#include "list.h"

void insertToHead(pStudent_t*head, pStudent_t*tail, int val){
	pStudent_t newNode = (pStudent_t)calloc(1, sizeof(student_t));
	newNode->num = val;
	if (NULL == *head){
		*head = newNode;
		*tail = newNode;
	}
	else{
		newNode->next = *head;
		*head = newNode;
	}
}
void print(student_t*head){
	student_t* tmp = head;
	while (tmp){
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
}
