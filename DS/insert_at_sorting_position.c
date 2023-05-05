#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
    @p_arr : pointer containing base address of array 
    @N : Size of array
    
    precodition : lements from index 0 to index N-1 are sorted 
                    ( all but last element are  sorted )
                
    the elments at last index (i.e. element at index N-1) may not be 
    in sorted order.
    
    postcondition : Entire array (index 0 to N-1) should be sorted
*/

void insert_at_sorting_position(int* p_arr, int N);
void show(int* p_arr, int N, const char* msg);

int main(void)
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 5};
    show(arr, 10, "Before inset at sorting position(): ");
    insert_at_sorting_position(arr, 10);
    show(arr, 10, "After insert_at_sorting_position(): ");
    return(0);
}

void insert_at_sorting_position(int* p_arr, int N)
{
    int key;
    int i;

    key = p_arr[N-1];
    i = N-2;
    while(i > -1 && p_arr[i] > key)
    {
        p_arr[i+1] = p_arr[i];
        i = i - 1;
    }

    p_arr[i + 1] = key;
}

void show(int* p_arr, int N, const char* msg)
{
    int i;

    if(msg)
        puts(msg);
    
    for(i = 0; i < N; ++i)
        printf("p_arr[%d]:%d\n", i, p_arr[i]);
}
