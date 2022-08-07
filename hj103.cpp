#include <stdio.h>
#include <string.h>

int main() {
	int n;
	int arr[200];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	int step[200];
	step[n - 1] = 1;
	int max_step_all = 0;

	for (int i = n - 2; i >= 0; i--) {
		int max_step = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				int temp = step[j] + 1;
				if (temp > max_step) max_step = temp;
			}
		}
		step[i] = max_step;
		if (max_step > max_step_all) max_step_all = max_step;
	}

	printf("%d", max_step_all);
	return 0;
}