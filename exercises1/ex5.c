#include <stdio.h>

         
void
arri_print(int* row, int len)
{
    for (int i=0; i<len; i++) {printf("%d ", row[i]);}
    printf("\n");
}

void
mati_print(int* first_row, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {arri_print(first_row+(i*cols), cols);}
}


int main()
{
    int A[4][2] = {
        {1, 1},
        {9, 4},
        {9, 3},
        {3, 7}};
        
    int* B[2][4];
    int C[2][2];
            
    // get pointers of rows
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<4; j++)    
        {            
            B[i][j] = &A[j][i];         
        }
    }


    // B*A
    int s;
    for (int i=0; i<2; i++) 
    {
        for (int j=0; j<2; j++) 
        {
            s = 0;
            for (int k=0; k<4; k++)
            {
                s+= *(*(*(B+i)+k)) * *(*(A+k)+j);
                //equivalent to *B[i][k] * A[k][j]
            }
            C[i][j] = s;
        }
    }

    mati_print(*C, 2, 2);
    
}
