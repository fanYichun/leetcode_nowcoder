#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int str_len = strlen(s);
    int group_num = str_len / (2 * numRows - 2);
    int last_num = str_len - group_num * (2 * numRows - 2);

    char* res = (char*)malloc((str_len + 1) * sizeof(char));
    memset(res, 0, (str_len + 1) * sizeof(char));

    int c_index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < group_num; j++) {
            res[c_index] = s[(2 * numRows - 2) * j + i];
            c_index++;

            if (i != 0 && i != numRows - 1) {
                res[c_index] = s[(2 * numRows - 2) * j + (2 * numRows - 2 - i)];
                c_index++;
            }
        }

        if (i < last_num) {
            res[c_index] = s[(2 * numRows - 2) * group_num + i];
            c_index++;

            if (i != 0 && i != numRows - 1 && 2 * numRows - 2 - i < last_num) {
                res[c_index] = s[(2 * numRows - 2) * group_num + (2 * numRows - 2 - i)];
                c_index++;
            }
        }
    }
    return res;
}

int main() {
    char str[] = "PAYPALISHIRING";
    char* res = convert(str, 3);

    free(res);
    return 0;
}