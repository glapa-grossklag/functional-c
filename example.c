/**
 * This program prints the following:
 *
 *     numbers[0] = 2
 *     numbers[1] = 3
 *     numbers[2] = 4
 *     numbers[3] = 5
 *     numbers[4] = 6
 *     numbers[5] = 7
 *
 *     squared[0] = 4
 *     squared[1] = 9
 *     squared[2] = 16
 *     squared[3] = 25
 *     squared[4] = 36
 *     squared[5] = 49
 *
 *     sum of squares = 139
 */
#include <stdio.h>
#include <stdlib.h>

#include "functional.h"

int main(void) {
	// === setup ===
	int numbers[] = {2, 3, 4, 5, 6, 7};
	size_t size = sizeof(numbers) / sizeof(numbers[0]);

	for (size_t i = 0; i < size; i += 1) {
		printf("numbers[%zu] = %d\n", i, numbers[i]);
	}
	printf("\n");

	// === map ===
	int square(int x) { return x * x; }
	int *squared = map(square, numbers, size);
	for (size_t i = 0; i < size; i += 1) {
		printf("squared[%zu] = %d\n", i, squared[i]);
	}
	printf("\n");

	// === reduce ===
	int add(int a, int b) { return a + b; }
	int sum = reduce(add, squared, size);
	printf("sum of squares = %d\n", sum);

	return EXIT_SUCCESS;
}
