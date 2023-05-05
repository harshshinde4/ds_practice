#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

void merge(int* a, int p, int q, int r);

int main (void)
{
    //  p = 3, q = 7, r = 15
    int a[] = {200, 100, 250, 10, 20, 30, 40, 50, 15, 25, 28, 29, 
                    41, 42, 45, 48, -1, -5, -2, -8};
    int p = 3, q = 7, r = 15;
    int i;

    printf("Showing a[%d...%d] before merging\n", p, r);
    for(i = p; i <= r; ++i)
        printf("a[%d]:%d\n", i, a[i]);
    merge(a, p, q, r);
    printf("Showing a[%d...%d] after merging\n", p, r);
    for(i = p; i <= r; ++i)
        printf("a[%d]:%d\n", i, a[i]);
    
    return (0);
}

void merge(int* a, int p, int q, int r)
{
    int n1; /* length of subarray 1*/
    int n2; /* length of subarray 2*/
    int* a1 = NULL; /* ptr to clone of subarray 1*/
    int* a2 = NULL; /* ptr to clone of subarray 2*/
    int i; /* counter variable */
    int k1; /* tracker of clone subarray 1 */
    int k2; /* tracker of clone subarray 2 */
    
    n1 = q - p + 1; /* [p,q] = length of [p..q] = q - p + 1*/
    n2 = r - q;     /* [q+1, r] = length of [q+1...r] = r - (q+1) + 1 = r-q-1+1 = r - q*/

    a1 = (int*)calloc(n1, sizeof(int));
    assert(a1 != NULL);

    a2 = (int*)calloc(n2, sizeof(int));
    assert(a2 != NULL);

    for(i = 0; i < n1; ++i)
        a1[i] = a[p+i];

    for(i = 0; i < n2; ++i)
        a2[i] = a[q+1+i];
    
    i = 0;
    k1 = 0;
    k2 = 0;

    while(TRUE)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+i] = a1[k1];
            k1++;
            i++;
            if(k1 == n1)
            {
                while(k2 < n2)
                {
                    a[p+i] = a2[k2];
                    k2++;
                    i++;
                }
                break;
            }
        }
        else 
        {
            a[p+i] = a2[k2];
            k2++;
            i++;
            if(k2 == n2)
            {
                while(k1 < n1)
                {
                    a[p+i] = a1[k1];
                    k1++;
                    i++;
                }
                break;
            }
        }
    }

    free(a1);
    a1 = NULL;

    free(a2);
    a2 = NULL;
}

/* 
    PC1 : 0 <= p <= q < r < N

    p <= q
    0 <= q - p
    0 < q - p +1 
    
    q < r
    0 < r - q
*/