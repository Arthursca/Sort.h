#include <stdio.h>
#include "..\utils\utils.c"


long isort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));



long isort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    long count = 0;

    for (int i = 1; i < nitems; i++) 
    {
        for (int j = i-1; 0 <= j; j--)
		{
            count++;
            if(compar((base + size*(j + 1)),(base + size*j)) < 0)
            {
                swap((base + size*(j + 1) ),(base + size*(j)), size);
            }
            else
            {
                j = 0;
            }
        }
    }
    return count;
}