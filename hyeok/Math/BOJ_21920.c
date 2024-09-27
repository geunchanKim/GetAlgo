#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

long long gcd (long long a, long long b)
{
    while(b != 0)
    {
        long long temp = a % b;
        a = b; b = temp;
    }
    return a;
}

double avr(double a, double b)
{
    return ((a + b) / 2.000000);
}

int main()
{
    double result;
    long long m;
    int test_case, size = 0;
    scanf("%d", &test_case);
    long long* n = (long long*)malloc(sizeof(long long)* test_case);

    for(int i = 0; i < test_case; i++)
    {
        scanf("%lld", &n[i]);
    }

    scanf("%lld", &m);

    for(int i = 0; i < test_case; i++)
    {
        if(gcd(n[i], m) == 1){
            if(size == 0){
                size++;
                result = (double)n[i];
            }
            else{
                result = avr(result, (double)n[i]);
            }
        }
    }

    printf("%.6f", result);
    free(n);
}