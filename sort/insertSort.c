//
// Created by bytedance on 2022/1/3.
//
#include "stdio.h"
//从后往前插入排序
int insertSortAfterToBefore(int a[], int n){
    if(n <= 0) return -1;
//    开始循环
    for (int i = 1; i < n; ++i) {
//        代表要比较的数据
        int value = a[i];
//        代表要比较的次数
        int j = i - 1;
//        开始循环，并把比value大的往后迁移
        for (; j>=0; --j) {
            if(a[j] > value){
                a[j+1] = a[j];
            } else break;
        }
//        将value插入正确的地方(第一次由于已经在0的地方插入，第二次由于与第一次不需要比较，所以可以插在1的地方)
        a[j+1] = value;
    }
    return 0;
}

//从前往后插入排序
int insertSortBeforeToAfter(int b[], int n){
    if(n <= 0) return -1;

    for (int i = 1; i < n; ++i) {
        int value = b[i];
        int j = i-1;
        int k = 0;
        for (; k <= j; ++k) {
            if(b[k] > value){
                b[k+1] = b[k];
            } else continue;
        }
//        插入元素
        b[j-k] = value;
    }
    return 0;
}

int main(){
    int a[] = {4, 5, 6, 1, 3, 2};
    int n = 6;
//    insertSortAfterToBefore(a, n);

    int b[] = {4, 5, 6, 1, 3, 2};
    insertSortBeforeToAfter(b, n);

//    for (int i = 0; i < n; ++i) {
//        printf("%d", a[i]);
//    }

    for (int i = 0; i < n; ++i) {
        printf("%d", b[i]);
    }
    return 0;
}