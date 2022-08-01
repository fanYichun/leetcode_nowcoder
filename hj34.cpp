#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[1001];
	scanf("%s", str);

	for (int i = 0; i < strlen(str) - 1; i++) {
		for (int j = i; j < strlen(str); j++) {
			if (str[i] > str[j]) {
				char temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	printf("%s\n", str);
	return 0;
}