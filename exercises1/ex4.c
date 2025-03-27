#include <stdio.h>

void print_mat(int rows, int cols, int** mat)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            printf("%d", mat[i][j]);
        }
    }
}

int main()
{
    int A[4][2] = {
    {1, 1},
    {9, 4},
    {9, 3},
    {3, 7}};
    
    int* B[2][4];

    printf("before: \n");
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<2; j++)
        {
            printf("%d", A[i][j]);
        }
        printf("\n");
    }

    printf("after: \n");

    // get pointers of rows
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<4; j++)    
        {            
            //printf("%p \n", (voA*) A[i]);
            B[i][j] = &A[j][i];
            printf("%d", *B[i][j]);
        }
        printf("\n");
    }
    
    //print_mat(4, 2, A);
    printf("%p", A);
    
    
    
}
