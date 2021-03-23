#include <stdio.h>

#ifndef BUBBLE_SORT_
#define BUBBLE_SORT_

long bsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

#endif