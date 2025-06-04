#include <cmath>
#include <iomanip>
#include <limits>
#include <iostream>

long long unsigned int fac(int k)
{
    if (k==0) { return 1;}
    return (k)*fac(k-1);
}


constexpr long double pi_approx(long int k)
{
    long double pi=0;
    for (long int i=0; i <= k; i++)
    { 
        //faster than using pow
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2*i + 1);
    }
    return pi*4;

}

constexpr long double e_pi_approx(int k, long double pi)
{
    long double out =0;    
    for (long int i=0; i<=k; i++)
    {
        out += std::pow(pi, i)/ fac(i);        
    }
    return out;
}


constexpr long double e_pi_approx_lambda(int k, long double pi)
{
    long double out =0;
    //self is needed for the recursion
    auto fac = [](auto&& self, int n)-> long long int 
        {
            if (n==0) {return 1;}
            return (n)*self(self, n-1);
        };


    for (int i=0; i<=k; i++)
    {       
        out += std::pow(pi, i)/fac(fac, i);        
    }
    return out;
}

int main()
{
    long int k = 1000000000;
    //std::cout << "pi approx for k= " << k << " " << pic(k);
    long double pi = pi_approx(k);
    std::cout << "pi approx for k= " << k << "\n"
    << std::setprecision (std::numeric_limits<double>::digits10 + 1) << pi << "\n";

    int l = 22;
    //std::cout << fac(l) << "\n";
    //std::cout << std::numeric_limits<long long unsigned int>::max() << "\n";
    // factorial is the bottleneck
    std::cout << "exp(pi) approx for k= " << l << "\n"
    << std::setprecision (std::numeric_limits<double>::digits10 + 1)
    << e_pi_approx(l, pi) << "\n"
    << std::setprecision (std::numeric_limits<double>::digits10 + 1)
    << e_pi_approx_lambda(l, pi) << "\n";
    
    
}