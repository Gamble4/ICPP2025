#include<stdio.h>

#ifndef MY_TOOLS_IMPLEMENTATION

#define MY_ERROR(message) \
        {printf("Error: %s\n in file %s at line %d\n", message, __FILE__, __LINE__);\
         exit(-1);}

         
void
arri_print(int* row, int len)
{
    for (int i=0; i<len; i++) {printf("%d ", row[i]);}
    printf("\n");
}

void
arrf_print(float* row, int len)
{
    for (int i=0; i<len; i++) {printf("%f ", row[i]);}
    printf("\n");
}

void 
arrip_print(int** row, int len)
{
    for (int i=0; i<len; i++) {printf("%d ", *row[i]);}
    printf("\n");
}

void
mati_print(int* first_row, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {arri_print(first_row+(i*cols), cols);}
}

void
matf_print(float* first_row, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {arrf_print(first_row+(i*cols), cols);}
}

/*
 matrix of integer pointers to array of pointers to integers
 p -> p -> p
*/
void
matipp_print(int** first_row, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {arrip_print(first_row+(i*cols), cols);}    
}

/*
 matrix of integer pointers to array of integers
 p -> p -> i
*/
void
matipi_print(int** first_row, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {arri_print(*(first_row+i), cols);}    
}




#endif // MY_TOOLS_IMPLEMENTATION
