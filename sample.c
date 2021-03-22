#include <stdio.h>
#include "sort.c"


//Create the comparator
int comparador(const void* a, const void* b)
{
    return *(int*) a - *(int*) b;
}


int main(void)
{
    //Create the array
    int arr[] = {2,6,14,25,13,25,46,85,42,92,99,45,32,01,25,65,23,41};
    
    //get the num of objects
    int arr_size = sizeof(arr)/sizeof(int);

    //sort the array and take the number of steps that was necessary for that 
    long steps = bsort(arr,arr_size ,sizeof(int), comparador);
    printf("%d\n", steps);

    for(int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
}