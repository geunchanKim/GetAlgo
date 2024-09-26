#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct{
    int data;
}element;

typedef struct{
    element heap[1500 * 1500 + 1];
    int size;
}HEAP;

HEAP h;

void push(int data)
{
    int i = ++(h.size);

    while((i != 1) && (data > h.heap[i/2].data))
    {
        h.heap[i].data = h.heap[i/2].data;
        i /= 2;
    }

    h.heap[i].data = data;
}

int pop()
{
    int root, temp;
    root = h.heap[1].data;
    temp = h.heap[(h.size)--].data;

    int parent = 1, child = 2;
    while(child <= h.size)
    {
        if((child < h.size) && (h.heap[child].data < h.heap[child + 1].data)){
            child++;
        }

        if(temp >= h.heap[child].data) break;

        h.heap[parent].data = h.heap[child].data;
        parent = child;
        child *= 2;
    }
    
    h.heap[parent].data = temp;

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);

    h.size = 0;

    for(int i = 0; i < n*n; i++)
    {
        int num;
        scanf("%d", &num);
        push(num);
    }

    for(int i = 0; i < n - 1; i++)
    {
        pop();
    }

    printf("%d", pop());
}