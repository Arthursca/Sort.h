#include <stdio.h>
#ifndef INSERTION_SORT_
#define INSERTION_SORT_

long bsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

#endif