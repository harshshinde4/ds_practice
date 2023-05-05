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

int merge_list(struct node* p_list1, struct node* p_list2, struct node** p_merged)
{
    struct node* p_run1 = NULL;
    struct node* p_run2 = NULL;
    struct node* merged = NULL;
    int data;
    int status;

    merged = create_list();
    p_run1 = p_list1->next;
    p_run2 = p_list2->next;

    while(1)
    {
        if(p_run1 == NULL)
        {
            while(p_run2 != NULL)
            {
                status = insert_at_end(merged, p_run2->data);
                assert(status);
                p_run2 = p_run2->next;
            }
            break;
        }

        if(p_run2 == NULL)
        {
            while(p_run1 != NULL)
            {
                status = insert_at_end(merge, p_list1->data);
                assert(status);
                p_run1 = p_run1->next;
            }
            break;
        }

        if(p_run1->data <= p_run2->data)
        {
            data = p_run1->data;            
            p_run1 = p_run1->next;
        }

        else
        {
            data = p_run2->data;
            p_run2 = p_run2->next;
        }
        status = insert_at_end(merged, data);
        assert(status);
    }
    *p_merged = merged;
    return(0);
}

int merge_list(struct node* p_list1, struct node* p_list2, struct node* merged)
{
    struct node* run1 = NULL;
    struct node* run2 = NULL;
    struct node* p_merged = NULL;
    int data; 
    int status;

    p_merged = create_list();
    run1 = p_list1->next;
    run2 = p_list2->next;

    while(1)
    {
        if(run1 == NULL)
        {
            while(run2 != NULL)
            {
                status = insert_at_end(p_merged, run2->data);
                assert(status);
                run2 = run2->next;
            }
            break;
        }

        if(run2 == NULL)
        {
            while(run1 != NULL)
            {
                status = insert_at_end(p_merged,run2->data);
                assert(status);
                run1 = run1->next;
            }
            break;
        }

        if(run1 <= run2)
        {
            data = run1->data;
            run1 = run1->next;
        }

        else
        {
            data = run2->data;
            run2 = run2->next;
        }
        status = insert_at_end(p_merged, data);
        assert(status);
    }
    *merged = p_merged;
    return(0);
}


