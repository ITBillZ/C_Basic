#include <stdio.h>

void swap(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int arr[] = {3, 6, 2, 1, 8, 7, 9, 15};
    size_t sz = sizeof(arr) / sizeof(arr[0]);
    int* left = arr;
    int* right = arr + sz - 1;
    while (left < right)
    {
        if (*left % 2 == 0) {
            while (left < right) {
                if (*right % 2 == 1) {
                    swap(left, right);
                    right--;
                    break;
                } else {
                    right--;
                }
            }
        }
        left++;
    }

    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
