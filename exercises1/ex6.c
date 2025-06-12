#include <stdio.h>
#include <math.h>
#include <complex.h>

void cprintf(complex float z)
{
    printf("%f%c%fi",
         creal(z), (cimag(z) < 0.) ? '\0' : '+', cimag(z));
}

complex float root(float a, float b, float c, int sign)
{
    float disc = pow(b, 2) - 4*a*c;
    if (disc < 0)
    {
        printf("warning: complex valued discriminant \n");
        
        complex float c_b, c_c, c_a;
        c_a = (complex float) a;
        c_b = (complex float) b;
        c_c = (complex float) c;
        return (-c_b + sign * csqrtf(cpowf(b, 2) - 4*c_a * c_c)) / (2*c_a);
    }
    else if (disc == 0.)
    {
        printf("discriminant is 0 \n");
        return -b / (2*a);
    }
    return (-b + sign * sqrtf(powf(b, 2) - 4*a*c)) / (2*a);
}

int main()
{
    complex float proot = root(1., 1., 9., +1);
    cprintf(proot);
    printf("\n");

    complex float nroot = root(1., 1., 9., -1);
    cprintf(nroot);
    printf("\n");

    // test
    //complex float test_proot = root(2., 4., 5., +1);
    //cprintf(test_proot);
    //printf("\n");
}

