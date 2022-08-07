#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sort_str(const char* str) {
    char* ret_str = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(ret_str, str);

    for (int i = 0; i < strlen(ret_str) - 1; i++) {
        for (int j = i; j < strlen(ret_str); j++) {
            if (ret_str[i] > ret_str[j]) {
                char temp = ret_str[i];
                ret_str[i] = ret_str[j];
                ret_str[j] = temp;
            }
        }
    }
    
    return ret_str;
}

int sort_cmp(char* str1, char* str2) {
    if (strcmp(str1, str2) == 0) return 1;

    char* sort_str1 = sort_str(str1);
    char* sort_str2 = sort_str(str2);
    int ret = strcmp(sort_str1, sort_str2);
    free(sort_str1);
    free(sort_str2);

    return ret;
}

int main() {
    int bro_num;
    scanf("%d", &bro_num);

    char** bro_dict = (char**)malloc(bro_num * sizeof(char**));
    for (int i = 0; i < bro_num; i++) {
        bro_dict[i] = (char*)malloc(11 * sizeof(char));
        scanf("%s", bro_dict[i]);
    }

    char x[11];
    scanf("%s", x);
    int k;
    scanf("%d", &k);

    int* bro_valid_flag;
    bro_valid_flag = (int*)malloc(bro_num * sizeof(int));
    memset(bro_valid_flag, 0, bro_num * sizeof(int));

    int bro_valid_num = 0;
    for (int i = 0; i < bro_num; i++) {
        if (sort_cmp(bro_dict[i], x) == 0) {
            bro_valid_num++;
            bro_valid_flag[i] = 1;
        }
    }

    printf("%d\n", bro_valid_num);

    for (int i = 0; i < bro_num - 1; i++) {
        for (int j = i; j < bro_num; j++) {
            if (strcmp(bro_dict[i], bro_dict[j])>0) {
                char *temp = bro_dict[i];
                bro_dict[i] = bro_dict[j];
                bro_dict[j] = temp;

                char temp2 = bro_valid_flag[i];
                bro_valid_flag[i] = bro_valid_flag[j];
                bro_valid_flag[j] = temp2;
            }
        }
    }

    char* kth_bro;
    int valid_index_cnt = 0;
    int valid_i;
    for (valid_i = 0; valid_i < bro_num; valid_i++) {
        if (bro_valid_flag[valid_i] == 1) valid_index_cnt++;
        if (valid_index_cnt == k) break;
    }
    if (valid_index_cnt == k) printf("%s\n", bro_dict[valid_i]);
    
    for (int i = 0; i < bro_num; i++) {
        free(bro_dict[i]);
    }
    free(bro_dict);
    return 0;
}