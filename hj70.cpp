#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct op {
	int x;
	int y;
	int cnt;
};

struct op_node {
	struct op_node* next;
	struct op matrix;
};

struct op_node* stack_push(struct op_node* stack, struct op item) {
	struct op_node* new_node = (struct op_node*)malloc(sizeof(struct op_node));
	new_node->matrix = item;
	new_node->next = stack;
	return new_node;
}

struct op_node* stack_pop(struct op_node* stack, struct op* item) {
	struct op_node* temp = stack->next;
	*item = stack->matrix;
	free(stack);
	return temp;
}

int main() {
	int n;
	scanf("%d", &n);

	char in;
	struct op op_arr[15];
	memset(op_arr, 0, sizeof(op_arr));

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(op_arr[i].x), &(op_arr[i].y));
		op_arr[i].cnt = 0;
	}

	struct op_node* op_stack = NULL;
	struct op op1, op2, op_res;
	int mat_cnt = 0;

	scanf("%c", &in);
	scanf("%c", &in);

	while (in != '\n') {
		if (in == ')') {
			op_stack = stack_pop(op_stack, &op2);
			op_stack = stack_pop(op_stack, &op1);
			op_res.x = op1.x;
			op_res.y = op2.y;
			op_res.cnt = op1.cnt + op2.cnt + op1.x * op1.y * op2.y;
			op_stack = stack_push(op_stack, op_res);
		}
		else if (isalpha(in)) {
			op_stack = stack_push(op_stack, op_arr[mat_cnt]);
			mat_cnt++;
		}
		scanf("%c", &in);
	}

	op_stack = stack_pop(op_stack, &op_res);
	printf("%d\n", op_res.cnt);
	
	return 0;
}