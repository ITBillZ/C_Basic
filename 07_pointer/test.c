#include <stdio.h>
#define SIZE 5

int main() {
    double value[SIZE];
    for (double* p = &value[0]; p < &value[SIZE];) {
        *p++ = 2;
    }
    for (double* p = &value[0]; p < &value[SIZE]; p++) {
        printf("%f\n", *p);
    }

    return 0;
}
