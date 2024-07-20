#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int n;
    int sum = 0;
    int ary[100];
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%1d", &ary[i]);
    }

    for(int i = 0; i < n; i++)
    {
        sum += ary[i];
    }

    printf("%d", sum);

    return 0;
}