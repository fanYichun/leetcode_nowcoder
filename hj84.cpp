#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[251];
	scanf("%[^\n]s", str);

	int num = 0;
	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') num++;
	}

	printf("%d", num);
	return 0;
}