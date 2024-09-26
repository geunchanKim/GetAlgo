#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

long long gcd (long long a, long long b)
{
    while(b != 0)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm (long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", lcm(a,b));
    }
}