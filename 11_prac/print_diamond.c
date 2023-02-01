#include <stdio.h>

int main() {
    int len = 8;
    // scanf("%d", &len);
    int len2 = len * 2 + 1;
    for (int i1 = 0; i1 < len2; i1++) {
        for (int j1 = 0; j1 < len2; j1++) {
            int i2 = len2 - i1 - 1;
            int j2 = len2 - j1 - 1;
            if (i1 + j1 < len  || i2 + j1 < len || i1 + j2 < len ||
                i2 + j2 < len) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
