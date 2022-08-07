#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	char str[19];

	while (scanf("%s", str) != EOF) {
		int str_len = strlen(str);
		int flag = 0;

		int start_index[5] = { 0 };
		int stop_index[5] = { 0 };
		int num_cnt = 0;

		for (int i = 0; i < str_len; i++) {
			if (str[i] == '.') {
				stop_index[num_cnt] = i;
				num_cnt++;
				start_index[num_cnt] = i + 1;
				if (num_cnt > 3) flag = 1;
				str[i] = 0;
			}
			else if (!isdigit(str[i])) {
				flag = 1;
			}
		}
		stop_index[3] = str_len;
		if (num_cnt != 3) flag = 1;

		for (int i = 0; i < 4; i++) {
			int temp = 0;
			if (start_index[i] == stop_index[i]) flag = 1;
			if (str[start_index[i]] == '0' && str[start_index[i] + 1] != 0) flag = 1;
			for (int j = start_index[i]; j < stop_index[i]; j++) {
				temp = temp * 10 + str[j] - '0';
			}
			if (!(temp >= 0 && temp <= 255)) flag = 1;
		}

		if (flag == 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}