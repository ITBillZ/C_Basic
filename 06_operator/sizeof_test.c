#include <stdio.h>

int main() {
    short s = 0;
    int a = 10;
    printf("%d\n", sizeof(s = a + 5));  // 2，由short的长度决定，sizeof里面的表达式不运算
    printf("%d\n", s);  // 0
    return 0;
}
