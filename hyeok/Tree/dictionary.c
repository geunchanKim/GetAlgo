#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Word_Size 100
#define Max_Meaning_Size 100

typedef struct{
    char word[Max_Word_Size];
    char mean[Max_Meaning_Size];
}element;

typedef struct Treenode{
    element key;
    struct Treenode *left, *right;
}Treenode;

int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word);
}

void display(Treenode *p)
{
    if(p != NULL)
    {
        printf("(");
        display(p->left);
        printf("%s:%s", p->key.word, p->key.mean);
        display(p->right);
        printf(")");
    }
}

Treenode* search(Treenode *p, element key)
{
    while(p != NULL)
    {
        if(compare(p->key, key) == 0)
            return p;
        else if(compare(p->key, key) < 0)
            p = p->right;
        else
            p = p->left;
    }
    return p;
}

Treenode* new_node(element item)
{
    Treenode *p = (Treenode*)malloc(sizeof(Treenode));
    p->key = item;
    p->left = p->right = NULL;
    return p;
}

Treenode* insert_node(Treenode *root, element key)
{
    if(root == NULL) return new_node(key);
    if(compare(root->key, key) < 0)
        root->right = insert_node(root->right, key);
    else if(compare(root->key, key) > 0)
        root->left = insert_node(root->left, key);
    return root;
}

Treenode* min_value_node(Treenode* node)
{
    Treenode *cur = node;
    while(cur->left != NULL)
        cur = cur->left;
    return cur;
}

Treenode* delete_node(Treenode* root, element key)
{
    if(root == NULL) return root;
    if(compare(root->key, key) > 0)
        root->left = delete_node(root->left, key);
    else if(compare(root->key, key) < 0)
        root->right = delete_node(root->right, key);
    else if(compare(root->key, key) == 0)
    {
        if(root->left == NULL)
        {
            Treenode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Treenode *temp = root->left;
            free(root);
            return temp;
        }
        
        Treenode *temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void help()
{
    printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}

int main(void)
{
    char command;
    element e;
    Treenode *root = NULL;
    Treenode *tmp;

    do{
        help();
        command = getchar();
        getchar();
        switch(command)
        {
            case 'i':
                printf("단어: ");
                gets(e.word);
                printf("의미: ");
                gets(e.mean);
                root = insert_node(root, e);
                break;
            case 'd':
                printf("단어: ");
                gets(e.word);
                root = delete_node(root, e);
                break;
            case 's':
                printf("단어: ");
                gets(e.word);
                tmp = search(root, e);
                if(tmp != NULL)
                    printf("의미: %s\n", tmp->key.mean);
                break;
            case 'p':
                display(root);
                printf("\n");
                break;
        }
    }while(command != 'q');

    return 0;
}