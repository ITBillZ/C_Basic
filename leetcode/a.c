#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int* p1 = nums;
    int* p2;
    int k = 1;
    for (int i = 1; i < numsSize; i++) {
        p2 = nums + i;
        if (*p1 != *p2) {
            p1++;
            k++;
            *p1 = *p2;
        }
    }
    return k;
}

void part_rotate(int* nums, int l, int r) {
    int* pl = nums + l;
    int* pr = nums + r;
    while (pl < pr) {
        int tmp = *pl;
        *pl = *pr;
        *pr = tmp;
        pl++;
        pr--;
    }
}

void rotate(int* nums, int numsSize, int k){
    // k 比 size 大会出错
    k %= numsSize;
    part_rotate(nums, 0, numsSize - k - 1);
    part_rotate(nums, numsSize - k, numsSize - 1);
    part_rotate(nums, 0, numsSize - 1);
}

int main() {
    
    return 0;
}
