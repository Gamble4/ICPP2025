#include "F1.hpp"
#include <vector>
#include <iostream>

matrix::matrix() 
{
    numRows = 3;
    numCols = 3;
    std::vector<double> unitvec{1, 1, 1};
    for (unsigned int i=0; i<numRows; i++)
    {
        m_data.reserve(numCols);
        m_data.push_back(unitvec);
    }
}

matrix::matrix(unsigned int i, unsigned int j) : numRows {i}, numCols {j}
{
    std::vector<double> row;
    row.reserve(numCols);
    
    for (unsigned int i=0; i<numRows; i++)
    {
        m_data.reserve(numCols);
        m_data.push_back(unitvec);
    }
}

double& matrix::operator()(unsigned int i, unsigned int j)
{
    return m_data[i][j];
}

const unsigned int& matrix::get_rows() {return numRows;}
const unsigned int& matrix::get_cols() {return numCols;}

void printMatrix(matrix& mat)
{
    for (unsigned int i=0; i<mat.get_rows(); i++)
    {
        for (unsigned int j=0; j<mat.get_cols(); j++)
        {
            std::cout << mat(i, j) << " ";
        }
        std::cout << "\n";
    }
}