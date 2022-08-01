#include <stdio.h>

int main() {
	int y, m, d;
	scanf("%d %d %d", &y, &m, &d);

	int flag = 0;
	if (y % 4 == 0 && y % 100 != 0) {
		flag = 1;
	}
	if (y % 400 == 0) flag = 1;

	int num[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (flag) num[1] = 29;

	int cnt = 0;
	for (int i = 1; i < m; i++) {
		cnt += num[i - 1];
	}
	cnt += d;

	printf("%d", cnt);
	return 0;
}