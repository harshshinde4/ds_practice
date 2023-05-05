#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    int data;
    struct node* next;
};


#define DATA_NOT_FOUND  2


struct node* get_new_node(int new_data);
struct node* create_list(void);
int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int data);
int insert_before_data(struct node* p_list, int ext_data, int new_data);
int insert_after_data(struct node* p_list, int ext_data, int new_data);




int main(void)
{
    struct node* p_list = NULL;
    struct node* p_list1 = NULL;
    struct node* p_list2 = NULL;
    struct node* p_cat = NULL;
    struct node* p_merged = NULL;
    struct node* p_reversed = NULL;
    struct node* p_reverse = NULL;
    struct node* p_lst_from_arr = NULL;
    


    return(0);
}

struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;
    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
        exit(1);
    
    p_new_node->data = new_data;
    p_new_node->next= NULL;
    return (p_new_node);

}

struct node* create_list(void)
{
    struct node* p_list = NULL;
    p_list = get_new_node(-1);
    return(p_list);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;
    p_new_node = get_new_node(new_data);    
    p_new_node->next = p_list->next;
    p_list->next = p_new_node;
    return(1);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_last_node = NULL;

    p_last_node = p_list;
    while(p_last_node->next != NULL)
        p_last_node = p_last_node->next;
    
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_last_node->next;
    p_last_node->next = p_new_node;

    return(1);

}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;
    struct node* p_ext_node_prev = NULL;

    p_run = p_list->next;
    p_ext_node_prev = p_list;
    while(p_run != NULL)
    {
        if(p_run->data == ext_data)
            break;
        p_ext_node_prev = p_run;
        p_run = p_run->next;
    }

    if(p_run == NULL)
        printf("data not found\n");
    
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_ext_node_prev->next;
    p_ext_node_prev->next = p_new_node;

    return(0);
}

int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == ext_data)
            break;
        p_run = p_run->next;
    }

    if(p_run == NULL)
        return(DATA_NOT_FOUND);

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_run->next = p_new_node;
}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list->next == NULL)
        return(-1);
    *p_start_data = p_list->next->data
    return(0);
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* p_run = NULL;
    if(p_list->next == NULL)
        return(-1);
    p_run = p_list;
    while(p_list != NULL)
        p_run = p_run->next;
    
    *p_end_data = p_run->data;
    return(1);
}

int pop_start(struct node* p_list, int* start_data)
{
    struct node* start_node = NULL;
    if(p_list->next == NULL)
        return(0);

    start_node = p_list->next;
    *start_data = start_node->next;
    free(start_node);
    start_node = NULL;

    return(0);
    
}

int pop_end(node* p_list, int* p_end_data)
{
    struct node* end_node = NULL;
    struct node* end_node_prev = NULL;

    if(p_list->next == NULL)
        return(-1);
    end_node = p_list->next;
    end_node_prev = p_list;
    while(end_node->next != NULL)
    {
        end_node_prev = end_node;
        end_node = end_node->next;
    }
    *p_end_data = end_node->data;
    end_node_prev->next = end_node->next;
    free(end_node);
    end_node = NULL;

    return(1);
}

int remove_start(struct node* p_list)
{
    struct node* p_first_node = NULL;
    if(p_list->next == NULL)
        return(1);
    p_first_node = p_list->next; 
    p_list->next = p_first_node->next;
    free(p_first_node);
    p_first_node = NULL;

    return(0);
}

int remove_end(struct node* p_list)
{
    struct node* p_last_node = NULL;
    struct node* p_last_prev = NULL;

    if(p_list->next == NULL)
        return(1);
    p_last_node = p_list->next;
    p_last_prev = p_list;
    while(p_last_node->next != NULL)
    {
        p_last_prev = p_last_node;
        p_last_node = p_last_node->next;
    }

    p_last_prev->next= p_last_node->next;
    free(p_last_node);
    p_last_node = NULL;

    return(0);
}

int remove_data(struct node* p_list, int req_data)
{
    struct node* del_node = NULL;
    struct node* del_node_prev = NULL;

    if(p_list->next == NULL)
        return(1);
    
    del_node = p_list->next;
    del_node_prev = p_list;
    while(del_node->next != NULL)
    {
        if(del_node == req_data)
            break;
        del_node_prev = del_node;
        del_node = del_node->next;
    }

    del_node_prev->next = del_node->next;
    free(del_node);
    del_node = NULL;

    return(1);
}


