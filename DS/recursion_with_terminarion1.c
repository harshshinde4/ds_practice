#include <stdio.h>
#include <stdlib.h>

void test_func(int n);

int main (void)
{
    test_func(1);
    return(0);
}

void test_func(int n)
{
    if(n == 8)
        return;
    printf("n = %d\n", n);
    test_func(n+1);
    printf("returning from function with n = %d\n", n);
}

/*
    tf(1)->prn(1)
        <-
        tf(2)->prn(2)
            <-
            tf(3)->prn(3)
                <-
                tf(4)->prn(4)
                    <-
                    tf(5)->prn(5)
                        <-
                        tf(6)->prn(6)
                            <-
                            tf(7)->prn(7)
                                <-
                                tf(8)
                                <-
                            prn2(7)
                            <-
                        prn2(6)
                        <-
                    prn2(5)
                    <-
                prn2(4)
                <-
            prn2(3)
            <-
        prn2(2)
        <-
    prn2(1)
    <-
*/