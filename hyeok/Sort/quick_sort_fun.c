#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* arg1, const void* arg2)
{
    if(*(double*)arg1 < *(double*)arg2) return -1;
    else if(*(double*)arg1 == *(double*)arg2) return 0;
    else return 1;
}

int main()
{
    double list[5] = {2.1, 0.9, 1.6, 3.8, 1.2};
    qsort((void*)list, 5, sizeof(double), compare);
    for(int i = 0; i < 5; i++)
        printf("%.3f ", list[i]);
    return 0;
}