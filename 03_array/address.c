#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4};
    printf("%p\n", arr);  // 第一个元素的地址
    printf("%p\n", &arr[0]);  // 第一个元素的地址
    printf("%d\n", *arr);

    // 数组名一般是数组首元素的地址，只有两个例外：
    // 1. sizeof(数组名)：算出整个数组的大小
    // 2. &数组名，取出的整个数组的地址
    printf("%p\n", &arr);  //整个数组的地址
    printf("%p\n", &arr + 1);  // 是上一行的结果 + 4 * sizeof(int)

    return 0;
}
