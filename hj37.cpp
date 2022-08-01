#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int now_num[31];
	int new_born[31];
	now_num[0] = 1;
	now_num[1] = 1;
	new_born[0] = 0;
	new_born[1] = 0;
	for (int i = 2; i < 31; i++) {
		new_born[i] = now_num[i - 2];
		now_num[i] = now_num[i - 1] + new_born[i];
	}
	printf("%d\n", now_num[n-1]);
	return 0;
}