#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int gcd(int a, int b){
    while(b != 0)
    {
        int temp = a % b;
        a = b; b = temp;
    }
    return a;
}

int main()
{
    int t, num, arr[100];
    long long sum = 0;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }

        for(int i = 0; i < num; i++)
        {
            for(int j = i + 1; j < num; j++)
            {
                sum += gcd(arr[i], arr[j]);
            }
        }

        printf("%lld\n", sum);
        sum = 0;
    }
}