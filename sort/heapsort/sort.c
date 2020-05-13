#include"sort.h"
#include <iostream>
using std::endl;
using std::cout;

//更新pos位置的值为其左右节点的最大，并把交换下去的数维持最大堆的性质
void audjustHeapSort(int*a, int pos, int len){
    int dad = pos;
    int son = dad * 2 + 1;
    while (son<len){
        if (son + 1 < len&&a[son] < a[son + 1]) son++;
        if(a[son]>a[dad]){
            SWAP(a[son], a[dad]);
            dad = son;
            son = son * 2 + 1;
        }
        else{break;}
    }
}
void heapsort(int *a, int left, int right){
    //从底到顶成堆
    for (int i = right/2 ; i>=0; i--){
        audjustHeapSort(a, i, right);
    }
    SWAP(a[0], a[right-1]);
    //每次从顶拿到最大值后与末尾的交换，这样从i以后的都是有序增大的。
    for (int i = right - 1; i > 0; i--){
        audjustHeapSort(a, 0, i);
        SWAP(a[0],a[i-1]);

    }

}

void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
