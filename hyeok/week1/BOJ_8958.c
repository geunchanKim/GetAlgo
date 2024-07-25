#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        int n[81] = {0};
        char str[81];
        scanf("%s", str);

        for(int j = 0; j < strlen(str); j++)
        {
            if(str[j] == 'O')
            {
                if(j > 0 && str[j-1] == 'O')
                n[j] = n[j-1] + 1;
                else
                n[j] = 1;
            }
        }
        int score = 0;
        for(int i = 0; i < strlen(str); i++)
        {
            score += n[i];
        }

        printf("%d\n", score);
    }

    return 0;
}