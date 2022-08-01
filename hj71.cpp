#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int match(char* str, int str_len, char* str_temp, int str_temp_len) {
	if (str_temp_len <= 0 && str_len <= 0) return 1;
	else if (str_len <= 0 && str_temp_len > 0) {
		if (str_temp[0] != '*') {
			return 0;
		}
		else return match(str, str_len, str_temp + 1, str_temp_len - 1);
	}
	else if (str_temp_len <= 0 && str_len > 0) {
		return 0;
	}
	else if (str_temp[0] == '?') {
		int flag = 0;
		if (isalnum(str[0]) && match(str + 1, str_len - 1, str_temp + 1, str_temp_len - 1) == 1) flag = 1;
		return flag;
	}
	else if (str_temp[0] == '*') {
		int flag = 0;
		if (match(str, str_len, str_temp + 1, str_temp_len - 1) == 1) flag = 1;
		if (match(str + 1, str_len - 1, str_temp, str_temp_len) == 1) flag = 1;
		return flag;
	}
	else {
		if (tolower(str[0]) == tolower(str_temp[0])) return match(str + 1, str_len - 1, str_temp + 1, str_temp_len - 1);
		else return 0;
	}
}

int main() {
	char str_temp[101];
	char str[101];

	scanf("%s", str_temp);
	scanf("%s", str);

	int str_temp_len = strlen(str_temp);
	int str_len = strlen(str);

	//for (int i = 0; i < str_len; i++) {
	//	if (str[i] != str_temp[0]) continue;

	//	int j = 1;
	//	for (; i + j < str_len && j < str_temp_len && str[i + j] == str_temp[j]; j++);
	//	if (j != str_temp_len) continue;
	//	else {
	//		printf("true\n");
	//		return 0;
	//	}
	//}
	//printf("false\n");

	int flag = match(str, str_len, str_temp, str_temp_len);
	if (flag == 1) printf("true\n");
	else printf("false\n");

	return 0;
}