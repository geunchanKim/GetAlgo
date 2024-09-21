#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int t;
    scanf("%d", &t);

    int h[100], w[100], n[10000];

    for(int i = 0; i < t; i++)
    {   
        scanf("%d %d %d", &h[i], &w[i], &n[i]);
    }

    int rh[100], rw[100];
    for(int i = 0; i < t; i++)
    {
        rh[i] = n[i] % h[i];
        if(rh[i] == 0)
        {rh[i] = h[i];
         rw[i] = n[i] / h[i];}
        else
        rw[i] = (n[i] / h[i]) + 1; 
    }

    for(int i = 0; i < t; i++)
    {
        printf("%d%02d\n", rh[i], rw[i]);
    }

    return 0;
}