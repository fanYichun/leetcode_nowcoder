#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
	int n_sqrt = sqrt(n);
	for (int i = 2; i <= n_sqrt; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int even;
	scanf("%d", &even);

	for (int i = even / 2; i >= 2; i--) {
		if (is_prime(i) && is_prime(even - i)) {
			printf("%d\n%d\n", i, even - i);
			return 0;
		}
	}
	return 0;
}