#include <stdio.h>
#include "sort.h"

//Create the compar
int compar(const void* a, const void* b)
{
    return *(int*) a - *(int*) b;
}


int main(void)
{
    //Create the array
    int arr[] = {2,6,14,25,13,25,46,85};
    
    //get the num of objects
    int arr_size = sizeof(arr)/sizeof(int);

    //sort the array and take the number of steps that was necessary for that
    long steps = isort(arr,arr_size ,sizeof(int), compar);

    //print the number of steps
    printf("%d\n", steps);

    //print sorted array
    for(int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
}