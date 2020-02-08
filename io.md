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

### gets,fgets
+ gets
> + gets(c)函数接受一个字符数组，并从键盘读取一行。
> + 遇到\n忽略并将之前的字符加上\0放入缓冲区。
> + 如果遇到文件结束符返回NULL(0)
> + 可能发生访问越界的问题(覆盖其他数据)

#### 测试gets
+ gets
```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 5


int main(){
	int a = 0;
	char b[size];
	while (gets(b) != NULL){
		puts(b);
		putchar('\n');
	}
	printf("%d", a);
	system("pause");
}

输入:aaaaa\n
输出:aaaaa
输入:aaaaaaaaaaaaaaaaaaaaaaaaa\n
输出:aaaaaaaaaaaaaaaaaaaaaaaaa
输入:ctrl+z
此时a的值会发生改变，因为访问越界.在vs2013中值为0xcccccccc
```


+ fgets(c,sizeof(c),stdin)
> + 接受一个字符数组，一个表示最多读入sizeof(c)-1，一个标准输入
> + 这个函数是安全的，一旦输入超过给定范围，后面的输入就会在缓冲区而不读入，如果少于给定范围，那就补充0
> + 它会把\n读取到c中，我们需要将c[sizeof[c]-1]=0将他抹掉。(这样必须保证子串长度小于sizeof(c)-1,因为最后一个位置是要给\n留的。比如下面这个例子，size=10这样我们最多读取8个字符，剩下两个存储\n和\0)
#### 测试fgets
```c++
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 5


int main(){
	int a = 0;
	printf("a=%d\n", a);
	char b[size];
	while (fgets(b,sizeof(b),stdin) != NULL){
		
		puts(b);	
		//putchar('\n');
	}
	printf("a=%d", a);
	system("pause");
}
输入:aa\n
输出:\n\naa(一个是缓冲区中的\n，另一个是puts的\n)
输入:aaaaaaaaaaaa\n(12个a)
输出:aaaa
占位 aaaa
占位 aaaa\n\n    
```

## str系列, strn系列函数
