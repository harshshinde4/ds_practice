#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

struct node
{
    int data;
    struct node* next;
};

int main(void)
{
    /* p_start is dedicated to store the address of the first node */

    int choice;
    int num;
    struct node* p_start_node = NULL;
    struct node* p_run = NULL;
    struct node* tmp_next = NULL;
    
    puts(" ");
    while(1)
    {
        printf("Do you further want to add a number? [Yes->1 | No->Otherwise]: ");
        scanf("%d", &choice);

        if(choice != 1)
            break;
        
        printf("Enter a number: ");
        scanf("%d", &num);

        if(p_start_node == NULL)
        {
            p_start_node = (struct node*)malloc(sizeof(struct node));
            assert(p_start_node != NULL);
            p_start_node->data = num;
            p_start_node->next = NULL;
            continue;
        }

        p_run = p_start_node;
        while(p_run->next != NULL)
        {
            p_run = p_run->next;
        }

        p_run->next = (struct node*)malloc(sizeof(struct node));
        assert(p_run->next != NULL);

        p_run->next->data = num;
        p_run->next->next = NULL;
    }
    puts(" ");
    p_run = p_start_node;
    while(p_run != NULL)
    {
        printf("Addressing(p_run) = %llu\tp_run->data = %d\n",
                (unsigned long long int)p_run, p_run->data);
        p_run = p_run->next;        
    }
    puts(" ");
    p_run = p_start_node;
    while(p_run != NULL)
    {
        tmp_next = p_run->next;
        printf("freeing node at address = %llu\n", 
                    (unsigned long long int)p_run);
        Sleep(1000);
        free(p_run);
        p_run = tmp_next;
    }
    p_start_node = NULL;

    return(0);
}
