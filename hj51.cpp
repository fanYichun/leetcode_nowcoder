#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

int main() {
	int N;

	while (scanf("%d", &N) != EOF) {

		struct node* head;
		head = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &(head->value));
		head->next = NULL;
		struct node* previos = head;
		struct node* ptr;

		for (int i = 0; i < N - 1; i++) {
			ptr = (struct node*)malloc(sizeof(struct node));
			scanf("%d", &(ptr->value));
			ptr->next = NULL;
			previos->next = ptr;
			previos = ptr;
		}

		int node_cnt = 0;
		for (struct node* ptr = head; ptr != NULL; ptr = ptr->next) {
			node_cnt++;
			//printf("%d ", ptr->value);
		}

		int k;
		scanf("%d", &k);

		int cnt_index = 0;
		for (struct node* ptr = head; ptr != NULL; ptr = ptr->next) {
			cnt_index++;
			if (cnt_index == node_cnt - k + 1) printf("%d\n", ptr->value);
		}
	}

	return 0;
}