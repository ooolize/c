#include"sort.h"

void quicksort(int* a, int left, int right){
	int pivot;
	//right--;
	if (left < right){
		pivot = partition(a, left, right);
		quicksort(a, left, pivot - 1);
		quicksort(a, pivot + 1, right);
	}
}

void heapsort(int *a, int left, int right){//right应该是元素长度
	int N = right / 2 - 1;
	for (int i = N - 1; i>=0; i--){
		audjustHeapSort(a, i, right);
	}
	SWAP(a[0], a[right-1]);
	for (int i = right - 2; i > 0; i--){
		audjustHeapSort(a, 0, i);
		SWAP(a[0],a[i]);
	}

}

//函数的语义是从将pos位置的值变为它左右子树的最大值，并将交换下去的数保留最大堆的性质。
void audjustHeapSort(int*a, int pos, int len){
	int dad = pos;
	int son = dad * 2 + 1;
	if (son + 1 < len&&a[son] < a[son + 1]) son++;
	while (son<len&&dad<len&&a[son]>a[dad]){
		SWAP(a[son], a[dad]);
		dad = son;
		son = son * 2 + 1;
	}
}
