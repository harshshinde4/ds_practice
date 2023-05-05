#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node 
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* get_new_node(int data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return(new_node);
}

struct node* create_list(void)
{
    struct node* p_list = NULL;
    p_list = get_new_node(-1);
    return(p_list);
}

int insert_at_start(struct node* p_list, int data)
{
    struct node* new_node = NULL;
    new_node = get_new_node(data);
    new_node->next = p_list->next;
    new_node->prev = p_list;

    if(p_list->next != NULL)
        p_list->next->prev = new_node;
    
    p_list->next = new_node;

    return(1);
}

int insert_at_end(struct node* p_list, int data)
{
    struct node* new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list;
    new_node = get_new_node(data);
    while(p_run->next != NULL)
        p_run = p_run->next;
    
    new_node->next = p_run->next;
    new_node->prev = p_run->prev;
    if(p_run->next != NULL)
        p_run->next->prev = new_node;
    p_run->next = new_node;

    return(1);
}

int insert_at_end(struct node* p_list, int data)
{
    struct node* new_node = NULL;
    struct node* p_run = NULL;
    p_run = p_list;

    while(p_run->next != NULL)
        p_run = p_run->next;
    
    new_node = get_new_node(data);
    new_node->next = p_run->next;
    new_node->prev = p_run;
    if(p_run->next != NULL)
        p_run->next->prev = new_node;
    p_run->next = new_node;

    return(1);
}

int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* ext_data = NULL;
    struct node* new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == ext_data)
            break;
        p_run = p_run->next;
    }
    if(p_run == NULL)
        return(1);

    new_node = get_new_node(new_data);
    new_node->next = p_run->next;
    new_node->prev = p_run;
    if(p_run->next != NULL)
        p_run->next->prev = new_node;
    p_run->next = new_node;
    return(1);
    
}