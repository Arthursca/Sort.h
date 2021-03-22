#include <stdio.h>
#include "..\utils\utils.c"


long bsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

long bsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    long count = 0;
    int swapped = 0;

    for (int i = 1; i < nitems; i++) 
    {
        swapped = 0;
        for (int j = 0; j <= nitems - (i + 1); j++)
		{
            count++;
            if(compar((base + size*(j + 1)),(base + size*j)) < 0)
            {
                swap((base + size*(j + 1) ),(base + size*(j)), size);
                swapped++;
            }
        }
        if(swapped == 0)
        {
            break;
        }
    }
    return count;
}
