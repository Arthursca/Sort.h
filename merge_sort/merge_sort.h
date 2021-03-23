#include <stdio.h>
#ifndef MERGE_SORT_
#define MERGE_SORT_

long merge(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right, int middle);
long msort(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right);

#endif