#include <stdio.h>


void print_mat(int rows, int cols, int** mat)
{
    for (int i=0; i< rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            printf("%d ", mat[i][j]);
        }
    printf("\n");
    }
}

int main()
{
    int* B[2];
    int row1[3] = {1, 2, 3};
    int row2[3] = {4, 5, 6};

    B[0] = row1;
    B[1] = row2;

    print_mat(2, 3, B);
}
