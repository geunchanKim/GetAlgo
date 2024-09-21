#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int t, n, m, count, front, max;
    int arr[100];
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &m);

        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        count = 1;
        front = 0;
        while(1)
        {   
            max = 0;
            for(int j = 0; j < n; j++)
            {
                if(arr[j] > max)
                max = arr[j];
            }
            while(arr[front] != max)
            {
                front = (front + 1) % n;
            }
            if(front == m) break;
            arr[front] = 0;
            count++;
        }
        printf("%d\n", count);
    }
}