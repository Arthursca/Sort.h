#include <stdio.h>
#include "utils.h"

void swap(void * a, void * b, size_t len);
void copy(void * a, void * b, size_t len);

void swap(void * a, void * b, size_t len)
{
    unsigned char * p = a, * q = b, tmp;
    for (size_t i = 0; i != len; ++i)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

void copy(void * a, void * b, size_t len)
{
    unsigned char * p = a, * q = b, tmp;
    for (size_t i = 0; i != len; ++i)
    {
        p[i] = q[i];
    }
}