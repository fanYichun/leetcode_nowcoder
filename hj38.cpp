#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int height;
	scanf("%d", &height);

	printf("%f\n%f\n", (float)height * 23 / 8, (float)height / 32);
	return 0;
}