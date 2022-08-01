#include <stdio.h>
#include <stdlib.h>

int main() {
	int temp;
	scanf("%d", &temp);

	for (int i = 0; i < 4; i++) {
		int a = 4 * i;
		int b = 25 - 7 * i;
		int c = 100 - a - b;
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}