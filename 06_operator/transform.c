#include <stdio.h>

int main() {
    char a = 0xb6;
    short b = 0xb600;
    int c = 0xb6000000;
    if (a == 0xb6)  // 把a提升为int，高位补符号位
        printf("a\n");
    if (b == 0xb600)
        printf("b\n");
    if (c == 0xb6000000)
        printf("c\n");  // 只输出了c

    
    char d = 1;
    // 144，貌似不同编译器第三个结果不同
    printf("%lu\n", sizeof(d));
    printf("%lu\n", sizeof(+d));
    printf("%lu\n", sizeof(!d));

    /*
    从下向上提升
    long double
    double
    float
    unsigned long int
    long int 
    unsigned int 
    int
    */

    return 0;
}
