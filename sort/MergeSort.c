//
// Created by bytedance on 2022/1/3.
//
//merge_sort(p...r) = merge(marge_sort(p...q), merge_sort(q+1, r))
#include "stdio.h"
//
//void merge(int mergeArr[], int mergeLeft[], int mergeRight[]){
////    哨兵模式，相当于一个参照物
////    tmpLeft[leftSize] = int.MaxValue;
////    tmpRight[rightSize] = int.MaxValue;
////
////   不需要，直接
////    for (k=left,i=0,j=0; k<=right; k++){
////        if(tmpLeft[i] < tmpRight[j]){
////            arr[k] = tmpLeft[i]; i++;
////        }else{
////            arr[k] = tmpRight[j]; j++;
////        }
////    }
//}

//
void merge_sort_c(int mergeArr[], int begin, int end){
//    递归的终止条件
    if (begin >= end) return;

//    取开始和解释之间中间的数值
    int sum = begin + end;
    int middle = sum /2;

    merge_sort_c(mergeArr, begin, middle);
    merge_sort_c(mergeArr, middle+1, end);

//
    merge(mergeArr[], mergeArr[], mergeArr[]);

}

//
void merge_sort(int mergeArr[], int len){
    merge_sort_c(mergeArr, 0, len);
}


int main(){

    printf("Hello");

}
