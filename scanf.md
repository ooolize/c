### scanf的小细节
+ 当键入回车时，就是键入一个换行符.当键入一个换行符时，才会将键盘上的内容存入缓冲区。
+ scanf如果缓冲区没数据才会阻塞，等待输入
+ scanf==EOF的情况只有第一个字符是ctrl + z时才会退出
+ scanf读取double时需要用ld% 
+ scanf用%d读取会忽略（访问了但丢弃）空格和换行符,遇到数字会读取，遇到其他会跳过(不丢弃)。如果用下面的循环读取元素。因为出现其他元素，缓冲区还有元素，所以不会阻塞scanf函数。一直读取成为死循环
+ scanf用%c读取字符无论什么字符都可以读取，这意味着\n,非首部的ctrl+z都会出现在缓冲中,也会被读取。

### 测试
```c
#include<stdio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define size 12

int main(){
	int a, ret;
	char c;
	
	while ((ret = scanf("%c", &c)) != EOF){//输入:1 2 3 缓冲区实际上是123\n.
		printf("%c->",c);                    //输出:1-> ->2-> ->3->'\n'(实际效果为换行)-> 
	}

	printf("\n");
	system("pause");

	while ((ret = scanf("%c", &c)) != EOF){//输入:1 2 3 ctrl+z \n
		if(c!='\n')printf("%c->", c);        //输出:1 ->2-> ->3->→(ctrl+z表示的字符)->     (注意跟在数据后的的ctrl+z并不会结束输入)
	}
	printf("\n");
	system("pause");

	//使用rewind函数清空缓冲区，这样就算第一次输入1 2 3也只会输出1，因为scanf读取1之后，缓冲区还有" 2 3"，再次进入循环之后首先清空缓冲区，这样scanf会被阻塞
	while (rewind(stdin),(ret = scanf("%d", &a)) != EOF){//输入:1 2 3
		printf("%d->", a);                                 //输出:1->
	}
	printf("\n");
	system("pause");
}
```
