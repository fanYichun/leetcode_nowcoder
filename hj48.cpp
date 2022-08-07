#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* next;
	int value;
};

int main() {
	int N;
	scanf("%d", &N);

	struct node* node_ptr = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &(node_ptr->value));
	node_ptr->next = NULL;
	struct node* head = node_ptr;

	for (int i = 0; i < N - 1; i++) {
		struct node* node_ptr = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &(node_ptr->value));

		int previous_value;
		scanf("%d", &previous_value);

		for (struct node* ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->value == previous_value) {
				node_ptr->next = ptr->next;
				ptr->next = node_ptr;
				break;
			}
		}
	}

	int delete_value;
	scanf("%d", &delete_value);

	for (struct node* ptr = head; ptr != NULL && ptr->next != NULL; ptr = ptr->next) {
		if (ptr->next->value == delete_value) {
			struct node* temp = ptr->next;
			ptr->next = temp->next;
			free(temp);
			break;
		}
	}
	if (head->value == delete_value) {
		struct node* temp = head;
		head = temp->next;
		free(temp);
	}

	for (struct node* ptr = head; ptr != NULL; ptr = ptr->next) {
		printf("%d ", ptr->value);
	}

	struct node* tmp;
	for (struct node* ptr = head; ptr != NULL;) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	return 0;
}