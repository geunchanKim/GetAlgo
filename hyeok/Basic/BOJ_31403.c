#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int a, b, c, i;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    printf("%d\n", a + b - c);

    char s1[10], s2[10];
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
    strcat(s1, s2);
    i = atoi(s1);

    printf("%d", i - c);

    return 0;
}