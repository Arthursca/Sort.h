# :books: Sort.h
lib in c that contains as many generalist sort functions as I can

## Note:
As quicksort already exists in c for arrays I didn't make it

## Version 1.0

in this version I focused on just adding the most basic sorts to arrays,they are 
Insertion Sort, Bubble Sort, Heap Sort and Merge Sort

### how it works?

to use each of these functions we have to pass at least 4 parameters.

#### - *Insertion Sort, Bubble Sort and Heap Sort:*

1. Here we need 4 parameters, the array you want to sort, the array size, the size of the array type and a int function that have 2 const void parameters, 
(this function will give you how your array will be ordered).

2. Sample:
```
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
```
#### - *Merge Sort*

1. Here we need 5 parameters, the array, the size of the array type, a int function that have 2 const void parameters, 
(this function will give you how your array will be ordered), 0 and  the array size - 1 (also works with the array size but it takes more steps to complete)

2. Sample:
```
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
    long steps = msort(arr ,sizeof(int), compar,0,arr_size - 1);

    //print the number of steps
    printf("%d\n", steps);

    //print sorted array
    for(int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
}
```


## :pencil: TO DO:

### Version 1.0

- [x] implements basic sorts for array
- [ ] implements basic sorts for lists
- [ ] implements basic sorts for trees
- [ ] implements basic sorts for files
- [ ] implements more sorts
