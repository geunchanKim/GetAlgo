#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define Max 100001

typedef struct{
    int key;
}element;

typedef struct{
    element heap[Max];
    int heap_size;
}heaptype;

heaptype h;

void insert(heaptype *h, element item)
{
    int i;
    i = ++(h -> heap_size);

    while((i != 1) && (item.key > h -> heap[i/2].key)){
        h -> heap[i] = h -> heap[i/2];
        i /= 2;
    }
    
    h -> heap[i] = item;
}

element delete(heaptype * h)
{
    int parent, child;
    element item, temp;

    if(h -> heap_size == 0){
        element empty = {0};
        return empty;
    }
    
    item = h -> heap[1];
    temp = h -> heap[(h -> heap_size)--];
    parent = 1;
    child = 2;

    while(child <= h -> heap_size)
    {
        if((child < h -> heap_size) && (h -> heap[child].key) < (h -> heap[child + 1].key))
            child++;
        if(temp.key >= h -> heap[child].key)
            break;
        h -> heap[parent] = h -> heap[child];
        parent = child;
        child *= 2;
    }
    h -> heap[parent] = temp;
    return item;
    }

    int main()
    {
        h.heap_size = 0;
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);

            if(m == 0){
                element max = delete(&h);
                printf("%d\n", max.key);
            }
            else{
                element item = {m};
                insert(&h, item);
            }
        }
    }
