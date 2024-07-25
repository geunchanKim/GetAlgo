#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int ary[8];
    
    scanf("%d %d %d %d %d %d %d %d", &ary[0], &ary[1], &ary[2], &ary[3], &ary[4], &ary[5], &ary[6], &ary[7]);

    int asc = 1;
    int des = 1;
    int mix = 1;
    for(int i = 0; i < 8; i++)
    {
       if(i + 1 != ary[i])
        {
            asc = 0;
        }
        if(ary[i] != 8 - i)
        {
            des = 0;
        }
    }

    if(asc)
    {
        printf("ascending");
    }
    else if(des)
    {
        printf("descending");
    }
    else printf("mixed");
    
    return 0;
}