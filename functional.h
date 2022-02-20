#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <stddef.h>

/**
 * Calls FUNCTION on N elements of the array SOURCE. Returns an array
 * (statically-allocated) with the result.
 */
#define map(function, source, n) ({ \
	__auto_type function_ = (function); \
	__auto_type source_ = (source); \
	__auto_type n_ = (n); \
	typeof(source) destination; \
	for (size_t i = 0; i < n_; i += 1) { \
		destination[i] = function_(source_[i]); \
	} \
	destination; \
})

/**
 * Reduces N elements of the array SOURCE by calling FUNCTION. The function
 * FUNCTION must take two elements. Returns an array (statically-allocated) with
 * the result.
 */
#define reduce(function, source, n) ({ \
	__auto_type function_ = (function); \
	__auto_type source_ = (source); \
	__auto_type n_ = (n); \
	__auto_type result = source_[0]; \
	for (size_t i = 1; i < n_; i += 1) { \
		result = function_(result, source_[i]); \
	} \
	result; \
})

#endif
