#include <stdio.h>
#include <stdlib.h>

int sort(int n, int k, int* arr) {
	for (int* ptr = arr; arr + k > ptr; ptr++) {
		for (int* ptr2 = ptr + 1; arr + n > ptr2; ptr2++) {
			if (*ptr > *ptr2) {
				int temp = *ptr;
				*ptr = *ptr2;
				*ptr2 = temp;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

int main() {
	int n, k;
	int* arr;

	while (scanf("%d", &n) != EOF) {
		scanf("%d", &k);
		arr = (int*)malloc(n * sizeof(int));

		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		sort(n, k, arr);
		free(arr);
	}
	
	return 0;
}