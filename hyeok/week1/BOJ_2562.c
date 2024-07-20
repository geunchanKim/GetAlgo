#include <stdio.h>
#define _CRT_SECURE_NO_WARNIGS

int main(void)
{
    int ary[9];
    int max = 0;
    int n = 0;

    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &ary[i]);
    }

    max = ary[0];

    for(int i = 0; i < 9; i++)
    {
        if(max < ary[i])
        max = ary[i];
    }

    printf("%d\n", max);

    for(int i = 0; i < 9; i++)
        if(max == ary[i])
        {
            n = i;
            break;
        }

    printf("%d", n + 1);
    return 0;
}