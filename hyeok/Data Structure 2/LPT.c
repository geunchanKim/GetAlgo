#include <stdio.h>
#include <stdlib.h>
#define Max_Element 200

typedef struct 
{
    int id;
    int avail;
}element;

typedef struct
{
    element heap[Max_Element];
    int heap_size;
}HeapType;

HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void insert_min_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);

    while((i != 1) && (item.avail < h->heap[i / 2].avail))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    
    h->heap[i] = item;
}

element delete_min_heap(HeapType *h)
{
    int parent, child;
    element tmp, item;

    item = h->heap[1];
    tmp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while(child <= h->heap_size)
    {
        if((child < h->heap_size) && (h->heap[child].avail > h->heap[child + 1].avail))
            child++;
        if(tmp.avail < h->heap[child].avail)
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = tmp;
    return item;
}

#define Jobs 7
#define Machines 3

int main()
{
    int jobs[Jobs] = {8, 7, 6, 5, 3, 2, 1};
    element m = {0, 0};
    HeapType *heap = create();
    init(heap);

    for(int i = 0; i < Machines; i++)
    {
        m.id = i + 1;
        m.avail = 0;
        insert_min_heap(heap, m);
    }

    for(int i = 0; i < Jobs; i++)
    {
        m = delete_min_heap(heap);
        printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d�� �Ҵ��Ѵ�. \n", i, m.avail, m.avail + jobs[i] - 1, m.id);
        m.avail += jobs[i];
        insert_min_heap(heap, m);
    }
    
    return 0;
}