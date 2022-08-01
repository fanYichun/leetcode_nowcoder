#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n < 3) printf("-1");
	else if (n % 4 == 0) printf("3");
	else if (n % 4 == 1) printf("2");
	else if (n % 4 == 2) printf("4");
	else printf("2");
	return 0;
}