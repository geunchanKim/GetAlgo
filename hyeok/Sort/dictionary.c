#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define Max_Word_Size 50
#define Max_Meaning_Size 500
#define SIZE 5

typedef struct element{
    char word[Max_Word_Size];
    char meaning[Max_Meaning_Size];
}element;
element list[SIZE];

int compare(const void *arg1, const void* arg2)
{
    return (strcmp(((element*)arg1)->word, ((element*)arg2)->word));
}

int main()
{
    int i, j;
    element temp;

    printf("5개의 단어와 의미를 입력하시오\n");

    for(i = 0; i < SIZE; i++)
    {
        scanf("%s[^\n]", list[i].word);
        scanf("%s[^\n]", list[i].meaning);
    }

    qsort((void*)list, 5, sizeof(element), compare);

    printf("\n정렬 후 사전의 내용:\n");
    for(i = 0; i < SIZE; i++)
        printf("%s: %s\n", list[i].word, list[i].meaning);

    return 0;
}