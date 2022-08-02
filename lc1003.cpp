#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int str_len = strlen(s);
    if (str_len == 0) return true;
    else if (str_len < 3) return false;
    else {
        int valid = 0;
        int i = 0;
        for (; i < str_len - 2; i++) {
            if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
                valid = 1;
                break;
            }
        }
        if (valid == 0) return false;

        for (int j = i; j < str_len - 2; j++) {
            s[j] = s[j + 3];
        }

        return isValid(s);
    }
}

int main() {
    char str[] = "aabcbc";
    bool res = isValid(str);
    return 0;
}