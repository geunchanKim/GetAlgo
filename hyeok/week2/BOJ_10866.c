#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Listnode {
    int data;
    struct Listnode* next;
    struct Listnode* prev;
} Listnode;

typedef struct list {
    Listnode* head;
    Listnode* tail;
    int size;
} list;

void initialize (list* list){
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0;
}

void push_front(list* list, int value)
{
    Listnode *p = (Listnode *)malloc(sizeof(Listnode));
    if (!p) return;
    p -> data = value;
    p -> prev = NULL;
    p -> next = list -> head;
    if(list -> size == 0){
        list -> tail = p;
    }
    else{
        list -> head -> prev = p;
    }
    list -> head = p;
    list -> size++;
}

void push_back(list* list, int value)
{
    Listnode *p = (Listnode *)malloc(sizeof(Listnode));
    if (!p) return;
    p -> data = value;
    p -> next = NULL;
    p -> prev = list -> tail;
    if(list -> size == 0){
        list -> head = p;
    }
    else{
        list -> tail -> next = p;
    }
    list -> tail = p;
    list -> size++;
}

void pop_front(list* list)
{
    if(list -> size == 0){
        printf("-1\n");
        return;
    }
    Listnode *removed;
    removed = list -> head;
    printf("%d\n", removed -> data);

    if(list -> size == 1){
        list -> head = NULL;
        list -> tail = NULL;
    }
    else{
        list -> head = list -> head -> next;
        list -> head -> prev = NULL;
    }
    free(removed);
    list -> size--;
}

void pop_back(list* list)
{   
    if(list -> size == 0){
        printf("-1\n");
        return;
    }
    Listnode *removed;
    removed = list -> tail;
    printf("%d\n", removed -> data);
    
    if(list -> size == 1){
        list -> head = NULL;
        list -> tail = NULL;
    }
    else{
        list -> tail = list -> tail -> prev;
        list -> tail -> next = NULL;
    }
    free(removed);
    list -> size--;
}

void size_list(list* list)
{
    printf("%d\n", list -> size);
}

void empty(list* list)
{
    if(list -> size == 0){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}

void front(list* list)
{
    if(list -> size == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n", list -> head -> data);
    }
}

void back(list* list)
{
    if(list -> size == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n", list -> tail -> data);
    }
}

int main(void)
{
    list l;
    initialize(&l);

    int t;
    char order[20];
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%s", order);
        if(strcmp(order, "push_front") == 0){
            int n;
            scanf("%d", &n);
            push_front(&l, n);
        }
        else if(strcmp(order, "push_back") == 0){
            int n;
            scanf("%d", &n);
            push_back(&l, n);
        }
        else if(strcmp(order, "pop_front") == 0){
            pop_front(&l);
        }
        else if(strcmp(order, "pop_back") == 0){
            pop_back(&l);
        }
        else if(strcmp(order, "size") == 0){
            size_list(&l);
        }
        else if(strcmp(order, "empty") == 0){
            empty(&l);
        }
        else if(strcmp(order, "front") == 0){
            front(&l);
        }
        else if(strcmp(order, "back") == 0){
            back(&l);
        }
    }
    return 0;
}