#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int N, K, cnt = 0;
    scanf("%d %d", &N, &K);
    int* visited = (int*)calloc(N + 1, sizeof(int));

    for(int i = 2; i <= N; i++)
    {
        for(int j = i; j <= N; j += i)
        {
            if(!visited[j])
            {
                cnt++;
                visited[j] = 1;
                if(cnt == K)
                {
                    printf("%d", j);
                    break;
                }
            }
        }
    }

    free(visited);
}