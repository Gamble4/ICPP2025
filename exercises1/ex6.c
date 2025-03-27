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
        //complex float c_disc = csqrtf((complex float) disc);
        //print_complex(c_disc);
        
        complex float c_b, c_c, c_a;
        c_a = (complex float) a;
        c_b = (complex float) b;
        c_c = (complex float) c;
        return (cpowf(c_b, 2) + sign * csqrtf(cpowf(b, 2) - 4*c_a * c_c))
            / (2*c_a);
    }
    else if (disc == 0.)
    {
        return powf(b, 2) / (2*a);
    }
    return (powf(b, 2) + sign * sqrtf(powf(b, 2) - 4*a*c))
        / (2*a);
}

int main()
{
    
    cprintf(root(1., 1., 9., +1));
}

