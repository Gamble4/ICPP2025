#include "src/F1.hpp"
#include <iostream>
#include <vector>

void p(std::string&& i)
{
    std::cout << i << "\n";
}

int main()
{
    
    matrix defaultmat{};
    // can use custom fill values as last argument, default value is 0.
    matrix mat1{3, 3, 3.};
    matrix mat2{3, 3, 6.};    
        
    p("default matrix");
    printMatrix(defaultmat);
    p("matrix 1: ");
    printMatrix(mat1);
    p("matrix 2: ");
    // can add, subtract matrices if dimensions match
    p("add and subtract");
    printMatrix(mat1 + mat2);
    printMatrix(mat1 - mat2);
    // can multiply and divide with scalars elementwise in ''both directions''
    p("multiply and divide");
    printMatrix(mat1 * 3.);
    printMatrix(3. * mat2);

    printMatrix(mat1 / 2);
    printMatrix(2 / mat2);

    // matrix multiplication + changing some values
    matrix mat3{3, 2, 2.4};
    p("matrix mult / matix vector mult");
    mat3(0, 1) = 7;
    mat3(2, 1) = -2;
    // mat1(3, 1) = 8; // throws error
    printMatrix(mat1 * mat3);
    // printMatrix(mat3 * mat1); // throws error since inner dimensions do not match

    // can join arithmetic expressions for matrices and matrix times vector mult
    std::vector<double> v1{1., 2., 3.};
    printVec((2*mat1 + 6/mat2) * v1);
       
    // very simple row iterator
    p("simple row iterator");
    for (auto& v : mat1)
    {
        printVec(v);
    }

}