int get_length(struct node* p_list)
{
    struct node* nc = NULL;
    int cnt = 0;

    if(p_list->next == NULL)
        return(1);
    nc = p_list->next;
    while(nc != NULL)
    {
        ++cnt;
        nc = nc->next;
    }
    return(cnt);

}

int is_list_empty(struct node* p_list)
{
    return(p_list->next != NULL);
}

void show_list(struct node* p_list)
{
    struct node* p_run = NULL;
    if(msg)
        puts(msg);
    
    printf("[START->]");
    p_run = p_list->next;
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]");
}

int destroy_list(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_nxt = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        p_run_nxt = p_run->next;
        free(p_run);
        p_run = p_run_nxt;
    }
    free(p_list);
    return(1);
}

int concat_list(struct node* p_list1, struct node* p_list2, struct node** pp_concat)
{
    struct node* p_run1 = NULL;
    struct node* p_cat_list = NULL;
    int status;

    p_cat_list = create_list();

    for(p_run1 = p_list1->next; p_run1 != NULL; p_run1 = p_run1->next)
    {
        status = insert_at_end(p_cat_list, p_run1->data);
        assert(status == 1);
    }

    for(p_run1 = p_list2->next; p_run1 != NULL; p_run1 = p_run1->next)
    {
        status = insert_at_end(p_cat_list, p_run1->data);
        assert(status == 1);
    }

    *pp_concat = p_cat_list;
    return(1);
}

int append_list(struct node* p_list1, struct node* p_list2)
{
    struct node* p_run = NULL;

    p_run = p_list1;
    while(p_run->next != NULL)
        p_run = p_run->next;
    
    p_run->next = p_list2->next;
    free(p_list2);
    p_list2 = NULL;

    return (0);

}

int merge_list(struct node* p_list1, struct node* p_list2, struct node** pp_merged)
{
    struct node* p_merged_list = NULL;
    struct node* p_run1 = NULL, *p_run2 = NULL;
    int data;
    int status;

    p_merged_list = create_list();
    p_run1 = p_list1->next;
    p_run2 = p_run2->next;

    while(1)
    {
        if(p_run2 == NULL)
        {
            while(p_run1 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run1->data);
                assert(status == 1);
                p_run1 = p_run1->next;
            }
            break;
        }

        if(p_run1 == NULL)
        {
            while(p_run2 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run2->data);
                assert(status);
                p_run2 = p_run2->next;
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
        status = insert_at_end(p_merged_list, data);
        assert(status);
    }

    *pp_merged = p_merged_list;
    return(0);
}

int to_array(struct node* p_list, int** pp_arr, int* p_size)
{
    int* p_arr = NULL;
    int N = 0;
    int i = 0;
    struct node* p_run = NULL;

    N = get_length(p_list);
    if(N ==0)
    {
        *pp_arr = p_arr;
        *p_size = N;
        return (0);
    }

    p_arr = (int*)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    for(p_run = p_list->next; p_run != NULL; p_run = p_run->next)
        p_arr[i++] = p_run->data;
    
    *pp_arr = p_arr;
    *p_size = N;

    return(0);

}


int to_list(int* p_arr, int N, struct node** pp_list)
{
    struct node* p_list = NULL;
    int i;

    p_list = create_list();
    for(i = 0; i < N; ++i)
        assert(insert_at_end(p_list, p_arr[i]));
    
    *pp_list = p_list;
    return(0);
}

int get_reversed_list(struct node* p_list, struct node** pp_reversed)
{
    struct node* p_reversed_list = NULL;
    struct node* p_run = NULL;

    p_reversed_list = create_list();
    for(p_run = p_list->next; p_run != NULL; p_run = p_run->next)
        assert(insert_at_start(p_reversed_list, p_run->data));
    
    *pp_reversed = p_reversed_list;
    return(1);
}

int reverse_list(struct node* p_list)
{
    struct node* prev = NULL;
    struct node* curr = NULL;
    struct node* next = NULL;

    curr = p_list;
    while(current != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    p_list = prev;

    return(1);
}

