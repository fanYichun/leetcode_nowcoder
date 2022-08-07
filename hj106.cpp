#include <stdio.h>
#include <string.h>

int main() {
	char str[10001];
	scanf("%[^\n]s", str);
	int str_len = strlen(str);

	for (int i = 0; i < str_len / 2; i++) {
		char temp = str[i];
		str[i] = str[str_len - 1 - i];
		str[str_len - 1 - i] = temp;
	}
	printf("%s\n", str);
	return 0;
}