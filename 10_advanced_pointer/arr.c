#include <stdio.h>

void print2(int (*p)[4], int row, int col);
void print3(int** p, int row, int col);

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {2, 3, 4, 5};
    int arr3[] = {3, 4, 5, 7};
    int* parr[] = {arr1, arr2, arr3};  // 二维数组

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            // printf("%d ", parr[i][j]);
            printf("%d ", *(parr[i] + j));
        }
        printf("\n");
    }
    printf("\n");

    // 数组指针 指针数组
    int arr[5] = {1, 2, 3, 4, 5};
    // []的优先级比*高，所以p有10个，类型是int*，是指针数组
    // 但是 error: invalid initializer
    // int* p1[10] = &arr;

    // 加了括号，*p代表p是一个指针(不是解引用)，指向的类型是int[10]，是数组指针
    int(*p2)[5] = &arr;

    // 例
    char* arr4[5];
    char*(*parr4)[5] = &arr4;

    // 用在二维数组中
    int arr5[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {4, 4, 5, 5}};
    /*
    二维数组的数组名的含义：
    1. 首先把二维数组想象成一维数组 int (arr[3])[4]
    2. 这个一维数组的每个元素是int[4]类型
    3. 所以数组名代表的是 第一个int[4] 的地址，一个一维数组的地址
    */
    print3((int**)arr5, 3, 4);

    return 0;
}

void print1(int arr[3][4], int row, int col) {
    //...
}

void print2(int (*p)[4], int row, int col) {
    for (int i = 0; i < row; i++) {
        printf("%p ", p[i]);
        for (int j = 0; j < col; j++) {
            // p + i找到 第i个 int[4]的地址，所以上面那个4是不能省略的
            // *(p + i)取得 第i个 int[4]的首元素地址
            // *(p + i) + j)取得 第i个 int[4] 第j个元素的地址
            printf("%d ", *(*(p + i) + j));
            // printf("%d ", (*(p + i))[j]);  // 也行
            // printf("%d ", p[i][j]);

            // arr[i] == *(arr + i) == *(p + 1) == p[i] √√√等价
        }
        printf("\n");
    }
}

void print3(int** p, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *((int*)p + i * col + j));
        }
        printf("\n");
    }
}
