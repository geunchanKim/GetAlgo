#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int s, ans;
    char str[100001];
    scanf("%s", str);
    s = 0; ans = 0;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '('){
            s++;}
        else if(str[i] == ')')
        {
            s--;
            if(str[i - 1] == '('){
                ans += s;}
            else{
                ans += 1;}
        }
    }
    printf("%d", ans);
}