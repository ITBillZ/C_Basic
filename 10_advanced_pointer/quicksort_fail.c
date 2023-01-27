#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(void* base,
          size_t num,
          size_t size,
          int (*cmp)(const void*, const void*),
          int l,
          int r);

void swap(void** x, void** y) {
    void* tmp = *x;
    *x = *y;
    *y = tmp;
}

int patition(void* base,
             size_t num,
             size_t size,
             int (*cmp)(const void*, const void*),
             int l,
             int r) {
    void* pivot = base + r * size;
    void* ai;
    void* aj;
    int i = l;
    for (int j = l; j < r; j++) {
        ai = base + i * size;
        aj = base + j * size;
        if (cmp(aj, pivot) <= 0) {
            swap(&ai, &aj);
            i++;
        }
    }
    ai = base + i * size;
    swap(&ai, &pivot);
    return i;
}

void quicksort(void* base,
               size_t num,
               size_t size,
               int (*cmp)(const void*, const void*)) {
    srand(time(NULL));
    sort(base, num, size, cmp, 0, num - 1);
}

void sort(void* base,
          size_t num,
          size_t size,
          int (*cmp)(const void*, const void*),
          int l,
          int r) {
    if (l < r) {
        int p = patition(base, num, size, cmp, l, r);
        sort(base, num, size, cmp, l, p - 1);
        sort(base, num, size, cmp, p + 1, r);
    }
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int arr[] = {5, 3, 7, 1, -2, 0, 19, 6};
    size_t sz = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, sz, sizeof(arr[0]), cmp);
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
