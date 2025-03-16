#include <stdio.h>

int greateri(int a, int b)
{
    return (a>b) ? a:b;
}


int main(){

    printf("Hello, World! \n");

    printf("%d\n", greateri(6, 5));

    int a = 5;
    int b = 6;

    (a > b) ? 
    printf("a is greater\n") :
    printf("b is greater\n") ;


    return 0;
}