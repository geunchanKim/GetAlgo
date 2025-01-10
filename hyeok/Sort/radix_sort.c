#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max_Size 100

typedef int element;
typedef struct QueueType{
    int front, rear;
    element data[Max_Size];
}QueueType;

void init(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

int is_full(QueueType* q)
{
    return (q->front == (q->rear + 1) % Max_Size);
}

void enqueue(QueueType* q, element item)
{
    if(is_full(q)) return;
    q->rear = (q->rear + 1) % Max_Size;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
    if(is_empty(q)) return 0;
    q->front = (q->front + 1) % Max_Size;
    return q->data[q->front];
}

#define Buckets 10
#define Digits 4
void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queue[Buckets];

    for(b = 0; b < Buckets; b++)
        init(&queue[b]);
    for(d = 0; d < Digits; d++)
    {
        for(i = 0; i < n; i++)
            enqueue(&queue[(list[i] / factor) % 10], list[i]);
        for(b = i = 0; b < Buckets; b++)
            while(!is_empty(&queue[b]))
                list[i++] = dequeue(&queue[b]);
        factor *= 10;
    }
}

#define Size 10

int main()
{
    int list[Size];
    srand(time(NULL));
    for(int i = 0; i < Size; i++)
        list[i] = rand() % 100;
    radix_sort(list, Size);
    for(int i = 0; i < Size; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}