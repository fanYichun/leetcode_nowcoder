#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n1, n2;
	scanf("%d", &n1);

	int* arr1 = (int*)malloc(n1 * sizeof(int));
	for (int i = 0; i < n1; i++) {
		scanf("%d", arr1 + i);
	}

	scanf("%d", &n2);

	int* arr2 = (int*)malloc(n2 * sizeof(int));
	for (int i = 0; i < n2; i++) {
		scanf("%d", arr2 + i);
	}

	int* result = (int*)malloc((n1 + n2) * sizeof(int));
	memcpy(result, arr1, n1 * sizeof(int));
	memcpy(result + n1, arr2, n2 * sizeof(int));

	int num_all = n1 + n2;

	for (int i = 0; i < n1 + n2; i++) {
		for (int j = i + 1; j < n1 + n2; j++) {
			if (result[i] > result[j]) {
				int temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
		}
	}

	for (int i = 0; i < num_all - 1; i++) {
		while (result[i] == result[i + 1]) {
			for (int j = i + 1; j < num_all - 1; j++) {
				result[j] = result[j + 1];
			}
			num_all--;
		}
	}

	for (int i = 0; i < num_all; i++) {
		printf("%d", result[i]);
	}

	free(arr1);
	free(arr2);
	free(result);

	return 0;
}