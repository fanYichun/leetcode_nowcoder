#include <stdio.h>

int count_one(int in) {
	int cnt = 0;
	for (int i = 0; i < 32; i++) {
		cnt += ((in >> i) & 0x1);
	}
	return cnt;
}

int main() {
	int num;
	while (scanf("%d", &num) != EOF) {
		printf("%d\n", count_one(num));
	}
	return 0;
}