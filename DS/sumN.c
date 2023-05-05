#include <stdio.h> 
#include <stdlib.h> 

unsigned long long int sumN(int* a, unsigned long long int N); 

#define SIZE 8 

int main(void) 
{
    int a[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80}; 
    unsigned long long int sum; 

    sum = sumN(a, SIZE); 
    printf("sum = %llu\n", sum); 

    exit(EXIT_SUCCESS); 
}

unsigned long long int sumN(int* a, unsigned long long int N)
{
    if(N == 0)
        return 0; 
    return a[N-1] + sumN(a, N-1); 
}

