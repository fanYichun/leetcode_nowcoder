#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 7 == 0) cnt++;
		else {
			int temp = i;
			while (temp > 0) {
				if (temp % 10 == 7) {
					cnt++;
					break;
				}
				temp = temp / 10;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}