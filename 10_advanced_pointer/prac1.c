#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("%p\n", &p);
    printf("%p\n", &p + 1);
    printf("--------------------\n");

    printf("%ld\n", strlen(p));      // 6
    printf("%ld\n", strlen(p + 1));  // 5
    // printf("%ld\n", strlen(*p));//E
    // printf("%ld\n", strlen(p[0]));//E
    printf("%ld\n", strlen(&p));         // 随机
    printf("%ld\n", strlen(&p + 1));     // 随机
    printf("%ld\n", strlen(&p[0] + 1));  // 5

    printf("--------------------\n");

    int a1[3][4] = {0};
    printf("%ld\n", sizeof(a1));//48
    printf("%ld\n", sizeof(a1[0][0]));//int类型 4
    printf("%ld\n", sizeof(a1[0])); // a1[0]是第一行数组的数组名，sizeof(数组名)=数组大小 int[4] 16
    printf("%ld\n", sizeof(a1[0] + 1)); // a1[0][1]地址 8 这里没有&a1[0]，所以+1并不会跳到第二行，而是下一个元素
    printf("%ld\n", sizeof(*(a1[0] + 1))); //a1[0][1] int类型 4
    //把二维数组看成一维，a1是首元素的地址，也就是第一行的地址，a1+1是第二行数组的地址 8
    printf("%ld\n", sizeof(a1 + 1)); 
    printf("%ld\n", sizeof(*(a1 + 1)));//a1[1] 第二行数组地址解引用，是数组 16
    printf("%ld\n", sizeof(&a1[0] + 1));// 不是单独放sizeof里，是地址 8
    printf("%ld\n", sizeof(*(&a1[0] + 1)));
    printf("%ld\n", sizeof(*a1));
    printf("%ld\n", sizeof(a1[3]));

    printf("%p\n", a1[0]);

    return 0;
}
