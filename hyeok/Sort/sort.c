#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max_Size 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[Max_Size];
int n;

void selection_sort(int list[], int n)
{
    int i, j, least, temp;
    for(i = 0; i < n - 1; i++)
    {
        least = i;
        for(j = i + 1; j < n; j++)
            if(list[j] < list[least])
                least = j;
            if(i != least)
                SWAP(list[i], list[least], temp);
    }
}

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for(i = 0; i < n; i++)
    {
        key = list[i];
        for(j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}

void bubble_sort(int list[], int n)
{
    int i, j, temp;
    for(i = n - 1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
            if(list[j] > list[j + 1])
                SWAP(list[j], list[j + 1], temp);
    }
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for(i = first + gap; i <= last; i += gap)
    {
        key = list[i];
        for(j = i - gap; j >= first && key < list[j]; j -= gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for(gap = n / 2; gap > 0; gap /= 2)
    {
        if((gap % 2) == 0) gap++;
        for(i = 0; i < gap; i++)
            inc_insertion_sort(list, i, n - 1, gap);
    }
}

int sorted[Max_Size];

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right)
    {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if(i > mid)
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];
    for(l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main()
{
    int i;
    n = Max_Size;
    srand(time(NULL));
    for(i = 0; i < n; i++)
        list[i] = rand() % 100;

    //selection_sort(list, n);
    //for(i = 0; i < n; i++)
    //    printf("%d ", list[i]);
    //printf("\n");

    //insertion_sort(list, n);
    //for(i = 0; i < n; i++)
    //    printf("%d ", list[i]);
    //printf("\n");
    //return 0; 

    //bubble_sort(list, n);
    //for(i = 0; i < n; i++)
    //    printf("%d ", list[i]);
    //printf("\n");
    //return 0; 

    shell_sort(list, n);
    for(i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}