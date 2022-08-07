#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int find_min(int a, int b, int c) {
	int min_ab = (a > b ? b : a);
	int min_ac = (a > c ? c : a);
	return (min_ab > min_ac ? min_ac : min_ab);
}

int main() {
	char str1[1002];
	char str2[1002];

	str1[0] = ' ';
	str2[0] = ' ';

	scanf("%s", str1 + 1);
	scanf("%s", str2 + 1);

	int str_len1, str_len2;
	str_len1 = strlen(str1);
	str_len2 = strlen(str2);

	int* length = (int*)malloc(str_len1 * str_len2 * sizeof(int));
	for (int i = 0; i < str_len1; i++) {
		length[i * str_len2 + 0] = i;
	}
	for (int i = 1; i < str_len2; i++) {
		length[i] = i;
	}
	for (int i = 1; i < str_len1; i++) {
		for (int j = 1; j < str_len2; j++) {
			if (str1[i] == str2[j]) length[i * str_len2 + j] = length[(i - 1) * str_len2 + j - 1];
			else length[i * str_len2 + j] = find_min(length[(i - 1) * str_len2 + j], 
				length[i * str_len2 + j - 1], length[(i - 1) * str_len2 + j - 1]) + 1;
		}
	}
	printf("%d", length[(str_len1 - 1) * str_len2 + str_len2 - 1]);
	return 0;
}