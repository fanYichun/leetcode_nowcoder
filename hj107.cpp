#include <stdio.h>

double guess(double init, double range_l, double range_u, double num) {
	double prod = init * init * init;
	if (num - prod < 0.05 && num - prod > -0.05) return init;
	else if (num > prod) return guess((init + range_u) / 2, init, range_u, num);
	else return guess((init + range_l) / 2, range_l, init, num);
}

int main() {
	double num;
	scanf("%lf", &num);

	double sign = (num > 0 ? 1 : 0);
	if (sign == 0) num = -num;

	double range_l, range_u;

	if (num > 1) {
		range_l = 1;
		range_u = num;
	}
	else {
		range_l = 0;
		range_u = 1;
	}

	double g = guess(1, range_l, range_u, num);

	if (sign == 0) g = -g;

	printf("%.1lf", g);
	return 0;
}