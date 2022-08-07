#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfWeakCharacters(int** properties, int propertiesSize, int* propertiesColSize) {
	int* max_defense = (int*)malloc(100002 * sizeof(int));
	memset(max_defense, 0, 100002 * sizeof(int));

	for (int i = 0; i < propertiesSize; i++) {
		int attack = properties[i][0];
		int defense = properties[i][1];
		if (defense > max_defense[attack]) max_defense[attack] = defense;
	}

	for (int i = 100000 - 2; i >= 0; i--) {
		max_defense[i] = (max_defense[i + 1] > max_defense[i] ? max_defense[i + 1] : max_defense[i]);
	}

	int cnt = 0;
	for (int i = 0; i < propertiesSize; i++) {
		int attack = properties[i][0];
		int defense = properties[i][1];
		if (defense < max_defense[attack + 1]) cnt++;
	}
	return cnt;
}

int main() {
	
}