#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char DNA_str[1001];
	scanf("%s", DNA_str);

	int sub_str_len;
	scanf("%d", &sub_str_len);

	int gc_cnt = 0;
	for (int i = 0; i < sub_str_len; i++) {
		if (DNA_str[i] == 'G' || DNA_str[i] == 'C') gc_cnt++;
	}

	int max_gc_cnt = gc_cnt;
	int max_gc_index = 0;

	int str_len = strlen(DNA_str);

	for (int j = sub_str_len; j < str_len; j++) {
		if (DNA_str[j] == 'G' || DNA_str[j] == 'C') gc_cnt++;
		if (DNA_str[j - sub_str_len] == 'G' || DNA_str[j - sub_str_len] == 'C') gc_cnt--;
		
		if (gc_cnt > max_gc_cnt) {
			max_gc_cnt = gc_cnt;
			max_gc_index = j - sub_str_len + 1;
		}
	}

	DNA_str[max_gc_index + sub_str_len] = 0;
	printf("%s", DNA_str + max_gc_index);

	return 0;
}