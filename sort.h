
#ifndef SORT_H_
#define SORT_H_


//UTILS
void swap(void * a, void * b, size_t len);
void copy(void * a, void * b, size_t len);

//INSERTION SORT
long isort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

//HEAP SORT
long hsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
long heap(void *base, size_t size, int (*compar)(const void *, const void*),int n ,int i) ;

//BUBBLE SORT
long bsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

//MERGE SORT
long msort(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right);
long merge(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right, int middle);

#endif
