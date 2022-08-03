#include <string.h>
#include <math.h>
#include <stdlib.h>

int equalSubstring(char* s, char* t, int maxCost) {
    int str_len = strlen(s);
    int max_len = 0;

    int index_p = 0;
    int sum_p = 0;

    for (int i = 0; i < str_len; i++) { // front pointer
        int diff = abs(s[i] - t[i]);
        int sum = sum_p + diff;

        if (sum > maxCost) {
            int j = index_p; // move the back pointer
            while (sum > maxCost) {
                sum -= abs(s[j] - t[j]);
                j++;
            }
            index_p = j;
        }
        sum_p = sum;

        int len = i - index_p + 1;

        if (len > max_len) max_len = len;
    }

    return max_len;
}

int main() {
	char s[] = "abcd";
	char t[] = "bcdf";

    int res = equalSubstring(s, t, 3);
    return 0;
}