#include <stdio.h>



int main()
{
    int A[4][2] = {
        {1, 1},
        {9, 4},
        {9, 3},
        {3, 7}};
        
    int* B[2][4];
    
        
    // get pointers of rows
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<4; j++)    
        {            
            //printf("%p \n", (voA*) A[i]);
            B[i][j] = &A[j][i];         
        }
    }

    int C[2][2];

    
    // B*A
    int s;
    for (int i=0; i<2; i++) // rows in B
    {
        for (int j=0; j<2; j++) // cols in A
        {
            s = 0;
            for (int k=0; k<4; k++)
            {
                s+= *B[i][k] * A[k][j];
            }
            C[i][j] = s;
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
}
