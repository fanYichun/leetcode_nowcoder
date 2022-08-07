#include <stdio.h>
#include <string.h>

int minimumLength(char* s) {
	int str_len = strlen(s);

	char c;
	int index_f = 0;
	int index_e = str_len - 1;
	while (index_f < index_e && s[index_f] == s[index_e]) {
		while (s[index_f + 1] == s[index_f] && index_f + 1 <= index_e) index_f++;
		index_f++;
		while (s[index_e - 1] == s[index_e] && index_e - 1 >= index_f) index_e--;
		index_e--;
	}
	int len = index_e - index_f + 1;
	if (len < 0) len = 0;
	return len;
}

int main() {
	char str[] = "cababac";
	int result = minimumLength(str);
	return 0;
}