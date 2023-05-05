#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1

#define TRUE    1
#define FALSE   0

#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

struct node
{
    int data;           /* data element */
    struct node* prev;  /* backwrd link */
    struct node* next;  /* forward link */
};

/* Interface routines declarations */
struct node* create_list(void);

int insert_at_start(struct node* p_list, int new_node);
int insert_at_end(struct node* p_list, int new_node);
int insert_after_data(struct node* p_list, int ext_data, int new_data);
int insert_before_data(struct node* p_list, int ext_data, int new_data);

int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);

int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

int get_length(struct node* p_list);
int is_list_empty(struct node* p_list);
int find_data(struct node* p_list, int f_data);

void show_list(struct node* p_list, const char* msg);
int destroy_list(struct node* p_list);

int concat_lists(struct node* p_list_1, struct node* p_list_2, 
                    struct node** pp_concat_list);

int append_list(struct node* p_list_1, struct node* p_list_2);
int merge_list(struct node* p_list_1, struct node* p_list_2,
                    struct node** p_merged_list);

int to_array(struct node* p_list_1, int** pp_arr, int* p_size);
int to_list(int* p_arr, int N, struct node** pp_list);

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list);
int reverse_list(struct node* p_list);


/* Helper routines declaration */
struct node* get_new_node(int new_data);
struct node* search_node(struct node* p_list, int search_data);

int main(void)
{
    struct node* p_list = NULL;
    struct node* p_list_1 = NULL;
    struct node* p_list_2 = NULL;
    struct node* p_cat_list = NULL;
    struct node* p_merged_list = NULL;
    struct node* p_reversed_list = NULL;
    struct node* p_lst_from_arr = NULL;

    int* p_arr = NULL;
    int N;

    int status;
    int data;
    int i;

    int data_1[] = {10, 20, 30, 40};
    int data_2[] = {10, 12, 16, 25, 28, 32, 35, 37};


    p_list = create_list();
    show_list(p_list, "Showing list after creation: ");

    for(data = 10; data <= 60; data = data + 10)
    {
        status = insert_at_end(p_list, data);
        assert(status == SUCCESS);
    }
    show_list(p_list,"Showing after insertion_at_end(): ");

    for(data = 100; data <= 600; data = data + 100)
    {
        status = insert_at_start(p_list, data);
        assert(status == SUCCESS);
    }
    show_list(p_list, "Showing after insert_at_start(): ");

    status = insert_after_data(p_list, 10, 0);
    assert(status == SUCCESS);
    show_list(p_list, "After inserting 0 after 10: ");

    status = insert_before_data(p_list, 10, -1);
    assert(status == SUCCESS);
    show_list(p_list, "After inserting -1 before 10: ");

    status = insert_before_data(p_list, 600, -600);
    assert(status == SUCCESS);
    show_list(p_list, "After inserting -600 before 600: ");

    status = insert_after_data(p_list, 60, -60);
    assert(status == SUCCESS);
    show_list(p_list, "After inserting -60 after 60: ");

    status = insert_after_data(p_list, -500, 10);
    assert(status == LIST_DATA_NOT_FOUND);
    puts("-500 is not present in the list ");

    status = insert_before_data(p_list, -500, 10);
    assert(status == LIST_DATA_NOT_FOUND);
    puts("-500 is not present in the list");

    status = get_start(p_list, &data);
    assert(status == SUCCESS);
    printf("start data = %d\n", data);
    show_list(p_list, "After get_start(): ");

    status = get_end(p_list, &data);
    assert(status == SUCCESS);
    printf("end data = %d\n", data);
    show_list(p_list, "After get_end(): ");

    status = pop_start(p_list, &data);
    assert(status == SUCCESS);
    printf("start data = %d\n", data);
    show_list(p_list, "After get_end(): ");

    status = pop_end(p_list, &data);
    assert(status == SUCCESS);
    printf("end data = %d\n", data);
    show_list(p_list, "After pop_end(): ");

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "After remove_start(): ");

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "After remove_end(): ");

    status = remove_data(p_list, 0);
    assert(status == SUCCESS);
    show_list(p_list, "After remove data(): ");

    if(is_list_empty(p_list) == FALSE)
        puts("List is not empty at the moment");
    
    if(find_data(p_list, 200) == TRUE)
        puts("200 is present in list at the moment");

    if(find_data(p_list, -5214) == FALSE)
        puts("-5214 is not present in the list at the moment");
    
    status = destroy_list(p_list);
    p_list = NULL;
    assert(status == SUCCESS);

    p_list_1 = create_list();
    p_list_2 = create_list();

    for(i = 0; i < sizeof(data_1)/sizeof(int); ++i)
        assert(insert_at_end(p_list_1, data_1[i]));

    for(i = 0; i < sizeof(data_2)/sizeof(int); ++i)
        assert(insert_at_end(p_list_2, data_2[i]));

    status = concat_lists(p_list_1, p_list_2, &p_cat_list);
    assert(status == SUCCESS);
    show_list(p_cat_list, "Showing concatenated list: ");
    status = destroy_list(p_cat_list);
    assert(status == SUCCESS);
    p_cat_list = NULL;

    status = merge_lists(p_list_1, p_list_2, &p_merged_list);
    assert(status == SUCCESS);
    show_list(p_merged_list, "Showing merged list: ");
    status = destroy_list(p_merged_list);
    assert(status == SUCCESS);
    p_merged_list = NULL;

    status = get_reversed_list(p_list_2, &p_reversed_list);
    show_list(p_reversed_list, "Showing reversed list: ");
    status = destroy_list(p_reversed_list);
    assert(status == SUCCESS);
    p_reversed_list = NULL;

    status = to_array(p_list_1, &p_arr, &N);
    assert(status == SUCCESS);
    puts("Showing array: ");
    printf("[START]");
    for(i = 0; i < N; ++i)
        printf("[%d]", p_arr[i]);
    printf("[END]\n");
    free(p_arr);
    p_arr = NULL;

    status = to_list(data_2, sizeof(data_2)/sizeof(int), &p_lst_from_arr);
    assert(status == SUCCESS);
    show_list(p_lst_from_arr, "Showing list from array: ");
    status = destroy_list(p_lst_from_arr);
    assert(status == SUCCESS);
    p_lst_from_arr = NULL;

    // extreme_testing();
    puts("SUCCESS");
    return (EXIT_SUCCESS);
}

