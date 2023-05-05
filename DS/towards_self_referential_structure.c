#include <stdio.h>
#include <stdlib.h>

struct X
{
    int n;
    int* p;
};

struct Y
{
    int n;
    struct Y* p;
};

void test(void);

int main(void)
{
    struct X inX1, inX2;
    struct X* pX;
    printf("&inX2 = %p, &inX2.n = %p\n", &inX2, &inX2.n);

    inX1.n = 100;
    inX2.n = 200;
    inX1.p = &inX2.n;
    inX2.p = NULL;

    pX = &inX1;
    printf("pX->n = %d\n", pX->n);  // inX1.n
    printf("pX->p = %p\n", pX->p);  // &inX2, &inX2.n

    //type(pX->p) -> int*;
    printf("pX->p = %d\n", *pX->p); //inX2.n
    //inX2.p is NOT ACCESSIBLE THROUGH pX

    test();

    return(0);
    
}

void test(void)
{
    struct Y inY1, inY2, inY3;

    inY1.n = 100;
    inY2.n = 200;
    inY3.n = 300;

    inY1.p = &inY2;
    inY2.p = &inY3;
    inY3.p = NULL;

    printf("&inY1 = %p, inY1.p = %p\n", &inY1, inY1.p);
    printf("&inY2 = %p, inY2.p = %p\n", &inY2, inY2.p);
    printf("&inY3 = %p, inY3.p = %p\n", &inY3, inY3.p);

    struct Y* pY = &inY1;

    printf("pY->n = %d\tpY->p = %p\n", pY->n, pY->p);   //inY1.n, inY1.p
    printf("pY->p->n = %d\tpY->p->p = %p\n", pY->p->n, pY->p->p);   // inY2.n, inY2.p
    printf("pY->p->p->n = %d\tpY->p->p->p", pY->p->p->n, pY->p->p->p);
    
}