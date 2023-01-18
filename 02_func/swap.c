#include <stdio.h>

// 形参实例化后相当于实参的一份临时拷贝
void swap_fail(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swap(int* pa, int* pb) {
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int main() {
    int a = 10, b = 20;
    swap(&a, &b); // 传址调用
    printf("a=%d b=%d\n", a, b);
    return 0;
}
