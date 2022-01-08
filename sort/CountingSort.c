//
// Created by bytedance on 2022/1/3.
//
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
void countingSort(int arr[], int len){
    if (len <= 0) return;

//    查找数组中数据的范围,并保证数组里没有负数
    int min = 0;
    int max = arr[0];
    for (int i = 0; i < len; ++i) {
        if(max < arr[i]){
            max = arr[i];
        } else if (arr[i] < min) return;
    }

//  申请一个计数数组，下表大小为[0, max]
    int newArr[max+1];
    for (int i = 0; i <= max ; ++i) {
        newArr[i] = 0;
    }

//   计算每个数组的个数，放入申请的数组中。
//   对数组A[]进行遍历，得到 A[]中存储的具体的值，
//   该值又是新数组C的下标，C[]++表示 某个下标中存储的数据值加1
//   这里体现了分级思想
    for (int i = 0; i < len; ++i) {
        newArr[arr[i]]++;
    }

//    依次累加,就是顺序累加
    for (int i = 0; i <= max; ++i) {
        newArr[i] = newArr[i-1] + newArr[i];
    }

//  由于不是原地排序，所以需要申请内存空间。里面存储的是排序之后的结果
    int temporaryArr[len];

//    排序的关键。
//      得结合图文去理解 https://time.geekbang.org/column/article/42038
    for (int i = len -1; i >= 0 ; --i) {
        int index = newArr[arr[i]] - 1;
        temporaryArr[index] = arr[i];
        newArr[arr[i]]--;
    }

//    将结果拷贝给原来的数组
    for (int i = 0; i < len; ++i) {
        arr[i] = temporaryArr[i];
    }

}

int main(){
    int arr[] = {2,5,3,0,2,3,0,3};
    int len = 8;
    countingSort(arr,len);
    sleep(3);
    for (int i = 0; i < len; ++i) {
        printf("%d",arr[i]);
    }
}