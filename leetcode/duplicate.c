#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* e1, const void* e2) {
    return *((int*)e1) - *((int*)e2);
}

bool containsDuplicate(int* nums, int numsSize) {
    bool order = true;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            order = false;
        }
    }
    if (!order) {
        qsort(nums, numsSize, sizeof(int), cmp);
    }
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}