#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int num;
	struct student*next;
}student_t, *pStudent_t;
void insertToHead(pStudent_t*, pStudent_t*, int );
void print(pStudent_t);
