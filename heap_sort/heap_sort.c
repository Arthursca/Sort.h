#include <stdio.h>
#include "..\utils\utils.c"

long hsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
long heap(void *base, size_t size, int (*compar)(const void *, const void*),int n ,int i) ;



long hsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    long count = 0;


    for (int i = nitems / 2 - 1; i >= 0; i--)
    {
      count++;
      count += heap(base, size, compar,nitems,i);
    }

    for (int i = nitems - 1; i >= 0; i--)
    {
      count++;
      swap(base, base + i*size, size);
      count += heap(base, size, compar, i, 0);
    }

    
    return count;
}

long heap(void *base, size_t size, int (*compar)(const void *, const void*),int n ,int i) 
{
    long count = 0;
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && compar(base + left*size , base + largest*size)  > 0)
    {
      largest = left;
    }
  
    if (right < n && compar(base + right*size , base + largest*size) > 0)
    {
        largest = right;
    }
      
  
    if (largest != i) 
    {
      count++;
      swap(base + i*size, base + largest*size, size);
      count += heap(base,size,compar, n, largest);
    }
    return count;
}