#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    char ary[1000001];
    scanf("%[^\n]s", &ary);
    int n = 0;
    int l;
    l = strlen(ary);

    for(int i = 0; i < l; i++ )
    {
        if(ary[i] == ' ')
        { n++; }
    }
    n += 1;

    if(ary[0] == ' ')
        n -= 1;
    if(ary[l-1] == ' ')
        n -= 1;

    printf("%d", n);

    return 0;
}