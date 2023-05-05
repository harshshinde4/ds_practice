/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Symbolic constants */
#define SUCCESS             1
#define TRUE                1
#define FALSE               0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

/* Typedefs */
typedef int data_t;
typedef int status_t;
typedef int len_t;

typedef struct node node_t;
typedef node_t list_t;

/* Node layouts */
struct node
{
    data_t data;
    struct node* prev;
    struct node* next;
};

/* Declarations of interface functions */
list_t* create_list(void);

status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data);

status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

status_t find_data(list_t* p_list, data_t f_data);
status_t is_list_empty(list_t* p_list);
status_t get_length(list_t* p_list);
void show_list(list_t* p_list, const char* msg);

status_t destroy_list(list_t** pp_list);

status_t concat_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_cat_list);
status_t append_list(list_t* p_list_1, list_t* p_list_2);
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_list);
status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list);
status_t reverse_list(list_t* p_list);

/* Declaration of auxilary functions */
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
void generic_delete(node_t* p_delete_node);
node_t* search_node(list_t* p_list, data_t s_data);
node_t* get_node(data_t new_data);

/* Declaration of auxilary routines */
void* xcalloc(size_t nr_elements, size_t size_per_element);

int main (void)
{
    return (EXIT_SUCCESS);
}

/* Declaration of interface functions */
list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = get_node(-1);
    p_list->next = p_list;
    p_list->prev = p_list;

    return(p_list);
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next);
    return (SUCCESS);
}  

status_t insert_end(list_t* p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_node(new_data), p_list);
    return (SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL;

    e_node = search_node(p_list, e_data);
    if(e_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    generic_insert(e_node, get_node(new_data), e_node->next);
    return (SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL;

    e_node = search_node(p_list, e_data);
    if(e_node == NULL)
        return (LIST_DATA_NOT_FOUND);
    
    generic_insert(e_node->prev, get_node(new_data), e_node);
    return (SUCCESS);
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);
    *p_start_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);
    
    *p_end_data = p_list->prev->data;
    return (SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);

    *p_start_data = p_list->next->data;
    generic_delete(p_list->next);
    return (SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);

    *p_end_data = p_list->prev->data;
    generic_delete(p_list->prev);
    return (SUCCESS);

}

status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);
    
    generic_delete(p_list->next);
    return (SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);
    
    generic_delete(p_list->prev);
    return (SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* p_remove_node = NULL;

    p_remove_node = search_node(p_list, r_data);
    if(p_remove_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    generic_delete(p_remove_node);
    return (SUCCESS);
}

status_t find_data(list_t* p_list, data_t f_data)
{
    return(search_node(p_list, f_data) != NULL);
}

status_t is_list_empty(list_t* p_list)
{
    return (p_list->next == p_list && p_list->prev == p_list);
}

status_t get_length(list_t* p_list)
{
    node_t* p_run = NULL;
    len_t length = 0;

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        ++length;
    
    return (length);
}

void show_list(list_t* p_list, const char* msg)
{
    node_t* p_run;

    if(msg)
        puts(msg);

    printf("[START]<->");
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        printf("[%d]<->", p_run->data);
    puts("[END]");
}

status_t destroy_list(list_t** pp_list)
{
    list_t* p_list = NULL;
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    p_list = *pp_list;
    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
    {
        p_run_next = p_run->next;
        free(p_run);
    }

    free(p_list);
    *pp_list = NULL;
    return (SUCCESS);
}

status_t concat_lists(list_t* p_lis_1, list_t* p_list_2, list_t** pp_cat_list)
{
    list_t* p_new_list = NULL;
    node_t* p_run;

    p_new_list = create_list();
    for(p_run = p_lis_1->next; p_run != p_lis_1; p_run = p_run->next)
        assert(insert_end(p_new_list, p_run->data) == SUCCESS);

    for(p_run = p_list_2; p_run != p_list_2; p_run = p_run->next)
        assert(insert_end(p_new_list, p_run->data) == SUCCESS);
    
    return (SUCCESS);
}

status_t append_list(list_t* p_list_1, list_t* p_list_2)
{
    if(is_list_empty(p_list_2) == TRUE)
    {
        free(p_list_2);
        p_list_2 = NULL;
    }

    p_list_1->prev->next = p_list_2->next;
    p_list_2->next->prev = p_list_1->prev;
    p_list_2->prev->next = p_list_1;
    p_list_1->prev = p_list_2->prev;

    free(p_list_2);
    p_list_2 = NULL;

    return (SUCCESS);
}

status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_list)
{
    list_t* p_merged_list = NULL;
    node_t* p_run_1 = NULL;
    node_t* p_run_2 = NULL;
    data_t data;

    p_merged_list = create_list();

    p_run_1 = p_list_1->next;
    p_run_2 = p_list_2->next;

    while(TRUE)
    {
        if(p_run_1 == p_list_1)
        {
            while(p_run_2 != p_list_2)
            {
                assert(insert_end(p_merged_list, p_run_2->data) == SUCCESS);
                p_run_2 = p_run_2->next;
            }
            break;
        }

        if(p_run_2 == p_list_2)
        {
            while(p_run_1 != p_list_1)
            {
                assert(insert_end(p_merged_list, p_run_1->data) == SUCCESS);
                p_run_1 = p_run_1->next;
            }
            break;
        }

        if(p_run_1->data <= p_run_2->data)
        {
            data = p_list_1->data;
            p_run_1 = p_run_1->next;
        }
        else
        {
            data = p_run_2->data;
            p_run_2 = p_run_2->next;
        }

        assert(insert_end(p_merged_list, data) == SUCCESS);
    }

    *pp_merged_list = p_merged_list;
    return (SUCCESS);
}

status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list)
{
    list_t* p_reversed_list = NULL;
    node_t* p_run = NULL;

    p_reversed_list = create_list();
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        assert(insert_start(p_reversed_list, p_run->data) == SUCCESS);
    *pp_reversed_list = p_reversed_list;

    return (SUCCESS);
}

status_t reverse_list(list_t* p_list)
{
    return (SUCCESS);
}

/* Declaration of list auxilary functions */
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;
}

node_t* search_node(list_t* p_list, data_t s_data)
{
    node_t* p_run = NULL;

    p_run = p_list->next;
    while(p_run != p_list)
    {
        if(p_run->data == s_data)
            return (p_run);
        p_run = p_run->next;
    }

    return (NULL);
}

node_t* get_node(data_t new_data)
{
    node_t* p_new_node = NULL;

    p_new_node = (node_t*)xcalloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    return (p_new_node);
}

/* Definition of auxilary routines */
void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = NULL;
    p = calloc(nr_elements, size_per_element);
    if(p == NULL)
    {
        printf("calloc:fatal:out of memory\n");
        exit(EXIT_FAILURE);
    }

    return (p);
}