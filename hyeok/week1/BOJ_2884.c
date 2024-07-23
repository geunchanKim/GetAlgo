#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int hour, minute;
    scanf("%d %d", &hour, &minute);

    int total;
    total = (hour * 60) + minute + 1440;
    hour = (total - 1485) / 60;

    if((total - 1485) < 0)
    {hour = 23;}

    minute = (total - 45) % 60;

    printf("%d %d", hour, minute);

    return 0;
}