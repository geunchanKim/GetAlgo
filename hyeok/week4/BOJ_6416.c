#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Node{
    char alph;
    struct Node *left;
    struct Node *right;
}Node;

Node *makenode(char alph)
{
    if(alph == '.') return NULL;
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> alph = alph;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

void addnode(Node *root, char parent, char l_child, char r_child)
{
    if(root == NULL) return;
    if(root -> alph == parent){
        root -> left = makenode(l_child);
        root -> right = makenode(r_child);
    }
    else{
        if(root -> left) addnode(root -> left, parent, l_child, r_child);
        if(root -> right) addnode(root -> right, parent, l_child, r_child);
    }
}

void preorder(Node *node)
{
    if(node == NULL) return;
    printf("%c", node -> alph);
    preorder(node -> left);
    preorder(node -> right);
}

void inorder(Node *node)
{
    if(node == NULL) return;
    inorder(node -> left);
    printf("%c", node -> alph);
    inorder(node -> right);
}

void postorder(Node *node)
{
    if(node == NULL) return;
    postorder(node -> left);
    postorder(node -> right);
    printf("%c", node -> alph);
}

int main()
{
    int n;
    scanf("%d", &n);

    Node *root = NULL;

    for(int i = 1; i < n; i++)
    {
        char parent, l_child, r_child;
        scanf(" %c %c %c", &parent, &l_child, &r_child);
        if(root == NULL){
            root = makenode(parent);
        }
        addnode(root, parent, l_child, r_child);
    }

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}