#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
	const int str_max = 10001;
	char str1[str_max];
	char str2[str_max];
	char str_res[str_max+1];

	memset(str1, 0, str_max);
	memset(str2, 0, str_max);
	memset(str_res, 0, str_max+1);

	scanf("%s", str1);
	scanf("%s", str2);

	int str_len1 = strlen(str1);
	int str_len2 = strlen(str2);
	for (int i = 0; i < str_len1 / 2; i++) {
		char temp = str1[i];
		str1[i] = str1[str_len1 - 1 - i];
		str1[str_len1 - 1 - i] = temp;
	}
	for (int i = 0; i < str_len2 / 2; i++) {
		char temp = str2[i];
		str2[i] = str2[str_len2 - 1 - i];
		str2[str_len2 - 1 - i] = temp;
	}

	/*printf("%s\n", str1);
	printf("%s\n", str2);*/

	int carry = 0;
	int min_str_len = (str_len1 > str_len2 ? str_len2 : str_len1);
	int max_str_len = (str_len1 > str_len2 ? str_len1 : str_len2);
	char* ptr = (str_len1 > str_len2 ? str2 : str1);

	for (int i = 0; i < max_str_len; i++) {
		char add1 = (str1[i] == 0 ? '0' : str1[i]);
		char add2 = (str2[i] == 0 ? '0' : str2[i]);
		char add = add1 + add2 - '0' - '0' + carry;
		str_res[i] = '0' + (add % 10);
		carry = add / 10;
	}

	str_res[max_str_len] = carry + '0';

	int str_len_res = strlen(str_res);
	for (int i = str_len_res-1; i > 0; i--) {
		if (str_res[i] == '0') str_res[i] = 0;
		else if (str_res[i] != 0) break;
	}

	str_len_res = strlen(str_res);
	for (int i = 0; i < str_len_res / 2; i++) {
		char temp = str_res[i];
		str_res[i] = str_res[str_len_res - 1 - i];
		str_res[str_len_res - 1 - i] = temp;
	}
	printf("%s\n", str_res);

	return 0;
}
