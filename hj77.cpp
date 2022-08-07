#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct station {
	struct station* next;
	int train_code;
};

struct station* stack_push(struct station* stack, int train) {
	struct station* node = (struct station*)malloc(sizeof(struct station));
	node->next = stack;
	node->train_code = train;
	return node;
}

struct station* stack_pop(struct station* stack, int* train) {
	struct station* node = stack->next;
	*train = stack->train_code;
	free(stack);
	return node;
}

struct station* stack_copy(struct station* stack) {
	struct station* stack_c = NULL;
	struct station* stack_head = NULL;
	
	while (stack != NULL) {
		struct station* node = (struct station*)malloc(sizeof(struct station));
		if (stack_head == NULL) stack_head = node;
		else {
			stack_c->next = node;
		}
		node->next = NULL;
		node->train_code = stack->train_code;
		stack = stack->next;
		stack_c = node;
	}

	return stack_head;
}

int train_control(int total, int num_in, int* in_serial, struct station* st, int num_out, int* out_serial) {
	if (num_in == total && num_out == total) {
		for (int i = 0; i < total; i++) {
			printf("%d ", out_serial[i]);
		}
		printf("\n");
	}
	else if (num_in == total && num_out < total) {
		st = stack_pop(st, out_serial + num_out);
		train_control(total, num_in, in_serial, st, num_out + 1, out_serial);
	}
	else {
		if (num_in > num_out) {
			struct station* st2 = stack_copy(st);
			st2 = stack_pop(st2, out_serial + num_out);
			train_control(total, num_in, in_serial, st2, num_out + 1, out_serial);
		}

		st = stack_push(st, in_serial[num_in]);
		train_control(total, num_in + 1, in_serial, st, num_out, out_serial);
	}
	return 0;
}

int main() {
	int N;
	scanf("%d", &N);

	int train_serial[10];
	int out_serial[10];
	memset(train_serial, 0, sizeof(train_serial));
	memset(out_serial, 0, sizeof(out_serial));

	for (int i = 0; i < N; i++) {
		scanf("%d", train_serial + i);
	}

	struct station* st = NULL;

	train_control(N, 0, train_serial, st, 0, out_serial);
	return 0;
}