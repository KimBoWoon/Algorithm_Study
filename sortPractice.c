#include <stdio.h>
#include <stdlib.h>

typedef struct position {
	int x;
	int y;
} Position;

int comp(const void* x, const void* y) {
	if ((*(Position*)x).x == (*(Position*)y).x) {
		return (*(Position*)x).y - (*(Position*)y).y;
	}
	return (*(Position*)x).x - (*(Position*)y).x;
}

int main() {
	Position arr[] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
	int size = sizeof(arr) / sizeof(Position);
	int i = 0;

	for (i = 0; i < size; i++)
		printf("%d %d ", arr[i].x, arr[i].y);
	printf("\n");

	qsort(arr, size, sizeof(Position), comp);

	for (i = 0; i < size; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
	printf("\n");
}
