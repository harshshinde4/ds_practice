#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void merge(int* a, int q, int r);
void partition(int* a, int p, int r);


void merge_sort(int*a, int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p+r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
    }
}

void quick_sort(int* a, int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

#define SIZE 100

int main(void)
{
    int a[SIZE] = {10, };
    merge_sort(a, 0, SIZE-1);
    quick_sort(a, 0, SIZE-1);
}