/* Interface routines declarations */
struct node* create_list(void)
{
    return get_new_node(-1);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_list->next;
    p_new_node->prev = p_list;

    if(p_list->next != NULL)
        p_list->next->prev = p_new_node;
    
    p_list->next = p_new_node;

    return(SUCCESS);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_run = NULL;
    struct node* p_new_node = NULL;

    p_run = p_list;
    while(p_run->next != NULL)
        p_run = p_run->next;
    
    p_new_node = get_new_node(new_data);

    p_new_node->next = p_run->next;
    p_new_node->prev = p_run;
    if(p_run->next != NULL)
        p_run->next->prev = p_new_node;
    p_run->next = p_new_node;

    return (SUCCESS);
}

int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_ext_node = NULL;
    struct node* p_new_node = NULL;

    p_ext_node = search_node(p_list, ext_data);
    if(p_ext_node == NULL)
        return(LIST_DATA_NOT_FOUND);

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_ext_node->next;
    p_new_node->prev = p_ext_node;
    if(p_ext_node->next != NULL)
        p_ext_node->next->prev = p_new_node;
    p_ext_node->next = p_new_node;

    return (SUCCESS);
}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_ext_node = NULL;
    struct node* p_new_node = NULL;

    p_ext_node = search_node(p_list, ext_data);
    if(p_ext_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_ext_node;
    p_new_node->prev = p_ext_node->prev;
    p_ext_node->prev->next = p_new_node;
    p_ext_node->prev = p_new_node;

    return (SUCCESS);
}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list->next == NULL && p_list->prev == NULL)
        return(LIST_EMPTY);
    
    *p_start_data = p_list->next->data;
    return(SUCCESS);
}

int get_end(struct node* p_list, int* p_end_node)
{
    struct node* p_run = NULL;

    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY);

    p_run = p_list;
    while(p_run->next != NULL)
        p_run = p_run->next;

    *p_end_node = p_run->data;
    return (SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* p_delete_node = NULL;

    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY);

    p_delete_node = p_list->next;
    *p_start_data = p_delete_node->data;
    p_delete_node->prev->next = p_delete_node->next;
    if(p_delete_node->next != NULL)
        p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;

    return (SUCCESS);
}

int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* p_delete_node = NULL;

    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY);

    p_delete_node = p_list;
    while(p_delete_node->next != NULL)
        p_delete_node = p_delete_node->next;

    *p_end_data = p_delete_node->data;
    p_delete_node->prev->next = NULL;
    free(p_delete_node);
    p_delete_node = NULL;

    return (SUCCESS);
}

int remove_start(struct node* p_list)
{
    struct node* p_delete_node = NULL;

    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY);

    p_delete_node = p_list->next;
    p_delete_node->prev->next = p_delete_node->next;
    if(p_delete_node->next != NULL)
        p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;

    return (SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* p_delete_node = NULL;

    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY);

    p_delete_node = p_list;
    while(p_delete_node->next != NULL)
        p_delete_node = p_delete_node->next;

    p_delete_node->prev->next = NULL;
    free(p_delete_node);
    p_delete_node = NULL;

    return (SUCCESS);
}

