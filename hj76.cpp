#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int m;
	scanf("%d", &m);

	int m3 = m * m * m;
	int m3_m = m3 / m + 1;

	for (int i = 1; i < m3_m; i = i + 2) {
		if (m * (i + m - 1) == m3) {
			for (int j = 0; j < m; j++) {
				printf("%d", i + 2 * j);
				if (j != m - 1) printf("+");
			}
			printf("\n");
		}
	}
	return 0;
}