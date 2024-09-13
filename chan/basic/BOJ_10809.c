#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){
    char word[100];
    int i = 0;
    int ary[26];
    memset(ary, -1, sizeof(int) * 26);
    scanf("%s", word);
    while(word[i]){ 
        int idx = word[i] - 97;
        if(ary[idx] == -1)
            ary[idx] = i;
        i++;
    }
    for(int j = 0; j < 26; j++){
        printf("%d ", ary[j]);
    }
}

