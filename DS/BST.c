#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1
#define TRUE 1
#define FALSE 0

#define BST_EMPTY 2
#define BST_DATA_NOT_FOUND 3
#define BST_NO_INORDER_SUCCESSOR 4
#define BST_NO_INORDER_PREDECESSOR 5

struct bst_node
{
    int key;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

struct bst
{
    struct bst_node* p_root_node;
    unsigned long long int nr_elements;
};

struct bst* bst_create(void);
int bst_insert(struct bst* p_bst, int new_key);

void preorder(struct bst* p_bst);
void inorder(struct bst* p_bst);
void postorder(struct bst* p_bst);
int bst_search(struct bst* p_bst, int search_key);
void bst_destroy(struct bst* p_bst);

void preorder_nodelevel(struct bst_node* p_root);
void inorder_nodelevel(struct bst_node* p_root);
void postorder_nodelevel(struct bst_node* p_root);
void bst_destroy_nodelevel(struct bst_node* p_root);
struct bst_node* bst_search_nodelevel(struct bst_node* p_root, int search_key);
struct bst_node* get_bst_node(int key);

/* Client that uses bst */
int main(void)
{
    struct bst* p_bst = NULL;
    int keys[] = {100, 50, 150, 25, 75, 200, 20, 70, 80, 175, 250, 24};
    int ne_keys[] = {-345, 4573, 346, -6535, 4746, 735, -634};
    int i, status;

    p_bst = bst_create();
    for(i = 0; i < sizeof(keys)/sizeof(int); ++i)
        assert(bst_insert(p_bst, keys[i]) == SUCCESS);

    preorder(p_bst);
    inorder(p_bst);
    postorder(p_bst);

    puts("Test case for present keys");
    for(i = 0; i < sizeof(keys)/sizeof(int); ++i)
    {
        status = bst_search(p_bst, keys[i]);
        if(status == TRUE)
            printf("%d is present in given BST\n", keys[i]);
        else
        {
            puts("Something went wrong");
            bst_destroy(p_bst);
            p_bst = NULL;
            exit(EXIT_FAILURE);
        }
    }

    puts("Test case for absent keys");
    for(i = 0; i < sizeof(ne_keys)/sizeof(int); ++i)
    {
        status = bst_search(p_bst, ne_keys[i]);
        if(status == FALSE)
            printf("%d is not present in given BST\n", ne_keys[i]);
        else
        {
            puts("Something went wrong");
            bst_destroy(p_bst);
            p_bst = NULL;
            exit(EXIT_FAILURE);
        }
    }

    bst_destroy(p_bst);
    p_bst = NULL;
    puts("Tree destroyed successfully");

    return(EXIT_SUCCESS);
}

/* Implementation of server routines */

struct bst* bst_create(void)
{
    struct bst* p_bst = NULL;

    p_bst = (struct bst*)malloc(sizeof(struct bst));
    if(NULL == p_bst)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    p_bst->p_root_node = NULL;
    p_bst->nr_elements = 0;

    return (p_bst);
}

int bst_insert(struct bst* p_bst, int new_key)
{
    struct bst_node* p_new_node = NULL;
    struct bst_node* p_run = NULL;

    p_new_node = get_bst_node(new_key);
    p_run = p_bst->p_root_node;
    if(p_run == NULL)
    {
        p_bst->p_root_node = p_new_node;
        p_bst->nr_elements += 1;
        return (SUCCESS);
    }

    while(1)
    {
        if(new_key <= p_run->key)
        {
            if(p_run->left == NULL)
            {
                p_run->left = p_new_node;
                p_new_node->parent = p_run;
                break;
            }
            else 
                p_run = p_run->left;
        }
        else 
        {
            if(p_run->right == NULL)
            {
                p_run->right = p_new_node;
                p_new_node->parent = p_run;
                break;
            }
            else 
                p_run = p_run->right;
        }
    }

    p_bst->nr_elements += 1;
    return (SUCCESS);
}

void bst_destroy(struct bst* p_bst)
{
    bst_destroy_nodelevel(p_bst->p_root_node);
}

void preorder(struct bst* p_bst)
{
    puts("PREORDER: ");
    printf("[START]<->");
    preorder_nodelevel(p_bst->p_root_node);
    printf("[END]\n");
}

void inorder(struct bst* p_bst)
{
    puts("INORDER: ");
    printf("[START]<->");
    inorder_nodelevel(p_bst->p_root_node);
    printf("[END]\n");
}

void postorder(struct bst* p_bst)
{
    puts("POSTORDER: ");
    printf("[START]<->");
    postorder_nodelevel(p_bst->p_root_node);
    printf("[END]\n");
}

int bst_search(struct bst* p_bst, int search_key)
{
    return (
            bst_search_nodelevel(p_bst->p_root_node,
                                search_key) != NULL
            );
}

void preorder_nodelevel(struct bst_node* p_root)
{
    if(p_root != NULL)
    {
        printf("[%d]<->", p_root->key);
        preorder_nodelevel(p_root->left);
        preorder_nodelevel(p_root->right);
    }
}

void inorder_nodelevel(struct bst_node* p_root)
{
    if(p_root != NULL)
    {
        inorder_nodelevel(p_root->left);
        printf("[%d]<->", p_root->key);
        inorder_nodelevel(p_root->right);
    }
}

void postorder_nodelevel(struct bst_node* p_root)
{
    if(p_root != NULL)
    {
        postorder_nodelevel(p_root->left);
        postorder_nodelevel(p_root->right);
        printf("[%d]<->", p_root->key);
    }
}

void bst_destroy_nodelevel(struct bst_node* p_root)
{
    if(p_root != NULL)
    {
        bst_destroy_nodelevel(p_root->left);
        bst_destroy_nodelevel(p_root->right);
        free(p_root);
    }
}

struct bst_node* bst_search_nodelevel(struct bst_node* p_root, 
                                        int search_key)
{
    struct bst_node* p_run = NULL;

    p_run = p_root;
    while(p_run != NULL)
    {
        if(p_run->key == search_key)
            break;
        else if(search_key <= p_run->key)
            p_run = p_run->left;
        else
            p_run = p_run->right;
    }

    return (p_run);
}

struct bst_node* get_bst_node(int key)
{
    struct bst_node* p_new_bst_node = NULL;

    p_new_bst_node = (struct bst_node*)malloc(sizeof(struct bst_node));
    if(p_new_bst_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    p_new_bst_node->key = key;
    p_new_bst_node->left = NULL;
    p_new_bst_node->right = NULL;
    p_new_bst_node->parent = NULL;

    return (p_new_bst_node);
}
