#include <stdio.h>
#include <stdlib.h>
#define Max_terms 101

typedef struct{
    int rows;
    int cols;
    int value;
}element;

typedef struct SparceMatrix{
    element data[Max_terms];
    int rows;
    int cols;
    int terms;
}SparceMatrix;

SparceMatrix matrix_transpose(SparceMatrix A)
{
    SparceMatrix B;

    int bindex;
    B.rows = A.rows;
    B.cols = A.cols;
    B.terms = A.terms;

    if(A.terms > 0)
    {
        bindex = 0;
        for(int c = 0; c < A.cols; c++)
        {
            for(int i = 0; i < A.terms; i++)
            {
                if(A.data[i].cols == c)
                {
                    B.data[bindex].rows = A.data[i].cols;
                    B.data[bindex].cols = A.data[i].rows;
                    B.data[bindex].value = A.data[i].value;
                    bindex++;
                }
            }
        }
    }

    return B;
}

void print_matrix(SparceMatrix A)
{
    for(int i = 0; i < A.terms; i++)
    {
        printf("{%d, %d, %d}\n", A.data[i].rows, A.data[i].cols, A.data[i].value);
    }
}

int main()
{
    SparceMatrix m = {{{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}}, 6, 6, 7};
    SparceMatrix result = matrix_transpose(m);

    print_matrix(result);
    return 0;
}