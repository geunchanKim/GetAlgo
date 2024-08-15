#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int ary[8];
    for(int i = 0; i < 8; i++){
        scanf("%d", &ary[i]);}

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