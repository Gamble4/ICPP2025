#include "../mytools.hpp"
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

    switch (a)
    {
        case 1: printf("1\n");
            // other things
            a = 3;
            break; // <-- break required to stop switch
        default: printf("%d\n", a); break;
    }


    int drink;
    float price = 0.;

    while (price == 0.)
    {
        printf("Getränk wählen: (1, 2, 3)\n");
        scanf("%d", &drink);

        switch (drink) {
            case 1: price = 0.5; break;
            case 2: price = 1.0; break;  
            case 3: price = 2.0; break;
            default: printf("bitte nur szwischen 1-3 wählen\n");
        }
    }

    float paid = 0.;

    while (true)
    {
        printf("bitte werfen sie %.2f ein (oder -1 um Abszubrechen): ", price);
        scanf("%f", &paid);
        if (paid == price)
        {
            price = 0.;
            paid = 0;
            printf("vielen Dank! \n");
            break;
        }
        else if (paid == -1)
        {
            printf("Abgebrochen\n");
            break;
        }
    }

    return 0;
}