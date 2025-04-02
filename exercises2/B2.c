
#include <stdio.h>
#include <stdlib.h>

void print_arr(int* arr, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int ind_in_array(int* a, int ind, int n)
{
    for (int i=0; i<n; i++)
    {
        if (a[i] == ind) return 1;
    }
    return 0;
}

int ind_max(int *arr, int n)
{
    int i = 0;
    for (int j=0; j<n; j++)
    {
        if (arr[j] > arr[i]) i = j;
    }

    return i;
}

int lucas(int n)
{
    static int l0 = 2;
    static int l1 = 1;

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
    const int max_num_terms = 10;
    int num_terms, scanf_success, terms[max_num_terms], natural[num_terms];
    int scan_tmp;
    printf("How many terms to calculate? \n");
    scanf_success = scanf("%d", &num_terms);
    if (!scanf_success || num_terms > max_num_terms) // make this nicer
    {
        exit(-1);
    }

    printf("please enter the desired indices: \n");
    for (int i=0; i<num_terms; i++)
    {
        scanf("%d", &scan_tmp);
        if (ind_in_array(terms, scan_tmp, i))
        {
            printf("no duplicate indices allowed, exiting \n");
            exit(-1); // maybe allow to change input with while loop?
        }
        terms[i] = scan_tmp;   
        natural[i] = scan_tmp;             
    }

    printf("--- Summary of Input ---\n");
    printf("number of terms: %d \n", num_terms);
    printf("selected indices: ");
    for (int i=0; i<num_terms; i++)
    {
        printf("%d:%d, ", i+1, terms[i]);
    }
    printf("\n");

    printf("%d ", lucas(10));
    // take differences in order to compute the terms
    for (int i=0; i<num_terms; i++)
    {
        qsort(natural, num_terms, sizeof(int), void*);
        natural[i] = lucas(natural[i+1]-natural[i]);
    }
}
