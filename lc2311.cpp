#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int longestSubsequence(char* s, int k) {
    int str_len = strlen(s);
    if (str_len == 0) return 1;
    
    int sum = 0;
    int len = 0;
    for (int i = str_len - 1; i >= 0; i--) {
        if (s[i] == '0') len++;
        else {
            if (sum + pow(2, str_len - 1 - i) <= k) {
                sum += pow(2, str_len - 1 - i);
                len++;
            }
        }
    }

    return len;
}

int main() {
    char str[] = "001010010";
    int res = longestSubsequence(str, 1);
    return 0;
}