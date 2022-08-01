#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char password[101];
	char str[101];

	memset(password, 0, 101);

	scanf("%s", password);
	scanf("%s", str);

	for (int i = 0; i < strlen(password); i++) {
		for (int j = i + 1; j < strlen(password); j++) {
			while (j < strlen(password) && password[j] == password[i]) {
				for (int k = j; k < strlen(password); k++) {
					password[k] = password[k + 1];
				}
			}
		}
	}

	int add_index = strlen(password);
	for (int i = 0; i < 26; i++) {
		int flag = 0;
		for (int j = 0; j < strlen(password); j++) {
			if ('a' + i == password[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			password[add_index] = 'a' + i;
			add_index++;
		}
	}

	for (int i = 0; i < strlen(str); i++) {
		str[i] = password[str[i] - 'a'];
	}

	printf("%s\n", str);
	return 0;
}