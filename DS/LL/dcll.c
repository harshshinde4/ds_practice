#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* create_list(void)
{
    struct node* p_list = NULL;

    p_list = get_node(-1);
    p_list->next = p_list;
    p_list->prev = p_list;

    return(p_list);
}

struct node* get_node(int data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;

    return(new_node);
}

void generic_insert(struct node* p_beg, struct node* p_mid, struct node* p_end)
{
    p_mid->next = p_beg->next;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

void generic_delete(struct node* delete_node)
{
    delete_node->next->prev = delete_node->prev;
    delete_node->prev->next = delete_node->next;
    free(delete_node);
}

struct node* search_node(struct node* p_list, int data)
{
    struct node* p_run = NULL;
    p_run = p_list;
    while(p_run->next != p_list)
    {
        if(p_run->data == data)
            return(p_run);
        p_run = p_run->next;
    }
    return(NULL);
}

int insert_start(struct node* p_list, int new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next);
    return(1);
}

int insert_end(struct node* p_list, int new_data)
{
    generic_insert(p_list->prev, get_node(new_data), p_list);
    return(1);
}

int insert_before(struct node* p_list, int e_data, int n_data)
{
    struct node* e_node = NULL;
    e_node = search_node(p_list, e_data);
    if(e_node == NULL)
        return(0);
    generic_insert(e_node->prev, get_node(n_data), e_node);
    return(1);
}

int insert_before(struct node* p_list, int e_data, int n_data)
{
    struct node* e_node = NULL;
    e_node = search_node(p_list, e_data);
    if(e_node == NULL)
        return(0);
    
    generic_insert(e_node->prev, get_node(n_data), e_node);
    return(1);
}

int insert_after(struct node* p_list, int e_data, int n_data)
{
    struct node* e_node = NULL;
    e_node = search_node(p_list, e_data);
    if(e_node == NULL)
        return(0);
    generic_insert(e_node, get_node(n_data), e_node->next);
    return;
}

int is_empty(struct node* p_list)
{
    return(p_list->next == p_list && p_list->prev == p_list);
}


int get_repeat_cnt(struct node* p_list, int search_data)
{
    int count = 0;
    struct node* p_run = NULL;
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
    {
        if(p_run->data == search_data)
            count++;
    }
    return(count);
}

struct node* reverse_list(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;
    struct node* p_prev_orig = NULL;

    p_prev_orig = p_list->prev;

    for(p_run = p_list->prev->prev; p_run != p_list; p_run = p_run_prev)
    {
        p_run_prev = p_run->prev;
        generic_insert(p_list->prev, p_run, p_list);
    }

    p_prev_orig->prev = p_list;
    p_list->next = p_prev_orig;
    return(1);
}

 