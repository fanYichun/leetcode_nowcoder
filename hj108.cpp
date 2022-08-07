#include <stdio.h>

int gcd(int s, int l) {
	int m = l % s;
	if (m == 0) return s;
	else return gcd(m, s);
}

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	int l, s;

	l = (a > b ? a : b);
	s = (a > b ? b : a);

	int g = gcd(s, l);

	int res = a * b / g;

	printf("%d", res);
	return 0;
}