#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int que[10001];
int rear = 0;
int head = 0;

void push(int num)
{
    que[rear] = num;
    rear++;
}

void pop()
{
    if(head < rear){
        printf("%d\n", que[head]);
        que[head] = 0;
        head++;}
    else
        printf("-1\n");
}

void size()
{
    printf("%d\n", rear - head);
}

void empty()
{
    if(rear == head)
        printf("1\n");
    else
        printf("0\n");
}

void front()
{
    if(rear != head)
        printf("%d\n", que[head]);
    else   
        printf("-1\n");
}

void back()
{
    if(rear != head)
        printf("%d\n", que[rear - 1]);
    else
        printf("-1\n");
}

int main(void){
    
    int t;
    char order[10];
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%s", &order);
        if (strcmp(order, "push") == 0){
            int n;
            scanf("%d", &n);
            push(n);}
        else if (strcmp(order, "pop") == 0)
            pop();
        else if (strcmp(order, "size") == 0)
            size();
        else if (strcmp(order, "empty") == 0)
            empty();
        else if (strcmp(order, "front") == 0)
            front();
        else if (strcmp(order, "back") == 0)
            back();
    }
    return 0;
}