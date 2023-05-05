#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int i;

    puts("Using argc: ");
    for(i = 0; i < argc; ++i)
        printf("argv[%d]: %s\n", i, argv[i]);

    puts("Using NULL ptr: ");
    for(i = 0; argv[i] != NULL; ++i)
        printf("argv[%d]: %s\n", i, argv[i]);
    
    return(0);
}