#include "F1.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>

// +-------------+
// |  Operators  |
// +-------------+

double& matrix::operator()(unsigned int i, unsigned int j) 
{
    // underflow is covered by using unsigned int as parameter types, e.g. i = -1 -> something >0
    if ((i >= numRows) || (j >= numCols) )
    {
        throw std::domain_error("index out of reach");
    }
    return m_data[i][j];
}


const double& matrix::operator()(unsigned int i, unsigned int j) const
{    
    if ((i >= numRows) || (j >= numCols) )
    {
        throw std::domain_error("index out of reach");
    }
    return m_data[i][j];
}

std::vector<double>& matrix::operator[](unsigned int i)
{
    if ((i >= numRows))
    {
        throw std::domain_error("row index out of reach");
    }
    return m_data[i];
}

matrix matrix::operator+(matrix const& rmat) const
{
    check_dims_match(*this, rmat);

    matrix out{numRows,numCols};
    for (unsigned int i=0; i<numRows; i++)
    {
        for (unsigned int j=0; j<numCols; j++)
        {
            out(i, j) = m_data[i][j] + rmat(i, j);
        }
    }
    return out;
}


matrix matrix::operator-(matrix const& rmat) const
{
    check_dims_match(*this, rmat);

    matrix out{numRows,numCols};
    for (unsigned int i=0; i<numRows; i++)
    {
        for (unsigned int j=0; j<numCols; j++)
        {
            out(i, j) = m_data[i][j] - rmat(i, j);
        }
    }
    return out;
}

matrix matrix::operator/(double s) const
{   
    matrix out{numRows, numCols};
    for (unsigned int i=0; i<numRows; i++)
    {
        for (unsigned int j=0; j<numCols; j++)
        {
            out(i, j) = m_data[i][j] / s;
        }
    }
    return out;
}


matrix operator/(double s, matrix const& mat)
{   
    matrix out{mat.get_nrows(), mat.get_ncols()};
    for (unsigned int i=0; i<mat.get_nrows(); i++)
    {
        for (unsigned int j=0; j<mat.get_ncols(); j++)
        {
            out(i, j) = s / mat(i, j);
        }
    }
    return out;
}


matrix matrix::operator*(double s) const
{   
    matrix out{numRows, numCols};
    for (unsigned int i=0; i<numRows; i++)
    {
        for (unsigned int j=0; j<numCols; j++)
        {
            out(i, j) = m_data[i][j] * s;
        }
    }
    return out;
}

matrix operator*(double s, matrix const& mat)
{   
    matrix out{mat.get_nrows(), mat.get_ncols()};
    for (unsigned int i=0; i<mat.get_nrows(); i++)
    {
        for (unsigned int j=0; j<mat.get_ncols(); j++)
        {
            out(i, j) = mat(i, j) * s;
        }
    }
    return out;
}


std::vector<double> matrix::operator*(std::vector<double>& v) const
{   
    if (numCols != v.size())
    {
        throw std::domain_error("dimensions do not match in matrix vector multiplication");
    }

    std::vector<double> out;    
    out.reserve(v.size());
    double tmp;
    for (unsigned int i=0; i<numRows; i++)
    {
        tmp = 0;
        for (unsigned int j=0; j<numCols; j++)
        {            
            tmp+= m_data[i][j] * v[j];
        }
        out.push_back(tmp);
    }
    return out;
}

matrix matrix::operator*(matrix const& rmat) const
{
    check_inner_dims_match(*this, rmat);
    matrix out{numRows, rmat.get_ncols(), 0.};
    for (unsigned int i=0; i<numRows; i++)
    {
        for (unsigned int j=0; j<rmat.get_ncols(); j++)
        {
            for (unsigned int k=0; k<numCols; k++)
                out(i, j) += m_data[i][k] * rmat(k, j);            
        }
    }
    return out;
}
