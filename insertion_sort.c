#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long swap(void * a, void * b, size_t len);
long insertion_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

long swap(void * a, void * b, size_t len)
{
    unsigned char * p = a, * q = b, tmp;
    for (size_t i = 0; i != len; ++i)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

long insertion_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    long count = 0;
    for (int i = 1, j; i < nitems; i++) {
        for (int j = i-1; 0 <= j; j--)
		{
            count++;
            if(compar((base + size*i),(base + size*j)) < 0)
            {
                swap((base + size*(j + 1) ),(base + size*(j)), size);
                i--;
            }
            else
            {
                j = 0;
            }
        }
    }
    return count;
}
