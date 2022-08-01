#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[20];
	scanf("%s", str);

	unsigned ip_int;
	scanf("%u", &ip_int);

	int start_index[4];
	start_index[0] = 0;
	int start_index_cnt = 1;
	unsigned ip_to_int = 0;
	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {
		if (str[i] == '.') {
			str[i] = 0;
			start_index[start_index_cnt] = i + 1;
			start_index_cnt++;
		}
	}

	ip_to_int += (atoi(str) << 24);
	ip_to_int += (atoi(str + start_index[1]) << 16);
	ip_to_int += (atoi(str + start_index[2]) << 8);
	ip_to_int += (atoi(str + start_index[3]));
	printf("%u\n", ip_to_int);


	unsigned ip_convert[4];
	ip_convert[0] = ((ip_int & (0xff << 24)) >> 24);
	ip_convert[1] = ((ip_int & (0xff << 16)) >> 16);
	ip_convert[2] = ((ip_int & (0xff << 8)) >> 8);
	ip_convert[3] = (ip_int & 0xff);
	printf("%u.%u.%u.%u\n", ip_convert[0], ip_convert[1], ip_convert[2], ip_convert[3]);

	return 0;
}