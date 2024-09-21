#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct pokemon{
    char name[21];
    int num;
}pokemon;

int cmp(const pokemon* a, const pokemon* b){
    char* na = (char*)a -> name;
    char* nb = (char*)b -> name;
    return strcmp(na, nb);
}

int main()
{
    int n, m;
    scanf(" %d %d", &n, &m);

    pokemon* pokeidx = (pokemon*)malloc(sizeof(pokemon)* n);
    pokemon* pokename = (pokemon*)malloc(sizeof(pokemon)* n);

    for(int i = 0; i < n; i++)
    {
        pokeidx[i].num = pokename[i].num = i + 1;
        scanf(" %s", pokename[i].name);
        strcpy(pokeidx[i].name, pokename[i].name);
    }

    qsort(pokename, n, sizeof(pokemon), cmp);

    for(int i = 0; i < m; i++)
    {
        char q[21];
        scanf("%s", q);

        if(q[0] >= '0' && q[0] <= '9')
        {
            int idx = atoi(q);
            printf("%s\n", pokeidx[idx - 1].name);
        }
        else{
            int mid, left = 0, right = n - 1;
            while(right >= left)
            {
                mid = (left + right) / 2;
                if(strcmp(pokename[mid].name, q) == 0) break;
                else if(strcmp(pokename[mid].name, q) > 0) right = mid - 1;
                else left = mid + 1;
            }
            printf("%d\n", pokename[mid].num);
        }
    }

    free(pokeidx);
    free(pokename);
}