#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visit[4];
double item[4];
int flag;

int helper(double res, int item_num) {
	if (item_num == 0) {
		if (res == 24) flag = 1;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				int r0 = helper(res + item[i], item_num - 1);
				int r1 = helper(res - item[i], item_num - 1);
				int r2 = helper(res * item[i], item_num - 1);
				int r3 = helper(res / item[i], item_num - 1);
				visit[i] = 0;
			}
		}
	}
	return 0;
}

int main() {
	while (scanf("%lf %lf %lf %lf", item, item + 1, item + 2, item + 3) != EOF) {
		flag = 0;
		memset(visit, 0, 4 * sizeof(int));
		helper(0, 4);

		if (flag == 1) printf("true\n");
		else printf("false\n");
	}
	return 0;
}