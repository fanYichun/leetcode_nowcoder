#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str[1001];
	scanf("%[^\n]s", str);

	int alpha = 0, space = 0, num = 0, other = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') alpha++;
		else if (str[i] >= 'A' && str[i] <= 'Z') alpha++;
		else if (str[i] >= '0' && str[i] <= '9') num++;
		else if (str[i] == ' ') space++;
		else other++;
	}
	printf("%d\n%d\n%d\n%d\n", alpha, space, num, other);
	return 0;
}