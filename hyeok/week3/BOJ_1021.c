#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Node{
    int data;
    struct Node * before;
    struct Node * next;
}Node;

typedef struct Deque{
    Node * front;
    Node * rear;
    int cnt;
}Deque;

void init(Deque * d)
{
    d -> front = d -> rear = NULL;
    d -> cnt = 0;
}

int Empty(Deque * d)
{return d -> cnt == 0;}

void Pushback(Deque *d, int value)
{
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode -> next = newnode -> before = NULL;
    newnode -> data = value;

    if(Empty(d)) d -> front = d -> rear = newnode;
    else
    {
        newnode -> before = d -> rear;
        d -> rear -> next = newnode;
        d -> rear = newnode;
    }
    d -> cnt++;
}

int Popfront(Deque * d)
{
    if(Empty(d)) return 0;
    Node * removed = d -> front;
    int tmp = removed -> data;
    d -> front = removed -> next;
    free(removed);
    d -> cnt--;
    return tmp;
}

int top(Deque * d)
{return d -> front -> data;}

int main()
{
    Deque d;
    init(&d);

    int n, m, ans = 0;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        Pushback(&d, i);

    for(int i = 0; i < m; i++)
    {
        int num, move = 0;
        scanf("%d", &num);
        while(1)
        {
            if(num == top(&d))
            {
                ans += (move <= d.cnt / 2) ? move : d.cnt - move;
                Popfront(&d);
                break;
            }
            Pushback(&d, Popfront(&d));
            move++;
        }
    }
    printf("%d", ans);
}