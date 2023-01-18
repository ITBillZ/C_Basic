#include <stdio.h>
#include <string.h>

int main() {
    char arr1[3] = {'a', 'b', 'c'};
    int len = strlen(arr1);  // 实际上是一个随机值
    printf("%d\n", len);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int sz = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < sz; i++) {
        printf("%p\n", &arr2[i]);
    }

    return 0;
}
