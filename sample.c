#include <stdio.h>
#include "sort.c"

int comparador(const void* a, const void* b)
{
    return *(int*) a - *(int*) b;
}


int main(void)
{
    int arr[] = {2,6,14,25,13,25,46,85,42,92,99,45,32,01,25,65,23,41};
    int arr_size = sizeof(arr)/sizeof(int);
    long a = bsort(arr,arr_size ,sizeof(int), comparador);

    printf("%d\n", a);

    for(int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
}