#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int height[3000];

	for (int i = 0; i < n; i++) {
		scanf("%d", height + i);
	}

	int left_num[3000];
	int right_num[3000];

	left_num[0] = 0;
	for (int i = 1; i < n; i++) {
		int max_num = 0;
		for (int j = 0; j < i; j++) {
			if (height[i] > height[j] && left_num[j] + 1 > max_num)
				max_num = left_num[j] + 1;
		}
		left_num[i] = max_num;
	}

	right_num[n-1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		int max_num = 0;
		for (int j = n - 1; j > i; j--) {
			if (height[i] > height[j] && right_num[j] + 1 > max_num)
				max_num = right_num[j] + 1;
		}
		right_num[i] = max_num;
	}

	int total_num[3000];
	int max_num = 1;
	for (int i = 0; i < n; i++) {
		total_num[i] = left_num[i] + right_num[i] + 1;
		if (total_num[i] > max_num) max_num = total_num[i];
	}
	printf("%d", n - max_num);
	return 0;
}