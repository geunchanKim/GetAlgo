#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define SIZE 100000

int main()
{
    int n, stack[SIZE];
    char result[SIZE * 2];
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num = 1;
    int index = 0;
    int result_index = 0;
    int top = -1;

    while(1)
    {
        if(top == -1 || stack[top] < arr[index])
        {
            stack[++top] = num++;
            result[result_index++] = '+';
        }
        else if(stack[top] == arr[index])
        {
            top--;
            result[result_index++] = '-';
            index++;
        }
        else
        {
            printf("NO\n");
            return 0;
        }
        if(result_index == n * 2) break;
    }

    for(int i = 0; i < result_index; i++)
        printf("%c\n", result[i]);

    free(arr);
}