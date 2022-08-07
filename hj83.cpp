#include <stdio.h>
#include <stdlib.h>

int is_valid(int num, int min, int max) {
	return (num <= max && num >= min);
}

void print_valid(int valid_flag) {
	if (valid_flag) printf("0\n");
	else printf("-1\n");
	return;
}

int main() {
	int m, n;
	int valid_flag = 1;
	int x1, y1, x2, y2;
	int x, y;

	while (scanf("%d %d", &m, &n) != EOF) {
		valid_flag = is_valid(m, 1, 9) && is_valid(n, 1, 9);
		print_valid(valid_flag);

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		valid_flag = is_valid(x1, 0, m - 1) && is_valid(y1, 0, n - 1) && is_valid(x2, 0, m - 1) & is_valid(y2, 0, n - 1);
		print_valid(valid_flag);

		scanf("%d", &x);
		valid_flag = is_valid(x, 0, m - 1) && is_valid(m + 1, 1, 9);
		print_valid(valid_flag);

		scanf("%d", &y);
		valid_flag = is_valid(y, 0, n - 1) && is_valid(n + 1, 1, 9);
		print_valid(valid_flag);

		scanf("%d %d", &x, &y);
		valid_flag = is_valid(x, 0, m - 1) && is_valid(y, 0, n - 1);
		print_valid(valid_flag);
	}
	return 0;
}