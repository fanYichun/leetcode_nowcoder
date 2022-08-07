#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str1[151];
	char str2[151];

	scanf("%s", str1);
	scanf("%s", str2);

	int str_len1, str_len2;
	str_len1 = strlen(str1);
	str_len2 = strlen(str2);

	int* dp = (int*)malloc(str_len1 * str_len2 * sizeof(int));
	
	for (int i = 0; i < str_len1; i++) {
		dp[i * str_len2] = (str2[0] == str1[i] ? 1 : 0);
	}
	for (int j = 1; j < str_len2; j++) {
		dp[j] = (str1[0] == str2[j] ? 1 : 0);
	}

	for (int i = 1; i < str_len1; i++) {
		for (int j = 1; j < str_len2; j++) {
			dp[i * str_len2 + j] = (str1[i] == str2[j] ? 1 + dp[(i - 1) * str_len2 + (j - 1)] : 0);
		}
	}

	int max_len = 0;
	for (int i = 0; i < str_len1; i++) {
		for (int j = 0; j < str_len2; j++) {
			if (dp[i * str_len2 + j] > max_len) max_len = dp[i * str_len2 + j];
		}
	}
	printf("%d", max_len);
	return 0;
}