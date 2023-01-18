#include <stdio.h>

void bubble_sort_fail(int arr[]) {
    // 传的是一个地址
    // ‘sizeof’ on array function parameter ‘arr’ will return size of ‘int *’
    // [-Wsizeof-array-argument] 
    // int sz = sizeof(arr) / sizeof(arr[0]);
    int sz;
    int tmp;
    for (int i = 0; i < sz - 1; i++) {
        for (int j = 0; j < sz - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void bubble_sort(int arr[], size_t sz) {
    int tmp;
    for (int i = 0; i < sz - 1; i++) {
        int flag = 1; // 有序时退出
        for (int j = 0; j < sz - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag)
            break;
    }
}

int main() {
    int arr[] = {5, 3, 2, 6, 9, 7, 4};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz);
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
