#include <stdio.h>

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {
    return a / b;
}

char* my_strcpy(char* dest, const char* src){};

int main() {
    printf("%p\n", add);
    printf("%p\n", &add);

    int (*pa)(int, int) = add;
    // 都能得出结果
    printf("%d\n", (pa)(2, 3));
    printf("%d\n", (*pa)(2, 3));
    printf("%d\n", (**pa)(2, 3));
    printf("%d\n", (***pa)(2, 3));

    // 函数指针数组
    int (*pa2[4])(int, int) = {add, sub, mul, div};

    for (int i = 0; i < 4; i++) {
        printf("%d\n", pa2[i](6, 3));
    }

    //
    char* (*pf1)(char*, const char*) = my_strcpy;
    char* (*pf2[4])(char*, const char*);

    return 0;
}
