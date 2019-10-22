/*************************************************************************
	> File Name: 13.binary_search.cpp
	> Author: ranjinxi 
	> Mail: r1367718372@163.com 
	> Created Time: 2019年10月20日 星期日 20时38分34秒
 ************************************************************************/

#include <stdio.h>

#define P(func, args...) {\
    printf("%s %d",#func, func(args));\
    printf("\n");\
}

// 1 3 5 7 9 10
int binary_search(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

// 1111000000
int binary_search1(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0000000111111111
int binary_search2(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    int arr3[10] = {0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1};
    P(binary_search, arr1, 10, 7);
    P(binary_search1, arr2, 10);
    P(binary_search2, arr3, 10);
    return 0;
}
