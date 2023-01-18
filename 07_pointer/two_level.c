#include <stdio.h>

int main() {
    int a = 10;
    int* pa = &a;
    int** ppa = &pa;
    printf("%p\n", pa);
    printf("%p\n", ppa);

    printf("%d\n", **ppa);
    return 0;
}
