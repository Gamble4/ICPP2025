#include <iostream>

template <typename T>
T eval_polynomial(T x, T a0)
{
    return a0;
}

template<typename T, typename... Types>
T eval_polynomial(T x, T a1, Types... an)
{    
    return a1 + x*eval_polynomial(x, an...);
}

template<typename T, typename... Types>
T eval_polynomial_fold(T x, Types... an)
{    
    return ( ... * (x*(x+an)));
}
// (x* ((an-1 + x)*(an+x))
// left fold -> ((ao + x) * (a1+x)) * (a2+x)

template <typename T, typename... Coeffs>
T horner(T x, Coeffs... coeffs) {
    return (coeffs + ... * x);  // Left fold: (((aₙ * x + aₙ₋₁) * x + ...) + a₀)
}

int main()
{
    
    double res = eval_polynomial(2.,   3., 4.);
    double res_fold = eval_polynomial_fold(2., 4., 3.);
    std::cout << res << "\n" << res_fold << "\n";
}