#include <stdio.h>


int lucas_static(int n)
{
    static int l0 = 2;
    static int l1 = 1;

    //int l0 = 2;
    //int l1 = 1;

    int tmp;    
    for (int i=0; i<n; i++)
    {
        tmp = l0+l1;
        l0 = l1;
        l1 = tmp;
    }
    return l1;
}

int lucas(int n)
{
    int l0 = 2;
    int l1 = 1;

    int tmp;    
    for (int i=0; i<n; i++)
    {
        tmp = l0+l1;
        l0 = l1;
        l1 = tmp;
    }
    return l1;
}



int main()
{
    int n = 3, terms[3]={1, 2, 8};
    int diffs[] = {1, 1, 6};


    for (int i=0; i<3; i++)
    {
        printf("lucas nr for n=%d: %d \n", i, lucas(terms[i]));
        printf("lucas static n=%d: %d \n", i, lucas_static(diffs[i]));
    }
}
