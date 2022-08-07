#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str1[301];
	char str2[301];

	scanf("%s", str1);
	scanf("%s", str2);

	int str_len1 = strlen(str1);
	int str_len2 = strlen(str2);

	char* str_s = (str_len1 > str_len2 ? str2 : str1);
	char* str_l = (str_len1 > str_len2 ? str1 : str2);

	int str_len_s = (str_len1 > str_len2 ? str_len2 : str_len1);
	int str_len_l = (str_len1 > str_len2 ? str_len1 : str_len2);

	int max_len = 0;
	int max_index = 0;

	for (int i = 0; i < str_len_s; i++) {
		for (int j = 0; j < str_len_l; j++) {
			int k = 0;
			for (; i + k < str_len_s && j + k < str_len_l && str_s[i + k] == str_l[j + k]; k++);
			if (k > max_len) {
				max_len = k;
				max_index = i;
			}
		}
	}

	str_s[max_index + max_len] = 0;
	printf("%s\n", str_s + max_index);
	return 0;
}