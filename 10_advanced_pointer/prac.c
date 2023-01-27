#include <stdio.h>
#include <string.h>

// 本平台是64位，地址为8个字节
int main() {
    // int型一维数组
    int a[] = {1, 2, 3, 4};
    printf("sizeof(a) = %ld\n", sizeof(a));            // 数组长度 16
    printf("sizeof(a + 0) = %ld\n", sizeof(a + 0));    // 首元素地址 8
    printf("sizeof(*a) = %ld\n", sizeof(*a));          // 解引用，整型 4
    printf("sizeof(a + 1) = %ld\n", sizeof(a + 1));    // 8
    printf("sizeof(a[1]) = %ld\n", sizeof(a[1]));      // 4
    printf("sizeof(&a) = %ld\n", sizeof(&a));          // 数组地址 8
    printf("sizeof(*&a) = %ld\n", sizeof(*&a));        // 抵消 数组 16
    printf("sizeof(&a + 1) = %ld\n", sizeof(&a + 1));  // 数组地址 8
    printf("sizeof(&a[0]) = %ld\n", sizeof(&a[0]));    // 8
    printf("sizeof(&a[0] + 1) = %ld\n", sizeof(&a[0] + 1));  // 8

    // 字符数组
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%ld\n", sizeof(arr));          // 6
    printf("%ld\n", sizeof(arr + 0));      // 8
    printf("%ld\n", sizeof(*arr));         // 1
    printf("%ld\n", sizeof(arr[1]));       // 1
    printf("%ld\n", sizeof(&arr));         // 8
    printf("%ld\n", sizeof(&arr + 1));     // 8
    printf("%ld\n", sizeof(&arr[0] + 1));  // 8
    printf("--------------------\n");

    printf("%ld\n", strlen(arr));      // 随机值
    printf("%ld\n", strlen(arr + 0));  // 随机值
    // printf("%ld\n", strlen(*arr)); // Segmentation fault
    // printf("%ld\n", strlen(arr[1])); // Segmentation fault
    printf("%ld\n", strlen(&arr));         // 随机值 与第一行结果相同
    printf("%ld\n", strlen(&arr + 1));     // 随机值 比第一行少6
    printf("%ld\n", strlen(&arr[0] + 1));  // 随机值 比第一行少1
    printf("--------------------\n");

    char arr2[] = "abcdef";
    printf("%ld\n", sizeof(arr2));          // 7
    printf("%ld\n", sizeof(arr2 + 0));      // 8
    printf("%ld\n", sizeof(*arr2));         // 1
    printf("%ld\n", sizeof(arr2[1]));       // 1
    printf("%ld\n", sizeof(&arr2));         // 8
    printf("%ld\n", sizeof(&arr2 + 1));     // 8
    printf("%ld\n", sizeof(&arr2[0] + 1));  // 8
    printf("--------------------\n");

    printf("%ld\n", strlen(arr2));      // 6
    printf("%ld\n", strlen(arr2 + 0));  // 6
    // printf("%ld\n", strlen(*arr2));         // ERROR
    // printf("%ld\n", strlen(arr2[1]));       // ERROR
    printf("%ld\n",
           strlen(&arr2));  // &arr2的类型是char(*)[7]，会被强转，但是结果不变 6
    printf("%ld\n", strlen(&arr2 + 1));     // 随机
    printf("%ld\n", strlen(&arr2[0] + 1));  // 5
    printf("--------------------\n");

    char* p = "abcdef";
    printf("%ld\n", sizeof(p));          // 8
    printf("%ld\n", sizeof(p + 1));      // 8
    printf("%ld\n", sizeof(*p));         // 1
    printf("%ld\n", sizeof(p[0]));       // 1
    printf("%ld\n", sizeof(&p));         // 8
    printf("%ld\n", sizeof(&p + 1));     // 8
    printf("%ld\n", sizeof(&p[0] + 1));  // 8
    // ？？？
    // printf("%p\n", &p);
    // printf("%p\n", &p + 1);
    printf("--------------------\n");

    printf("%ld\n", strlen(p));      // 6
    printf("%ld\n", strlen(p + 1));  // 5
    // printf("%ld\n", strlen(*p));//E
    // printf("%ld\n", strlen(p[0]));//E
    printf("%ld\n", strlen(&p));         // 随机
    printf("%ld\n", strlen(&p + 1));     // 随机
    printf("%ld\n", strlen(&p[0] + 1));  // 5

    return 0;
}
