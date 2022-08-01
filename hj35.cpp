#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);

	int i_init = 1;
	for (int i = 0; i < N; i++) {
		int j_init = i_init;
		for (int j = 0; j < N - i; j++) {
			printf("%d ", j_init);
			j_init += 2 + i + j;
		}
		printf("\n");
		i_init += 1 + i;
	}
	return 0;
}