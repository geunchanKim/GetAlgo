#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        long long m;
        scanf("%lld", &m);

        if(m == 0 || m == 1 || m == 2)
        {
            printf("%d\n", 2);
        }
        else{
            while(1)
            {
                long long result = 0;
                for(int j = 2; j <= sqrt((double)m); j++)
                {
                    if(m % j == 0)
                    {
                        result++;
                     break;
                    }
                }
                if(result == 0)
                {   
                    printf("%lld\n", m);
                    break;
                }
                m++;
            }
        }
    }
}