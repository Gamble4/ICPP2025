#include <iostream>

template <typename T>
T eval_polynomial(T x, T a0)
{
    (void) x; // just to suppress warning, (void) cast works for most types (maybe all)
    return a0;
}

template<typename T, typename... Types>
T eval_polynomial(T x, T a0, Types... an)
{    
    return a0 + x*eval_polynomial(x, an...);
}


// this is awkward since a0 is in the first slot and then the coeffiecients 
// are in reverse order  a_n -> a_{n-1} -> ... 
// but i wanted to use the fold expression, which in this context only unpacks left to right
// even if using (..., expr)
template<typename T, typename... Types>
T horner(T x, T a0, Types... coeffs)
{
    T tmp = 0;    
    return a0+((tmp=(x * (tmp+coeffs))), ...);
}

template<typename... Types>
void print(Types&&... args)
{
    (std::cout << ... << args) << "\n";
}


int main()
{    
    print(
        eval_polynomial(2, 3, 4, 5),        " ", horner(2, 3, 5, 4),      "\n",
        eval_polynomial(-4. , 7., 6., 2.),  " ", horner(-4. , 7., 2., 6.), "\n", 
        eval_polynomial(-4 , -8, -5, 2),    " ", horner(-4 , -8, 2, -5),  "\n", 
        eval_polynomial(9., 2., 7.8, -4.3), " ", horner(9., 2., -4.3, 7.8)
    );

}