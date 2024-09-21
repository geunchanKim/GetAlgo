#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int ary1[4];
    int ary2[10] = {0, };
    long long int product;

    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &ary1[i]);
    }

    product = ary1[0] * ary1[1] * ary1[2];
    
    while(product > 0)
    {
        ary2[product%10]++;
        product /= 10;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", ary2[i]);
    }

    return 0;

}