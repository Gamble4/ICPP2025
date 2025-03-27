#include <stdio.h>

int main()
{
    const int order = 10;
    float B[order];
    B[0]= 1;

    for(int r=0; r<order; r++)
    {
        B[r] = 1; // B_{r, r } = 1, so we exclude it in calculation below
        for(int c=1; c<r; c++)
        {
            B[c] = (float) (r-c+1)/c * B[c-1];
        }
        
    // the printing
    printf("%d: ", r);
    for(int j=0; j<=r; j++)
    {
        printf("%d, ", (int) B[j]);
    }
    printf("\n");
    }
}
