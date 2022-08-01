#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str[1001];
	scanf("%[^\n]s", str);

	int start_index[1001];
	memset(start_index, 0, 1001);

	int word_cnt = 0;

	int valid_flag = 0;
	int valid_flag_d = valid_flag;
	int quote_flag = 0;

	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {
		if (str[i] == '"') {
			quote_flag = !quote_flag;
			if (quote_flag == 0) {
				valid_flag = 0;
			}
		}
		else if (str[i] == ' ' && quote_flag == 0) {
			valid_flag = 0;
		}
		else {
			valid_flag = 1;
		}

		if (valid_flag_d == 0 && valid_flag == 1) {
			start_index[word_cnt] = i;
			word_cnt++;
		}
		if (valid_flag_d == 1 && valid_flag == 0) {
			str[i] = 0;
		}
		valid_flag_d = valid_flag;
	}

	printf("%d\n", word_cnt);
	for (int i = 0; i < word_cnt; i++) {
		printf("%s\n", str + start_index[i]);
	}
	return 0;
}