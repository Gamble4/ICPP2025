#include <stdio.h>
#include <stdlib.h>

int check_scanf_success(int scanf_out)
{
    if (!scanf_out) 
    {
        printf("parsing failed, please only enter integer numbers \n");
        return 0;
    }
    return 1;
}

int check_is_pos(int in)
{
    if (in < 0)
    {
        printf("please enter positive integers >= 0\n");
        return 0;
    }
    return 1;
}


int fib(int a, int b, int n)
{
    if (n == 0) return b;
    printf("%d, ", a);
    return fib(b, a+b, n-1);
}

int main()
{
    int css, cip, vars[3];
    char tmp_char = 'a';
    const int c_limit = 1000;
    printf("please enter three integers a, b, c to calculate fibonacci(a, b, c)\n");
    for (int i=0; i<3; i++)
    {
        printf("%c: ", tmp_char);           
        css = check_scanf_success(scanf("%d", vars+i));
        cip = check_is_pos(vars[i]);
        if (!css || !cip)
        {
            printf("error in input %c \n", tmp_char);
            exit(-1);
        }
        tmp_char++;
    }


    if (vars[2] > c_limit)
    {        
        printf("c limit of %d exceeded\n", c_limit);
        exit(-1);
    }

    fib(vars[0], vars[1], vars[2]);
    
    printf("\n");

}
