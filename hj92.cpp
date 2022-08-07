#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str[201];

	while (scanf("%s", str) != EOF) {

		int str_len = strlen(str);

		int dig_flag = 0;
		int dig_flag_d = dig_flag;
		int len_cnt = 0;

		int sub_len[201];
		int sub_index[201];
		int sub_len_cnt = 0;

		int max_cnt = 0;

		for (int i = 0; i < str_len; i++) {
			if (isdigit(str[i])) {
				dig_flag = 1;
				len_cnt++;
			}
			else {
				dig_flag = 0;
			}
			if (dig_flag_d == 1 && dig_flag == 0) {
				sub_len[sub_len_cnt] = len_cnt;
				if (len_cnt > max_cnt) max_cnt = len_cnt;
				sub_index[sub_len_cnt] = i;
				sub_len_cnt++;
				len_cnt = 0;
				str[i] = 0;
			}

			dig_flag_d = dig_flag;
		}
		if (dig_flag == 1) {
			sub_len[sub_len_cnt] = len_cnt;
			if (len_cnt > max_cnt) max_cnt = len_cnt;
			sub_index[sub_len_cnt] = str_len;
			sub_len_cnt++;
		}

		for (int i = 0; i < sub_len_cnt; i++) {
			for (int j = i + 1; j < sub_len_cnt; j++) {
				if (sub_len[i] < sub_len[j]) {
					int temp = sub_len[i];
					sub_len[i] = sub_len[j];
					sub_len[j] = temp;

					temp = sub_index[i];
					sub_index[i] = sub_index[j];
					sub_index[j] = temp;
				}
			}
			if (sub_len[i] < max_cnt) break;
		}

		for (int i = 0; i < sub_len_cnt; i++) {
			if (sub_len[i] < max_cnt) break;
			printf("%s", str + sub_index[i] - sub_len[i]);
		}
		printf(",%d\n", max_cnt);

	}

	return 0;
}