### 数组和指针
数组在堆中分配固定大小的连续空间。也可以使用malloc在栈中分配可变大小的空间。

指针(char* p)是一种类型，它的值是某个地址，**通过解引用(*p)得到该地址中存储的内容**。它也像其他变量一样有一个地址存储它的值。
+ 操作一个指针时一定要注意他的基类型
+ 指针加1指向的位置是当前位置加一个基类型的大小の位置。(char* p)是1，(int* p)是4.
> 数组可以在某些情况下转化为指针。但指针就是指针，数组就是数组，两者不能任意转换.
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100


int main(){
	int n = 5;
	char p[5] = "bbbb";
	char*c = "aaaa";//指针的存储值是子串"aaaa"的地址，但是指针既然在内存中，它也有一个4字节的地址。
	c[0] = 'b';//会报错。因为字符串"aaaa"是存储在数据段的，不允许写。上一个语句只是将该字符串的地址给了c
	p[0] = 'c';//不会报错，因为"bbbb"是在栈空间，可读可写。
	system("pause");
}
```
### 二维数组&指针数组&数组指针**二维指针
+ char a[3][3]是一个二维数组,a是一个数组指针(char(*)[3])指向一个数组(char[3])。
+ char *a[3]是一个指针数组,其中有3个指针(char* )。
+ char**p是一个二维指针。它的基类型是char* 。它的值是一个地址存储着char*的位置。
*p+1是p[0][1] *(p+1)是p[1]
+ 二维数组不能转化为二维指针。
+ 二维指针的传递与移位(todo)
## 实战--字符串排序
输入一些字符串，将它们按字典序输出。
+ 方法一：直接修改字符串数组的值
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS
#define size 12

void sort(char(*p)[size], int n){
	for (int i = n-1; i >0; i--){
		for (int j = n - 1; j > n - 1 - i; j--){
			if (strcmp(p[j - 1], p[j]) > 0){
				char tmp[size];
				strcpy(tmp, p[j]);//直接交换字符串，
				strcpy(p[j], p[j - 1]);
				strcpy(p[j - 1], tmp);
			}
		}
	}
}

int main(){
	char a[size][size] = { "hello", "world", "how", "are", "you", "ok!" };
	sort(a,6);
	for (int i = 0; i < 6; i++){
		puts(a[i]);
	}
	system("pause");
}
```

+ 方法二：通过定义一个指针数组保存每个字符串的指针，然后将指针排序，输出对应位置的值
```c++
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS
#define size 12

//冒泡排序：每次找到最小值放在前面
void sort(char**p, int n){
	for (int i = n - 1; i > 0; i--){//每次搜索的范围(n-1-j,n-1)
		for (int j = n - 1; j > n - 1 - i; j--){
			if (strcmp(p[j - 1], p[j]) > 0){//是j不是i
				char* a = p[j];
				p[j] = p[j - 1];
				p[j - 1] = a;
			}
		}
	}
}
int main(){
	char a[size][size] = { "hello", "world", "how", "are", "you", "ok!" };
	char*p[size];
	for (int i = 0; i < 6; i++){
		p[i] = a[i];
	}
	sort(p,6);
	for (int i = 0; i < 6; i++){
		puts(p[i]);
	}
	system("pause");
}
```
