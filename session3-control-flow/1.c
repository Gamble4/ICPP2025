#include <limits.h>
#include<stdio.h>

enum bool
{
    false,
    true
};

int funny_func()
{
    return 1;
}

int return_true()
{
    return true;
}

int main()
{
    char a = 'a';
    printf("%c \n", ++a); // walk the ascii table;;

    short b = 1;
    printf("%d \n",b << 16);
    printf("%d, ", SHRT_MAX);

    if (funny_func() != false)
    {
        printf("true! \n");
    }

    // for loop tests at beginning
    int i = 1, j=0;
    for(; j>i; i++) printf("j: %d", j);

    // do loop tests at end
    do {
        printf("i: %d\n", i);
        
    }while (j>i);

    float arr[5] = {1., 2., 3., 4., 5.};
    for (int i=0; i<5; i++)
    {
        printf("%f, ",*(&arr[0]+i));
    }
    int myarray[3] = {1,5,7}, (*ptr)[3], my2d[2][2] = {{1,2}, {3,4}};
ptr = &myarray;
printf("%p %p %p\n", myarray, &myarray[0], ptr);
printf("%d %d %d\n", *myarray, *(myarray + 1), (*ptr)[0]);
printf("%d %d %d\n", **my2d, **(my2d + 1), *((*my2d) + 1));


    long double x =3.14;
    printf("%Lf", x);

  typedef struct label {
    char label[10];
  } mylabel;
  mylabel *p1, p2 = {"lane"};
  p1 = &p2;
  p1->label[1] = 'i';
  printf("%s\n", p2.label);
  

}
