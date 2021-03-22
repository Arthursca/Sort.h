#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void copy(void * a, void * b, size_t len);
long merge(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right, int middle);
long msort(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right);


void copy(void * a, void * b, size_t len)
{
    unsigned char * p = a, * q = b, tmp;
    for (size_t i = 0; i != len; ++i)
    {
        p[i] = q[i];
    }
}

long msort(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right)
{
    
    long count = 0;
    

    if(left < right)
    {
        
        int middle =  left + (right - left)/2;
        count += msort(base, size, compar, left, middle);
        count += msort(base, size, compar, middle+1, right);
        count += merge(base, size, compar, left, right, middle);
        
    }
    return count;
}


long merge(void *base, size_t size, int (*compar)(const void *, const void*), int left, int right, int middle)
{

    long count = 0;
    
    int n1 = middle - left + 1;
    int n2 = right - middle;

    void *L = malloc(size*(n1));
    void *R = malloc(size*(n2));
     

    for (int i = 0; i < n1; i++)
    {
        copy((L + size*i), (base + size*(left + i)), size);
    }
    for (int j = 0; j < n2; j++)
    {
        copy((R + size*j),(base + size*(middle + 1 + j)), size);
    }

    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) {
        count++;
        if (compar((L + size*i),(R + size*j)) <= 0) {
            copy((base + size*(k)), (L + size*i), size);
            i++;
        }
        else {
            copy((base + size*(k)), (R + size*j), size);
            j++;
        }
        k++;
    }
 

    while (i < n1) {
        count++;
        copy((base + size*(k)), (L + size*i), size);
        i++;
        k++;
    }
 

    while (j < n2) {
        count++;
        copy((base + size*(k)), (R + size*j), size);
        j++;
        k++;
    }
    return count;
}
