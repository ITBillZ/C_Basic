#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void _quicksort(void* base,
                size_t width,
                int (*cmp)(const void*, const void*),
                int l,
                int r);

// 如果width非常大的话，效率会非常低
void swap(char* buf1, char* buf2, size_t width) {
    char tmp;
    for (int i = 0; i < width; i++) {
        tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        // 记得把buf1 buf2向前移动
        buf1++;
        buf2++;
    }
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int patition(void* base,
             size_t width,
             int (*cmp)(const void*, const void*),
             int l,
             int r) {
    // 转换成char*，才知道加减多少个字节
    char* pivot = (char*)base + r * width;
    int ran = rand() % (r - l + 1) + l;
    swap(pivot, (char*)base + ran * width, width);

    char* ai;
    char* aj;
    int i = l;
    for (int j = l; j < r; j++) {
        ai = (char*)base + i * width;
        aj = (char*)base + j * width;
        if (cmp(aj, pivot) <= 0) {
            swap(ai, aj, width);
            i++;
        }
    }
    ai = (char*)base + i * width;
    swap(ai, pivot, width);
    return i;
}

void quicksort(void* base,
               size_t size,
               size_t width,
               int (*cmp)(const void*, const void*)) {
    srand(time(NULL));
    _quicksort(base, width, cmp, 0, size - 1);
}

void _quicksort(void* base,
                size_t width,
                int (*cmp)(const void*, const void*),
                int l,
                int r) {
    if (l < r) {
        int p = patition(base, width, cmp, l, r);
        _quicksort(base, width, cmp, l, p - 1);
        _quicksort(base, width, cmp, p + 1, r);
    }
}

int main() {
    int arr[] = {5, 3, 7, 1, -2, 0, 19, 6};
    size_t sz = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, sz, sizeof(arr[0]), cmp);
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
