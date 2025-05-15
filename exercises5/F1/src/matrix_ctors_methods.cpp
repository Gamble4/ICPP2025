#include "F1.hpp"
#include <exception>
#include <stdexcept>
#include <vector>
#include <iostream>

// +-------------+
// |    Ctors    |
// +-------------+

matrix::matrix() 
{
    numRows = 3;
    numCols = 3;
    std::vector<double> unitvec{1, 1, 1};
    m_data.reserve(numCols);
    for (unsigned int i=0; i<numRows; i++)
    {
        m_data.push_back(unitvec);
    }
}

matrix::matrix(unsigned int i, unsigned int j, double fillVal) : numRows {i} , numCols {j}
{    
    std::vector<double> row;
    row.reserve(numCols);

    for (unsigned int i=0; i<numCols; i++)
    {
        row.push_back(fillVal);        
    }

    for (unsigned int i=0; i<numRows; i++)
    {        
        m_data.push_back(row);
    }
}

// +-------------+
// |   Methods   |
// +-------------+

const unsigned int& matrix::get_nrows() const
{return numRows;}

const unsigned int& matrix::get_ncols() const
{return numCols;}

const std::vector<double>* matrix::begin() const
{
    return &m_data[0];
}

const std::vector<double>* matrix::end() const
{
    return &m_data[numRows];
}

// +-------------+
// |  Functions  |
// +-------------+

void check_dims_match(matrix const& lmat, matrix const& rmat)
{
    if ((lmat.get_nrows() != rmat.get_nrows()) || (lmat.get_ncols() != rmat.get_ncols()))
    {   
        throw std::domain_error("matrix dimensions do not match");
    }        
}


void check_inner_dims_match(matrix const& lmat, matrix const& rmat)
{
    if (lmat.get_ncols() != rmat.get_nrows())
    {   
        throw std::domain_error("matrix inner dimensions do not match");
    }        
}


void printMatrix(matrix const& mat)
{
    for (unsigned int i=0; i<mat.get_nrows(); i++)
    {
        std::cout << "( ";
        for (unsigned int j=0; j<mat.get_ncols(); j++)
        {
            std::cout << mat(i, j) << " ";
        }
        std::cout << ")\n";
    }
}


void printMatrix(matrix const&& mat)
{
    for (unsigned int i=0; i<mat.get_nrows(); i++)
    {
        std::cout << "( ";
        for (unsigned int j=0; j<mat.get_ncols(); j++)
        {
            std::cout << mat(i, j) << " ";
        }
        std::cout << ")\n";
    }
}

void printVec(std::vector<double> const& v)
{
    std::cout << "[";
    for (unsigned int i=0; i<v.size(); i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << "]\n";
}


void printVec(std::vector<double> const&& v)
{
    std::cout << "[";
    for (unsigned int i=0; i<v.size(); i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << "]\n";
}

