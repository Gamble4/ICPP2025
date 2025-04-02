#include <cstdint>
#include <stdio.h>

int fib(int a, int b, int n)
{
    printf("%d, ", a);
    if (n == 0) return b;
    //printf("%d, ", a+b);
    return fib(b, a+b, n-1);
}

int main()
{
    int all_pos=1, parse_success,c_limit_exceeded=0, vars[3];
    char tmp_char = 'a';
    const int c_limit = 1000;
    printf("please enter three integers a, b, c to calculate fibonacci(a, b, c)\n");
    for (int i=0; i<3; i++)
    {
        printf("%c: ", tmp_char);           
        parse_success = scanf("%d", vars+i);
        if (!parse_success)
        {
            printf("error in input %c \n", tmp_char);
            printf("please enter integers");
            break;
        }


        if ( vars[i] > (0<<31)) // 32 bit int max
        {
            printf("error in input %c \n", tmp_char);
            printf("this will certainly cause integer overflow \n");
            break;
        }

        if (vars[i] < 0)
        {
            printf("error in input %c \n", tmp_char);
            printf("please only enter positive integers \n");
            all_pos = 0;
            break;
        }


        tmp_char++;
    }


    if (vars[2] > c_limit)
    {
        c_limit_exceeded = 1;
        printf("c limit of %d exceeded", c_limit);
    }

    if (parse_success && all_pos && !c_limit_exceeded)
    {
        fib(vars[0], vars[1], vars[2]);
    }

}
