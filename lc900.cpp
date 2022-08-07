#include <stdio.h>
#include <stdlib.h>

typedef struct rle{
	struct rle* next;
	int repeat;
	int num;
} rle_node;

typedef struct rle_it {
	rle_node* fifo;
} RLEIterator;

rle_node* push(rle_node* fifo, int repeat, int num) {
	rle_node* fifo_old = fifo;
	rle_node* node = (rle_node*)malloc(sizeof(rle_node));
	node->repeat = repeat;
	node->num = num;
	node->next = NULL;

	if (fifo == NULL) {
		return node;
	}

	while (fifo->next != NULL) {
		fifo = fifo->next;
	}
	fifo->next = node;
	return fifo_old;
}

rle_node* pop(rle_node* fifo, int n, int* num, int* error) {
	if (fifo == NULL) {
		*error = 1;
		return fifo;
	}
	else if (fifo->repeat < n) {
		rle_node* next_ptr = pop(fifo->next, n - (fifo->repeat), num, error);;
		free(fifo);
		return next_ptr;
	}
	else if (fifo->repeat == n) {
		*num = fifo->num;
		rle_node* next_ptr = fifo->next;
		free(fifo);
		*error = 0;
		return next_ptr;
	}
	else {
		*num = fifo->num;
		fifo->repeat -= n;
		*error = 0;
		return fifo;
	}
}

RLEIterator* rLEIteratorCreate(int* encoding, int encodingSize) {
	RLEIterator* it = (RLEIterator*)malloc(sizeof(RLEIterator));
	it->fifo = NULL;

	for (int i = 0; i < encodingSize; i = i + 2) {
		int repeat = encoding[i];
		int num = encoding[i + 1];
		if (repeat > 0)
			it->fifo = push(it->fifo, repeat, num);
	}
	return it;
}

int rLEIteratorNext(RLEIterator* obj, int n) {
	int temp = 0;
	int error = 0;
	obj->fifo = pop(obj->fifo, n, &temp, &error);
	if (error == 1) return -1;
	else return temp;
}

void rLEIteratorFree(RLEIterator* obj) {
	int error = 0;
	int temp = 0;
	while (error == 0) {
		obj->fifo = pop(obj->fifo, 10, &temp, &error);
	}
	free(obj);
	return;
}

/**
 * Your RLEIterator struct will be instantiated and called as such:
 * RLEIterator* obj = rLEIteratorCreate(encoding, encodingSize);
 * int param_1 = rLEIteratorNext(obj, n);

 * rLEIteratorFree(obj);
*/

int main() {
	int encoding[] = { 3, 8, 0, 9, 2, 5 };
	int encodingSize = 6;
	int n = 2;

	RLEIterator* obj = rLEIteratorCreate(encoding, encodingSize);
	int param_1 = rLEIteratorNext(obj, n);

	rLEIteratorFree(obj);
	return 0;
}