#define _CRT_RAND_S

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void input(int N, int** pp_arr);
void insert_at_sorting_position(int* p_arr, int N);
void sort(int* p_arr, int N);
void output(int* p_arr, int N, const char* p_msg);

int main(int argc, char* argv[])
{
    int* p_arr = NULL;
    int N;

    if(argc != 2)
    {
        printf("%s number of elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);
    if(N <= 0)
    {
        puts("Number of elements should be positive");
        return(EXIT_FAILURE);
    }

    input(N, &p_arr);
    output(p_arr, N, "Before sort(): ");
    sort(p_arr, N);
    output(p_arr, N, "After sort(): ");
    free(p_arr);
    p_arr = NULL;

    return(EXIT_SUCCESS);
}

void input(int N, int** pp_arr)
{
    int* p_arr = NULL;
    unsigned int num;
    int i;

    p_arr = (int*)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    for(i = 0; i < N; ++i)
    {
        rand_s(&num);
        p_arr[i] = num % 100;
    }

    *pp_arr = p_arr;
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

    p_arr[i+1] = key;
}

void sort(int* p_arr, int N)
{
    int size;

    for(size = 2; size <= N; ++size)
    {
        insert_at_sorting_position(p_arr, size);
    }
}

void output(int* p_arr, int N, const char* p_msg)
{
    int i;

    if(p_msg)
        puts(p_msg);

    for(i = 0; i < N; ++i)
        printf("a[%d]:%d\n", i, p_arr[i]);
}