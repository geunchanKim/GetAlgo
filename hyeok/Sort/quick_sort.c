#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max_Size 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[Max_Size];
int n;

int partition(int list[], int left, int right)
{
    int pivot, temp; 
    int low, high;
    pivot = list[left];
    low = left;
    high = right + 1;

    do
    {
        do
            low++;
        while(list[low] < pivot);
        do
            high--;    
        while (list[high] > pivot);
        if(low < high) SWAP(list[low], list[high], temp);
    }while (low < high);
    
    SWAP(list[left], list[high], temp);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if(left < right)
    {
        int p = partition(list, left, right);
        quick_sort(list, left, p - 1);
        quick_sort(list, p + 1, right);
    }
}

int main()
{
    srand(time(NULL));
    n = Max_Size;
    for(int i = 0; i < n; i++)
        list[i] = rand() % 100;
    
    quick_sort(list, 0, n - 1);
    for(int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}