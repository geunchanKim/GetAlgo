#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int N, first;
    int max, min;
    scanf("%d", &N); 
    scanf("%d", &first);
    max = first;
    min = first;
    for(int i = 1; i < N; i++){
        int num;
        scanf("%d", &num);
        if(max < num){
            max = num;
        }
        if(min > num){
            min = num;
        }
    }
    printf("%d %d", min, max);
}
