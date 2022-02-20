#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <stddef.h>

/**
 * Calls FUNCTION on N elements of the array SOURCE. Returns an array
 * (statically-allocated) with the result.
 */
#define mapn(function, source, n) ({ \
	typeof(source) destination; \
	for (size_t i = 0; i < (n); i += 1) { \
		destination[i] = (function)((source)[i]); \
	} \
	destination; \
})

/**
 * Calls FUNCTION on each element of the array SOURCE. Returns an array
 * (statically-allocated) with the result. The array SOURCE must have been
 * statically-allocated.
 */
#define map(function, source) (mapn((function), (source), sizeof(source) / sizeof(source[0])))

/**
 * Reduces N elements of the array SOURCE by calling FUNCTION. The function
 * FUNCTION must take two elements. Returns an array (statically-allocated) with
 * the result.
 */
#define reducen(function, source, n) ({ \
	__auto_type result = (source)[0]; \
	for (size_t i = 1; i < n; i += 1) { \
		result = (function)(result, (source)[i]); \
	} \
	result; \
})

/**
 * Reduces each element of the array SOURCE by calling FUNCTION. The function
 * FUNCTION must take two elements. Returns an array (statically-allocated) with
 * the result. The array SOURCE must have been statically-allocated.
 */
#define reduce(function, source) (reducen((function), (source), sizeof(source) / sizeof(source[0])))

#endif
