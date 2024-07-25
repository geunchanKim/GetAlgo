#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int ary[11];
    int rem[11];
    int rem_count = 0;
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &ary[i]);
    }

    for(int i = 0; i < 10; i++)
    {
        rem[i] = ary[i] % 42;
    }

    for(int i = 0; i < 10; i++)
    {   
        int n = 1;
        for(int j = 0; j < i; j++)
        {
            if(rem[i] == rem[j])
            {
                n = 0;
                break;
            }
        }
        if(n)
        {rem_count++;}
    }

    printf("%d", rem_count);

    return 0;
}