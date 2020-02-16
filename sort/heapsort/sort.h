#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b){int tmp=a;a=b;b=tmp;}//不能用a^b why?

void audjustHeapSort(int*, int, int);
void heapsort(int *, int, int);
