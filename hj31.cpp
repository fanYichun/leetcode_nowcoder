#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	const int str_len = 10000 + 1;
	char str[str_len];
	scanf("%[^\n]s", str);

	int start_index[str_len];
	int stop_index[str_len];
	int valid_len = strlen(str);

	int flag1 = 0, flag2 = 0;
	int word_num = 0;

	for (int i = 0; i < valid_len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') flag1 = 1;
		else flag1 = 0;

		if (flag1 == 1 && flag2 == 0) {
			start_index[word_num] = i;
		}
		else if (flag1 == 0 && flag2 == 1) {
			stop_index[word_num] = i;
			word_num++;
		}

		flag2 = flag1;
	}

	if (flag2 == 1) {
		stop_index[word_num] = valid_len;
		word_num++;
	}

	//for (int i = 0; i < word_num; i++)
	//	printf("%d,%d\n", start_index[i], stop_index[i]);

	for (int i = word_num - 1; i >= 0; i--) {
		for (int j = start_index[i]; j < stop_index[i]; j++)
			printf("%c", str[j]);
		printf(" ");
	}

	return 0;
}