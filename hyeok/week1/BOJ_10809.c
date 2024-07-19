#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    char str[100];
    scanf("%s", str);
    int ary[26];
    for(int i = 0; i < 26; i++)
    {
        ary[i] = -1;
    }

    for (int i = 0; i < strlen(str); i++)
    {
        int idx = str[i] - 97; 

        if (ary[idx] == -1)
        {
            ary[idx] = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d ", ary[i]);
    }

    return 0;
}