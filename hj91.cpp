#include <stdio.h>
#include <string.h>

int main() {
	int mat[8][8];

	int n, m;
	scanf("%d %d", &n, &m);
	n++;
	m++;

	for (int i = 0; i < n; i++) {
		mat[i][m-1] = 1;
	}
	for (int j = 0; j < m; j++) {
		mat[n-1][j] = 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			mat[i][j] = mat[i + 1][j] + mat[i][j + 1];
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		printf("%d ", mat[i][j]);
	//	}
	//	printf("\n");
	//}

	printf("%d", mat[0][0]);

	return 0;
}