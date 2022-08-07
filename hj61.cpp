#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int m, int n) {
	if (m < 0 || n < 0) return 0;
	else if (m <= 1 || n <= 1) return 1;
	else return f(m - n, n) + f(m, n - 1);
}

int main() {
	int num[11][11];

	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);

	int cases = f(m, n);
	printf("%d\n", cases);
	return 0;
}