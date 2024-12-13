#include <iostream>

#define ROWS 3
#define COLS 3

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < ROWS; c++)
        {
            B[r][c] = A[r][c];
        }
    }
}

void matrix_print(int A[ROWS][COLS])
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < ROWS; c++)
        {
            printf("%d ", A[r][c]); 
        }
        printf("\n");
    }
}

int main()
{
    int array_1[ROWS][COLS] = {{2, 3, 0}, {8, 9, 1},{7, 0, 5}};
    int array_2[ROWS][COLS];

    matrix_transpose(array_1, array_2);
    matrix_print(array_1);
    matrix_print(array_2);

    return 0;
}