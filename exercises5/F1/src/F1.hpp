#include <vector>

#ifndef MY_MATRIX_IMP
#define MY_MATRIX_IMP


typedef class matrix
{
private:
    unsigned int numRows; 
    unsigned int numCols;
    std::vector<std::vector<double>> m_data;
public:
    matrix();
    matrix(unsigned int rows, unsigned int cols);

    double& operator()(unsigned int, unsigned int);
    const unsigned int& get_rows();
    const unsigned int& get_cols();
    
    
} matrix;

void printMatrix(matrix&);

#endif