#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int A[100][100];
	int B[100][100];
	int C[100][100];

	int x, y, z;
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int j = 0; j < y; j++) {
		for (int k = 0; k < z; k++) {
			scanf("%d", &B[j][k]);
		}
	}

	for (int i = 0; i < x; i++) {
		for (int k = 0; k < z; k++) {
			int sum = 0;
			for (int j = 0; j < y; j++) {
				sum += A[i][j] * B[j][k];
			}
			C[i][k] = sum;
			printf("%d ", sum);
		}
		printf("\n");
	}

	return 0;
}