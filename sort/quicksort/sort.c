#include"sort.h"

void quicksort(int* a, int left, int right){
	int pivot;
	if (left < right){
		pivot = partition(a, left, right);
		quicksort(a, left, pivot - 1);
		quicksort(a, pivot + 1, right);
	}
}
//partition作用是 以尾部元素为分界 比它小的放在前面 比它大的放在后面
int partition(int*a, int left, int right){//用i遍历整个数组找到比尾部元素小的元素，如果有它应该在前面
	int k=left;                       //k标识一个位置，在这个位置之前都是比尾部元素小的元素。
	for (int i = left; i < right; i++){
		if (a[i] < a[right]){
			SWAP(a[i], a[k]);
			k++;
		}
	}
	SWAP(a[k], a[right]);//最后将尾部元素放到k的位置
	return k;//返回分割好的位置
}
void print(int*a, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
