#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

long long sosu(long long n)
{   
    if(n < 2) return 0;
    for(long long i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int A;
    long long N, result = 1;
    scanf("%d", &A);

    int* visited = (int*)calloc(1000001, sizeof(int));

    for(int i = 0; i < A; i++)
    {
        scanf("%lld", &N);
        if(!visited[N])
        {
            visited[N] = 1;
            if(sosu(N))
            {
                result *= N;
            }
        }
    }

    if(result == 1)
    {
        result = -1;
    }

    printf("%lld\n", result);

    free(visited);
}