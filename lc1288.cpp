#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int intervals[][2] = { {3, 10}, {4, 10}, {5, 11} };
    int intervalsSize = 3;

    int max_val = 100001;
    int* max_r = (int*)malloc(max_val * sizeof(int));
    memset(max_r, 0, max_val * sizeof(int));

    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][1] > max_r[intervals[i][0]]) {
            max_r[intervals[i][0]] = intervals[i][1];
        }
    }

    for (int i = 1; i < max_val; i++) {
        if (max_r[i - 1] >= max_r[i]) max_r[i] = max_r[i - 1];
    }

    int num = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (max_r[intervals[i][0]] <= intervals[i][1]) {
            if (i > 0) {
                if (max_r[intervals[i][0] - 1] < intervals[i][1])
                    num++;
            }
            else {
                num++;
            }
        }
    }

    free(max_r);

    return 0;
}