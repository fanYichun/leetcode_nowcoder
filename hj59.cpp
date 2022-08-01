#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[1001];
	scanf("%s", str);
	char tag[1001];
	memset(tag, 0, 1001);

	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {
		int flag = 0;
		for (int j = i + 1; tag[i] == 0 && j < str_len; j++) {
			if (str[j] == str[i]) {
				flag = 1;
				tag[j] = 1;
			}
		}
		if (tag[i] == 0 && flag == 0) {
			printf("%c", str[i]);
			return 0;
		}
	}

	printf("-1");
	return 0;
}