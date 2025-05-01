#include <stdio.h>
#include <stdlib.h>


int main()
{
    const int n = 5;
    int fprintf_success;
    double x[n], y[n];
    for (int i=0; i<n; i++)
    {
        x[i] = i;
        y[i] = i*i;
    }

    const char *file = "test.txt";
    FILE* fp = fopen(file, "w");

    for (int i =0; i<n; i++)
    {
        fprintf_success = fprintf(fp, "%lf %lf \n", x[i], y[i]);

        if (!fprintf_success)
        {
            exit(-1);
        }
    }
    
    fclose(fp);
}
