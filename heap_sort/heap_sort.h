#include <stdio.h>
#ifndef HEAP_SORT_
#define HEAP_SORT_

long hsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
long heap(void *base, size_t size, int (*compar)(const void *, const void*),int n ,int i) ;
#endif