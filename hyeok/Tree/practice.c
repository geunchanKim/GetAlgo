#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Treenode{
    int data;
    struct Treenode *left, *right;
}Treenode;

#define Max_Queue 100
typedef Treenode* element;
typedef struct{
    element data[Max_Queue];
    int front, rear;
}QueueType;

void init(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return (q->front == (q->rear + 1) % Max_Queue);
}

void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        return;
    q->rear = (q->rear + 1) % Max_Queue;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        return NULL;
    q->front = (q->front + 1) % Max_Queue;
    return q->data[q->front];
}

void level_order(Treenode *ptr)
{
    QueueType q;

    init(&q);

    if(ptr == NULL) return;
    enqueue(&q, ptr);
    while(!is_empty(&q))
    {
        ptr = dequeue(&q);
        printf("[%d] ", ptr->data);
        if(ptr->left)
            enqueue(&q, ptr->left);
        if(ptr->right)
            enqueue(&q, ptr->right);
    }
}

int calc_dir_size(Treenode *root)
{
    int left_size, right_size;
    if(root == NULL) return 0;

    left_size = calc_dir_size(root->left);
    right_size = calc_dir_size(root->right);
    return (root->data + left_size + right_size);
}

int get_node_count(Treenode *node)
{
    int count = 0;
    if(node != NULL)
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    return count;
}

int get_leaf_count(Treenode *node)
{
    int count = 0;
    if(node != NULL)
    {
        if(node->left == NULL && node->right == NULL)
            return 1;
        else
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
    }
    return count;
}

int get_height(Treenode *node)
{
    int height = 0;
    if(node != NULL)
        height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) :
                         get_height(node->right));
    return height;
}

int get_nonleaf_count(Treenode *node)
{
    int count = 0;
    if(node == NULL)
        return 0;
    if(node->left != NULL || node->right != NULL)
        return (count = 1 + get_nonleaf_count(node->left) + get_nonleaf_count(node->right));
}

int main()
{
    Treenode n4 = {500, NULL, NULL};
    Treenode n5 = {200, NULL, NULL};
    Treenode n3 = {100, &n4, &n5};
    Treenode n2 = {50, NULL, NULL};
    Treenode n1 = {0, &n2, &n3};

    printf("디렉토리의 크기=%d\n", calc_dir_size(&n1));
    printf("%d\n", get_node_count(&n1));
    printf("%d\n", get_leaf_count(&n1));
    printf("%d\n", get_height(&n1));
    printf("%d\n", get_nonleaf_count(&n1));
}