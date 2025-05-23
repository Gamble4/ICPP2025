//#include "../mytools.hpp"
#include <stdio.h>

void create_binom_coeffs(int order, float* B)
{
    B[0] = 1;
    B[order] = 1; // B_{r, r } = 1, so we exclude it in calculation below

    for(int c=1; c<order; c++)
    {
        B[c] = (float) (order-c+1)/c * B[c-1];
    }   
}

int main()
{
    const int order = 10;
    float B[order][order];

    for (int i=0; i<order; i++)
    {
        create_binom_coeffs(i, *(B+i));
    }

    //matf_print(*B, order, order);

    const int id[] = {1, 1, 9, 4, 9, 3, 3, 7};
    size_t id_len = sizeof(id)/sizeof(int);
    int id_new[id_len];
    int c;
    
    for (int i=0; i<id_len; i++)
    {
        id_new[i] = id[i];
        if (id[i] == 0) continue;
        for (int r=0; r<order; r++)
        {
            c = 1;
            
            for (int j=0; j<=r; j++)
            {
                if (id[i] == (int) B[r][j])
                {
                    //printf("found digit %d in order r: %d \n", id[i], r);
                    id_new[i] = r+1;
                    c = 0;
                    break;
                }
            }

            if (c == 0) break;            
        }
    }
    
    printf("\ninitial: ");
    for (int i=0; i<id_len; i++)
    {
        printf("%d | ", id[i]);
    }

    printf("\nnew:     ");
    for (int i=0; i<id_len; i++)
    {
        printf("%d | ", id_new[i]);
    }

}
