#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct arr{
    char name[501];
} arr;

int cmp(const arr* a, const arr* b)
{
    return strcmp(a -> name, b -> name);
}

int search(arr* sets, int n, char* target)
{
    int left = 0, right = n - 1;
    while(right >= left)
    {
        int mid = (left + right) / 2;
        int cmp_result = strcmp(sets[mid].name, target);
        if(cmp_result == 0) return 1;
        else if(cmp_result > 0) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    arr* sets = (arr*)malloc(sizeof(arr)* n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%s", sets[i].name);
    }

    qsort(sets, n, sizeof(arr), cmp);

    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        char q[501];
        scanf("%s", q);
        if(search(sets, n, q))
        cnt++;
    }

    printf("%d", cnt);
    free(sets);
}