int remove_data(struct node* p_list, int r_data)
{
    struct node* p_delete_node = NULL;

    p_delete_node = search_node(p_list, r_data);
    if(p_delete_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    p_delete_node->prev->next = p_delete_node->next;
    if(p_delete_node->next != NULL)
        p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;

    return (SUCCESS);
}

int get_length(struct node* p_list)
{
    struct node* p_run = NULL;
    int len = 0;

    for(p_run = p_list->next; p_run != NULL; p_run = p_run->next)
        ++len;

    return (len);
}

int is_list_empty(struct node* p_list)
{
    return (p_list->prev == NULL && p_list->next == NULL);
}

int find_data(struct node* p_list, int f_data)
{
    return (search_node(p_list, f_data) != NULL);
}

void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run = NULL;

    if(msg)
        puts(msg);

    printf("[START]<->");
    for(p_run = p_list->next; p_run != NULL; p_run = p_run->next)
        printf("[%d]<->", p_run->data);
    printf("[END]\n");
}

int destroy_list(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_next = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_list);

    return (SUCCESS);
}

int concat_lists(struct node* p_list_1, struct node* p_list_2,
                    struct node** pp_concat_list)
{
    struct node* p_cat_list = NULL;
    struct node* p_run = NULL;

    p_cat_list = create_list();

    for(p_run = p_list_1->next; p_run != NULL; p_run = p_run->next)
        assert(insert_at_end(p_cat_list, p_run->data) == SUCCESS);

    for(p_run = p_list_2->next; p_run != NULL; p_run = p_run->next)
        assert(insert_at_end(p_cat_list, p_run->data) == SUCCESS);

    *pp_concat_list = p_cat_list;
    return (SUCCESS);
}

int append_list(struct node* p_list_1, struct node* p_list_2)
{
    struct node* p_run = NULL;
    struct node* p_last_node = NULL;

    p_run = p_list_1;
    while(p_run->next != NULL)
        p_run = p_run->next;

    p_last_node = p_run;
    p_last_node->next = p_list_2->next;
    if(p_list_2->next != NULL)
        p_list_2->next->prev = p_last_node;
    
    free(p_list_2);
    p_list_2 = NULL;

    return (SUCCESS);
}

int merge_lists(struct node* p_list_1, struct node* p_list_2,
                    struct node** pp_merged_list)
{
    struct node* p_merged_list = NULL;
    struct node* p_run_1 = NULL, *p_run_2 = NULL;
    int data;
    int status;

    p_merged_list = create_list();

    p_run_1 = p_list_1->next;
    p_run_2 = p_list_2->next;

    while(1)
    {
        if(p_run_1 == NULL)
        {
            while(p_run_2 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run_2->data);
                assert(status == SUCCESS);
                p_run_2 = p_run_2->next;
            }

            break;
        }

        if(p_run_2 == NULL)
        {
            while(p_run_1 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run_1->data);
                assert(status == SUCCESS);
                p_run_1 = p_run_1->next;
            }

            break;
        }

        if(p_run_1->data <= p_run_2->data)
        {
            data = p_run_1->data;
            p_run_1 = p_run_1->next;
        }
        else
        {
            data = p_run_2->data;
            p_run_2 = p_run_2->next;
        }

        status = insert_at_end(p_merged_list, data);
        assert(status == SUCCESS);
    }

    *pp_merged_list = p_merged_list;
    return (SUCCESS);
}

int to_array(struct node* p_list_1, int** pp_arr, int* p_size)
{
    int* p_arr = NULL;
    int N = 0;
    int i = 0;

    struct node* p_run = NULL;

    N = get_length(p_list_1);
    if(N == 0)
    {
        *pp_arr = p_arr;
        *p_size = N;
        return (SUCCESS);
    }

    p_arr = (int*)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    for(p_run = p_list_1->next; p_run != NULL; p_run = p_run->next)
        p_arr[i++] = p_run->data;
    
    *pp_arr = p_arr;
    *p_size = N;

    return (SUCCESS);
}

int to_list(int* p_arr, int N, struct node** pp_list)
{
    struct node* p_list = NULL;
    int i;

    p_list = create_list();
    for(i = 0; i < N; ++i)
        assert(insert_at_end(p_list, p_arr[i] == SUCCESS));
    
    *pp_list = p_list;
    return (SUCCESS);
}

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list)
{
    struct node* p_reversed_list = NULL;
    struct node* p_run = NULL;

    p_reversed_list = create_list();

    for(p_run = p_list->next; p_run != NULL; p_run = p_run->next)
        assert(insert_at_start(p_reversed_list, p_run->data) == SUCCESS);
    
    *pp_reversed_list = p_reversed_list;
    return (SUCCESS);
}

int reverse_list(struct node* p_list)
{
    return (SUCCESS);
}

/* Helper routines declarations */
struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    assert(p_new_node != NULL);
    p_new_node->data = new_data;
    p_new_node->prev = NULL;
    p_new_node->next = NULL;

    return(p_new_node);
}

struct node* search_node(struct node* p_list, int search_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(search_data == p_run->data)
            break;
        p_run = p_run->next;
    }

    return (p_run);
}


