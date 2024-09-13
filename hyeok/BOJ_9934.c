#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[1<<10];
int ans[1<<10];
int p[11] = {0};
int n, m;

void loop(int v)
{
    if(v < n){
        loop(v+1);
        ans[p[v]++] = arr[p[10]++];
        loop(v+1);
    }
}

int main()
{
    scanf("%d", &n);
    m = (1<<n) - 1;

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i < 10; i++)
    {
        p[i] = (1<<i) - 1;
    }

    loop(0);

    int k = 2;
    for(int i = 0; i < m; i++)
    {
        if(i == k - 1)
        {
            printf("\n");
            k <<= 1;
        }
        
        printf("%d ", ans[i]);
    }
}