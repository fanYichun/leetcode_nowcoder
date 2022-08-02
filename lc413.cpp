#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfArithmeticSlices(int* nums, int numsSize) {
    int* n_sub_num = (int*)malloc(numsSize * sizeof(int));
    memset(n_sub_num, 0, numsSize * sizeof(int));

    for (int i = 2; i < numsSize; i++) {
        n_sub_num[i] = n_sub_num[i - 1];

        int j;
        for (j = i - 2; j >= 0; j--) {
            if (nums[j + 1] - nums[j] != nums[j + 2] - nums[j + 1]) break;
        }
        int cons_num = i - 2 - j;
        n_sub_num[i] += cons_num;
    }

    int res = n_sub_num[numsSize - 1];
    free(n_sub_num);

    return res;
}

int main() {
    int num[] = { 1,2,3,4 };
    int res = numberOfArithmeticSlices(num, 4);

    return 0;
}