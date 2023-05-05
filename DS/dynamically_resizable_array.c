#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Dynamically resizable array is ccalled vector */

struct vector_of_int
{
    int* p_arr;
    long long int num_of_elements;
};

struct vector_of_int* create_vector_of_int(void);
int append_element_to_vector(struct vector_of_int* p_vector, int element);
void show_vector(struct vector_of_int* p_vector, const char* msg);
void destroy_vector(struct vector_of_int* p_vector);

int main(void)
{
    /* Test Client */
    struct vector_of_int* p_vec1 = NULL;
    struct vector_of_int* p_vec2 = NULL;
    int status;
    int element;
    int choice;

    p_vec1 = create_vector_of_int();
    p_vec2 = create_vector_of_int();

    status = append_element_to_vector(p_vec1, 5);
    assert(status == 1);

    status = append_element_to_vector(p_vec1, 10);
    assert(status == 1);

    status = append_element_to_vector(p_vec1, 15);
    assert(status == 1);

    status = append_element_to_vector(p_vec1, 20);
    assert(status == 1);

    while(1)
    {
        puts(" ");
        printf("Do you further want to enter an element? [1->Yes | Anything else->No]: ");
        scanf("%d", &choice);
        if(choice != 1)
            break;
        printf("Enter an element: ");
        scanf("%d", &element);
        status = append_element_to_vector(p_vec2, element);
        assert(status == 1);
    }

    show_vector(p_vec1, "Displaying vector 1: ");
    show_vector(p_vec2, "Displaying vector 2: ");

    destroy_vector(p_vec1);
    p_vec1 = NULL;

    destroy_vector(p_vec2);
    p_vec2 = NULL;
}

/* algorithm that will allow use of vector of integers */
struct vector_of_int* create_vector_of_int(void)
{   
    struct vector_of_int* p_vector = NULL;

    p_vector = (struct vector_of_int*)malloc(sizeof(struct vector_of_int));
    assert(p_vector != NULL);   

    p_vector->p_arr = NULL;
    p_vector->num_of_elements = 0;
    
    return(p_vector);
} 

int append_element_to_vector(struct vector_of_int* p_vector, int element)
{   
    p_vector->num_of_elements = p_vector->num_of_elements + 1;
    p_vector->p_arr = (int*)realloc(p_vector->p_arr, p_vector->num_of_elements * sizeof(int));
    assert(p_vector->p_arr != NULL);
    p_vector->p_arr[p_vector->num_of_elements - 1] = element;
    return(1);
}

void show_vector(struct vector_of_int* p_vector, const char* msg)
{   
    long long int i;
    puts(" ");
    if(msg)
        puts(msg);

    for(i = 0; i < p_vector->num_of_elements; ++i)
        printf("p_vector_of_int[%lld]:%d\n", i, p_vector->p_arr[i]);

}

void destroy_vector(struct vector_of_int* p_vector)
{   
    if(p_vector->p_arr != NULL)
        free(p_vector->p_arr);
    free(p_vector);
    p_vector = NULL;
}