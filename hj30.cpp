#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char convert(char in) {
    char ret_char;
    
    if (in >= 'A' && in <= 'F') in += 'a' - 'A';

    switch (in) {
    case '0': ret_char = '0'; break;
    case '1': ret_char = '8'; break;
    case '2': ret_char = '4'; break;
    case '3': ret_char = 'C'; break;
    case '4': ret_char = '2'; break;
    case '5': ret_char = 'A'; break;
    case '6': ret_char = '6'; break;
    case '7': ret_char = 'E'; break;
    case '8': ret_char = '1'; break;
    case '9': ret_char = '9'; break;
    case 'a': ret_char = '5'; break;
    case 'b': ret_char = 'D'; break;
    case 'c': ret_char = '3'; break;
    case 'd': ret_char = 'B'; break;
    case 'e': ret_char = '7'; break;
    case 'f': ret_char = 'F'; break;
    default: ret_char = in; break;
    }
    return ret_char;
}

int main() {
    char str_cat[202];
    char str2[101];

    scanf("%s", str_cat);
    scanf("%s", str2);
    strcat(str_cat, str2);

    for (int i = 0; i < strlen(str_cat) - 2; i = i + 2) {
        for (int j = i + 2; j < strlen(str_cat); j = j + 2) {
            if (str_cat[i] > str_cat[j]) {
                char temp = str_cat[i];
                str_cat[i] = str_cat[j];
                str_cat[j] = temp;
            }
        }
    }

    for (int i = 1; i < strlen(str_cat) - 2; i = i + 2) {
        for (int j = i + 2; j < strlen(str_cat); j = j + 2) {
            if (str_cat[i] > str_cat[j]) {
                char temp = str_cat[i];
                str_cat[i] = str_cat[j];
                str_cat[j] = temp;
            }
        }
    }

    for (int i = 0; i < strlen(str_cat); i++) {
        str_cat[i] = convert(str_cat[i]);
    }

    printf("%s\n", str_cat);
    return 0;
}
