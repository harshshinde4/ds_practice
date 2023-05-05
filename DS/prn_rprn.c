/*
    PRN -> print
    RPRN -> print in reverse
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int u64;

void prn(int* a, u64 N, u64 k);
void rprn(int* a, u64 k);

#define SIZE 8

int main(void)
{
    int a[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80};
    puts("Showing array in forward direction: ");
    prn(a, SIZE, 0);
    puts("Showing array in backward direction: ");
    rprn(a, SIZE);
    return(0);
}

void prn(int* a, u64 N, u64 k)
{
    if(k == N)
        return;
    printf("a[%llu]:%d\n", k, a[k]);
    prn(a, N, k+1);
}

void rprn(int* a, u64 k)
{
    if(k == 0)
        return;
    printf("a[%llu]:%d\n", k-1, a[k-1]);
    rprn(a, k-1);
}