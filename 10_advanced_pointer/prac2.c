#include <stdio.h>

void test1() {
    int a[5] = {1, 2, 3, 4, 5};
    int* ptr = (int*)(&a + 1);
    printf("%d,%d\n", *(a + 1), *(ptr - 1));
}

void test2() {
    // 根据运行结果，这个结构体的大小是32个字节
    struct Test {
        int Num;
        char* pcName;
        short sDate;
        char cha[2];
        short sBa[4];
    }* p;
    // 假设p 的值为0x10 0000。 如下表表达式的值分别为多少？
    // 已知，结构体Test类型的变量大小是20个字节
    p = (struct Test*)0x100000;
    printf("%p\n", p);
    printf("%p\n", p + 0x1);                 // 0x10 0014
    printf("%p\n", (unsigned long)p + 0x1);  // 0x10 0001
    printf("%p\n", (unsigned int*)p + 0x1);  // 0x10 0004
}

void test3() {
    int a[4] = {1, 2, 3, 4};
    int* ptr1 = (int*)(&a + 1);
    int* ptr2 = (int*)((int)a + 1);  // 本平台小端存储！！
    // %x 16进制
    printf("%x\n", ptr1[-1]);  // 取下标了，就是4
    printf("%x\n", *ptr2);     // 0x02 00 00 00，但是运行Segmentation fault
}

void test4() {
    // 圆括号() 是括号表达式！！
    int a[3][2] = {(0, 1), (2, 3), (4, 5)};  // {1, 3, 5, 0, 0, 0}
    int* p;
    p = a[0];
    printf("%d\n", p[0]);  // 1
}

void test5() {
    int a[5][5];
    int(*p)[4];  // 数组指针
    p = a;
    // p[4][2]是p[0][0]向后18个int，a[4][2]是a[0][0]向后22个int
    // p[4][2]等价于 *(*(p+4)+2)
    // 指针相减=地址相减 / 指针的类型字节数
    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
}

void test6() {
    int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* ptr1 = (int*)(&aa + 1);
    // a[1]，第二行的数组名，第二行首元素地址
    // 这里本身就是int*类型，不需要强转
    int* ptr2 = (int*)(*(aa + 1));
    printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
}

void test7() {
    char* a[] = {"work", "at", "alibaba"};
    char** pa = a;
    pa++;
    printf("%s\n", *pa);
}

void test8() {
    char* c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char** cp[] = {c + 3, c + 2, c + 1, c};
    char*** cpp = cp;
    printf("%s\n", **++cpp);
    printf("%s\n", *--*++cpp + 3);
    printf("%s\n", *cpp[-2] + 3);
    printf("%s\n", cpp[-1][-1] + 1);
}

int main() {
    test8();
    return 0;
}
