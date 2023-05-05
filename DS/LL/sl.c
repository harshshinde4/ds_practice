#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* get_new_node(int new_data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    assert(new_node);

    new_node->data = new_data;
    new_node->next = NULL;

    return(new_node);    
}

struct node* get_new_node(int data)
{
    struct node* new_node = NULL;
    new_node = (struct node*) malloc(sizeof(struct node));
    assert(new_node);

    new_node->data = data;
    new_node->next = NULL;

    return(new_node);
}

struct node* get_new_node(int data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    assert(new_node);

    new_node->data = data;
    new_node->next = NULL;

    return(new_node);
}

struct node* create_list(void)
{
    struct node* p_list = NULL;
    p_list = get_new_node(-1);
    return(p_list);
}

struct node* create_list(void)
{
    struct node* p_list = NULL;
    p_list = get_new_node();
    return(p_list);
}

struct node* create_list(void)
{
    struct node* p_list = NULL;
    p_list = get_new_node(-1);
    return(p_list);
}

int insert_at_end(struct node* p_list, int data)
{
    struct node* p_last = NULL;
    struct node* p_new_node = NULL;
    
    p_last = p_list;
    while(p_last->next != NULL)
        p_last = p_last->next;
    
    p_new_node = get_new_node(data);
    p_last->next = p_new_node;
    p_new_node->next NULL;
}

int insert_at_end(struct node* p_list, int data)
{
    struct node* p_last = NULL;
    struct node* new_node = NULL;

    p_last = p_list;
    while(p_last->next != NULL)
        p_last = p_last->next;
    
    new_node = get_new_node(data);
    p_last->next = new_node;
    new_node->next = NULL;

    return(1);
}

int insert_at_end(struct node* p_list, int data)
{
    struct node* new_node = NULL;
    struct node* last = NULL;

    last = p_list;
    while(last->next != NULL)
        last = last->next;

    new_node = get_new_node(data);
    last->next = new_node;
    new_node->next = NULL;
    return(1);
}

int insert_at_start(struct node* p_list, int data)
{
    struct node* new_node = NULL;
    new_node = get_new_node(data);
    new_node->next = p_list->next;
    p_list->next = new_node;

    return(1);
}

int insert_at_start(struct node* p_list, int data)
{
    struct node* new_node = get_new_node(data);
    new_node->next = p_list->next;
    p_list->next = new_node;
    return(1);
}


