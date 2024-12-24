#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Treenode{
    int data;
    struct Treenode *left, *right;
    int is_thread;
}Treenode;

Treenode n1 = {'A', NULL, NULL, 1};
Treenode n2 = {'B', NULL, NULL, 1};
Treenode n3 = {'C', &n1, &n2, 0};
Treenode n4 = {'D', NULL, NULL, 1};
Treenode n5 = {'E', NULL, NULL, 0};
Treenode n6 = {'F', &n4, &n5, 0};
Treenode n7 = {'G', &n3, &n6, 0};
Treenode *exp = &n7;

Treenode* find_successor(Treenode *p)
{
    Treenode *q = p->right;
    if(q == NULL || p->is_thread == TRUE)
        return q;
    while(q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(Treenode *root)
{
    Treenode *q;

    q = root;
    while(q->left) q = q->left;
    do{
        printf("%c", q->data);
        q = find_successor(q);
    }while(q);
}

int main()
{
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;

    thread_inorder(exp);
    printf("\n");
    
    return 0;
}