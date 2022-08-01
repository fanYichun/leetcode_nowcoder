#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* next[4];
	struct node* previous;
	int x;
	int y;
	int visit;
};

struct fifo_node {
	struct fifo_node* next;
	struct node* this_node;
};

void push_item(struct fifo_node** fifo_head, struct fifo_node** fifo_tail, struct node* item) {
	struct fifo_node* this_node = (struct fifo_node*)malloc(sizeof(struct fifo_node));
	this_node->next = NULL;
	this_node->this_node = item;

	if (*fifo_head != NULL) {
		(*fifo_tail)->next = this_node;
		*fifo_tail = this_node;
	}
	else {
		*fifo_head = this_node;
		*fifo_tail = this_node;
	}
	return;
}

struct fifo_node* pop_item(struct fifo_node** fifo_head, struct fifo_node** fifo_tail) {
	struct fifo_node* ret = *fifo_head;
	*fifo_head = ret->next;

	if (*fifo_head == NULL) *fifo_tail = NULL;
	return ret;
}

void push_stack_item(struct fifo_node** stack_head, struct node* item) {
	struct fifo_node* this_node = (struct fifo_node*)malloc(sizeof(struct fifo_node));
	this_node->next = *stack_head;
	this_node->this_node = item;

	*stack_head = this_node;
	return;
}

struct fifo_node* pop_stack_item(struct fifo_node** stack_head) {
	struct fifo_node* ret = *stack_head;
	*stack_head = ret->next;
	return ret;
}

void find_next(struct node* matrix, int x, int y, int* shape, int N, int M) {
	if (x - 1 >= 0 && shape[(x - 1) * M + y] == 0) { // up
		matrix[x * M + y].next[0] = &matrix[(x - 1) * M + y];
	}
	else matrix[x * M + y].next[0] = NULL;
	
	if (x + 1 < N && shape[(x + 1) * M + y] == 0) { // down
		matrix[x * M + y].next[1] = &matrix[(x + 1) * M + y];
	}
	else matrix[x * M + y].next[1] = NULL;

	if (y - 1 >= 0 && shape[x * M + y - 1] == 0) { // left
		matrix[x * M + y].next[2] = &matrix[x * M + y - 1];
	}
	else matrix[x * M + y].next[2] = NULL;

	if (y + 1 < M && shape[x * M + y + 1] == 0) { // right
		matrix[x * M + y].next[3] = &matrix[x * M + y + 1];
	}
	else matrix[x * M + y].next[3] = NULL;
}

int main() {
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	int* shape = (int*)malloc(N * M * sizeof(int));

	struct node* matrix = (struct node*)malloc(N * M * sizeof(struct node));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			matrix[i * M + j].x = i;
			matrix[i * M + j].y = j;
			matrix[i * M + j].previous = NULL;
			matrix[i * M + j].visit = 0;

			scanf("%d", &shape[i * M + j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			find_next(matrix, i, j, shape, N, M);
		}
	}

	struct fifo_node* fifo_head = NULL;
	struct fifo_node* fifo_tail = NULL;
	push_item(&fifo_head, &fifo_tail, &matrix[0]);

	while (fifo_head != NULL) {
		struct fifo_node* this_node = pop_item(&fifo_head, &fifo_tail);
		this_node->this_node->visit = 1;
		for (int i = 0; i < 4; i++) {
			if (this_node->this_node->next[i] != NULL) {
				if (this_node->this_node->next[i]->visit == 0) push_item(&fifo_head, &fifo_tail, this_node->this_node->next[i]);
				if (this_node->this_node->next[i]->previous == NULL) this_node->this_node->next[i]->previous = this_node->this_node;
			}
		}
		free(this_node);
	}

	fifo_head = NULL;
	struct node* p_node = &matrix[(N - 1) * M + M - 1];
	while (1) {
		push_stack_item(&fifo_head, p_node);
		p_node = p_node->previous;
		if (p_node == matrix) break;
	}
	printf("(0,0)\n");
	struct fifo_node* s_node;
	while (fifo_head != NULL) {
		s_node = pop_stack_item(&fifo_head);
		printf("(%d,%d)\n", s_node->this_node->x, s_node->this_node->y);
	}

	free(shape);
	free(matrix);

	return 0;
}
