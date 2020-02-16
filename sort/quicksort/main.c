#include"sort.h"

int main(){
	int a[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++){
		a[i] = rand() % 10;
	}

	print(a, 10);//注意范围
	quicksort(a, 0, 9);
	print(a,10);
	system("pause");
}
