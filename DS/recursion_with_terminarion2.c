#include <stdio.h>
#include <stdlib.h>

void test_func(int n);

int main(void)
{
    test_func(8);
    return(0);
}

void test_func(int n)
{
    if(n == 0)
        return;
    printf("n = %d\n", n);
    test_func(n-1);
    printf("returning from n = %d\n", n);
}