#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode{
    int key;
    struct Treenode *left, *right;
}Treenode;

Treenode* search(Treenode *node, int key)
{
    if(node == NULL) return NULL;
    if(key == node->key) return node;
    else if(key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

Treenode* search_rep(Treenode *node, int key)
{
    while(node != NULL)
    {
        if(key == node->key) return node;
        else if(key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

Treenode* new_node(int item)
{
    Treenode *temp = (Treenode*)malloc(sizeof(Treenode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Treenode* insert_node(Treenode* node, int key)
{
    if(node == NULL) return new_node(key);
    if(node->key > key)
        node->left = insert_node(node->left, key);
    else
        node->right = insert_node(node->right, key);

    return node;
}

Treenode* min_right_value(Treenode *node)
{
    Treenode *current = node;

    while(current->left != NULL)
        current = current->left;
    return current;
}

Treenode* delete_node(Treenode *root, int key)
{
    if(root == NULL) return root;
    if(key < root->key)
        root->left = delete_node(root->left, key);
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    else
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
            
        Treenode *temp = min_right_value(root->right);
        root->key = temp->key;
        delete_node(root->right, root->key);
    }
    return root;
}

void inorder(Treenode *root)
{
    if(root)
    {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int main()
{
    Treenode *root = NULL;
    Treenode *tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    printf("\n\n");
    if(search(root, 30) != NULL)
        printf("이진 탐색 트리에서 30을 발견함 \n");
    else
        printf("이진 탐색 트리에서 30을 발견못함 \n");
    
    return 0;
}