
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

int check_ind_in_array(int* a, int ind, int n)
{
    for (int i=0; i<n; i++)
    {
        if (a[i] == ind)
        {            
            printf("no duplicate indices allowed, exiting \n");
            exit(-1); // maybe allow to change input with while loop?            
            return 1;
        }
    }
    return 0;
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

int compare(void const *a, void const *b)
{
    // compare function in qsort wants void const 
    return *(int*)a - *(int*)b;
}

int check_scanf_success(int scanf_out)
{
    if (!scanf_out) 
    {
        printf("parsing failed, please only enter integer numbers \n");
        exit(-1);
    }
    return 1;
}

int check_is_pos(int in)
{
    if (in <= 0)
    {
        printf("please enter positive integers > 0\n");
        exit(-1);
    }
    return 1;
}


int main()
{
    const int max_num_terms = 10;
    int num_terms, terms[max_num_terms], diffs[max_num_terms];
    int scan_tmp;
    printf("How many terms to calculate? \n");
    check_scanf_success(scanf("%d", &num_terms));
    check_is_pos(num_terms);

    if (num_terms > max_num_terms)
    {
        printf("maximum number of terms is 10\n");
        exit(-1);
    }

    printf("please enter the desired indices: \n");
    for (int i=0; i<num_terms; i++)
    {
        check_scanf_success(scanf("%d", &scan_tmp));
        check_is_pos(scan_tmp);
        check_ind_in_array(terms, scan_tmp, i);
        
        terms[i] = scan_tmp;
    }

    printf("--- Summary of Input ---\n");
    printf("number of terms: %d \n", num_terms);
    printf("selected indices: ");
    for (int i=0; i<num_terms; i++)
    {
        printf("%d:%d, ", i+1, terms[i]);
    }
    printf("\n");

    // take differences in order to compute the terms
    qsort(terms, num_terms, sizeof(int), compare);

    printf("--- Output ---\n");
    printf("natural order of indices: ");
    print_arr(terms, num_terms);

    diffs[0] = terms[0];
    for (int i=0; i<num_terms-1; i++)
    {
        diffs[i+1] = terms[i+1] - terms[i];
    }

    for (int i=0; i<num_terms; i++)
    {        
        terms[i] = lucas(diffs[i]);
    }

    printf("terms order of lucas numbers: ");
    print_arr(terms, num_terms);
}
