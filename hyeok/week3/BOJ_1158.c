#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int N, K, idx, result_idx, count;
    scanf("%d%d", &N, &K);
    int *arr = (int *)malloc(sizeof(int) *N);
    int *result = (int *)malloc(sizeof(int) *N);
    for(int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    count = 0;
    idx = 0;
    result_idx = 0;
    while(result_idx < N)
    {
        if(arr[idx] != 0)
        {
            count++;
        }
        if(count == K)
        {
            result[result_idx] = arr[idx];
            arr[idx] = 0;
            result_idx++;
            count = 0;
        }
        idx = (idx + 1) % N;
    }

    printf("<");
    for(int i = 0; i < N - 1; i++)
    {
        printf("%d, ", result[i]);
    }
    printf("%d>", result[N - 1]);
}