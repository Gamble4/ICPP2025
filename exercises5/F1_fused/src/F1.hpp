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
    matrix(unsigned int rows, unsigned int cols, double fillVal=0.);
    
    /*performs boundary checking and will throw an error if the indices are out of range.Slow but safe */
    std::vector<double>& operator[](unsigned int i);
    /*performs boundary checking and will throw an error if the indices are out of range.Slow but safe */
    double& operator()(unsigned int i, unsigned int j);
    /*performs boundary checking and will throw an error if the indices are out of range.Slow but safe */
    const double& operator()(unsigned int i, unsigned int j) const;

    /*Checks the shape of the matrices before the operations */
    matrix operator+(matrix const&) const;
    matrix operator-(matrix const&) const;
    matrix operator/(double) const;
    matrix operator*(double) const;
    /*Checks the shape of the matrix and vector before multiplying */
    std::vector<double> operator*(std::vector<double>&) const;
    /*Checks the shape of the matrices before multiplying */
    matrix operator*(matrix const&) const;
    
    const unsigned int& get_nrows() const;
    const unsigned int& get_ncols() const;

    // attempt at some iterators
    const std::vector<double>* begin() const;
    const std::vector<double>* end() const;
    
    
} matrix;

matrix operator*(double, matrix const&);
matrix operator/(double, matrix const&);

/*Checks that dim m1 == dim m2, will throw an error if the dimensions do not match*/    
void check_dims_match(matrix const&, matrix const&);
/*Checks that lmat.numCols == rmat.numRows, will throw an error if the dimensions do not match*/
void check_inner_dims_match(matrix const& lmat, matrix const& rmat);

void printVec(std::vector<double> const&);
void printVec(std::vector<double> const&&);
void printMatrix(matrix const&);
void printMatrix(matrix const&&);

#endif