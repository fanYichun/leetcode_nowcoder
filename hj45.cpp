#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate_pretty(char* str) {
    int al_cnt[26];
    memset(al_cnt, 0, 26 * sizeof(int));

    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        al_cnt[tolower(str[i]) - 'a']++;
    }

    int al_arr[26];
    for (int i = 0; i < 26; i++) {
        al_arr[i] = i + 'a';
    }

    for (int i = 0; i < 25; i++) {
        for (int j = i; j < 26; j++) {
            if (al_cnt[i] > al_cnt[j]) {
                int temp = al_cnt[i];
                al_cnt[i] = al_cnt[j];
                al_cnt[j] = temp;

                temp = al_arr[i];
                al_arr[i] = al_arr[j];
                al_arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        al_cnt[i] = i + 1;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = i; j < 26; j++) {
            if (al_arr[i] > al_arr[j]) {
                int temp = al_cnt[i];
                al_cnt[i] = al_cnt[j];
                al_cnt[j] = temp;

                temp = al_arr[i];
                al_arr[i] = al_arr[j];
                al_arr[j] = temp;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < str_len; i++) {
        ret += al_cnt[tolower(str[i]) - 'a'];
    }

    return ret;
}

int main() {
    int N;
    scanf("%d", &N);

    const int max_str_len = 10001;
    char** str_arr = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        str_arr[i] = (char*)malloc(max_str_len * sizeof(char));
        scanf("%s", str_arr[i]);
    }

    int pretty;

    for (int i = 0; i < N; i++) {
        pretty = calculate_pretty(str_arr[i]);
        printf("%d\n", pretty);
    }

    return 0;
}