#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int stack[10001];
int count = 0;

void push(int num)
{
    stack[count] = num;
    count++;
}

void pop()
{
    if(count != 0)
    {
        count--;
        printf("%d\n", stack[count]);
        stack[count] = 0;
    }
    else printf("-1\n"); 
}

void top()
{
    if(count != 0)
        printf("%d\n", stack[count - 1]);
    else 
        printf("-1\n");
}

void size()
{
    printf("%d\n", count);
}

void empty()
{
    if(count != 0)
        printf("0\n");
    else
        printf("1\n");
}

int main(void)
{
    int t;
    char order[10];
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%s", &order);
        if (strcmp(order, "push") == 0){
            int n;
            scanf("%d", &n);
            push(n);
        }
        else if (strcmp(order, "pop") == 0)
            pop();
        else if (strcmp(order, "top") == 0)
            top();
        else if (strcmp(order, "size") == 0)
            size();
        else if (strcmp(order, "empty") == 0)
            empty();
    }
    return 0;
}