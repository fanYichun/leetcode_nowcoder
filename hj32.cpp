#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	const int str_max = 2501;
	char str[str_max];
	scanf("%s", str);

	int max_sub_len = 1;
	for (int i = 0; i < strlen(str); i++) {
		int sub_j = 1;
		for (; i - sub_j >= 0 && i + sub_j < strlen(str); sub_j++) {
			if (str[i - sub_j] != str[i + sub_j]) break;
		}

		int sub_j2 = 0;
		for (; i - sub_j2 >= 0 && i + 1 + sub_j2 < strlen(str); sub_j2++) {
			if (str[i - sub_j2] != str[i + 1 + sub_j2]) break;
		}
		if (2 * sub_j - 1 > max_sub_len) max_sub_len = 2 * sub_j - 1;
		if (2 * sub_j2 > max_sub_len) max_sub_len = 2 * sub_j2;
	}
	printf("%d\n", max_sub_len);
	return 0;
}