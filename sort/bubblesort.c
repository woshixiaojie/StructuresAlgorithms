//
// Created by bytedance on 2022/1/3.
//
#include "stdbool.h"
#include "stdio.h"
int bubbleSort(int a[], int n){
//    判断数组是否为空，和传入的n大小是否小于0
    if(n <= 0) return -1;

    int cycle = 0;
    int exchangeTime = 0;
//    按照惯例，冒泡每次都把最大的放在最后，所以一般情况下都是对数组每一个元素排序
    for (int i = 0; i < n; ++i) {
//        为了每一轮都方便标记，初始化标记位置
        bool flag = false;
//        这里就是具体的操作，把最大的放在最后面
        for (int j = 0; j < n; ++j) {
            if(a[j] > a[j+1]){
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                ++exchangeTime;
//                当有数据交换时，我们可以标记一下这这一轮
                flag = true;
            }
        }
//        当走完一轮发现没有位置交换，则直接退出最外层循环
        ++cycle;
        if(!flag) break;
    }
//    --exchangeTime;
    printf("%d, %d\n",cycle, exchangeTime);
    return 0;
}

int main(int argc, char* argv[]){
    int arr[] = {3, 5, 4, 1, 2, 6};
    int n = 6;
    char key = 6;
    bubbleSort(arr,n);
    for (int i = 0; i < n; ++i) {
        printf("%d",arr[i]);
    }
    return 0;
}




