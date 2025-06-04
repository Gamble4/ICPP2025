#include <iostream>


// templates also give you a way of compile-time computing
template <typename T=double, int size=3>
class marray
{
private:
    const int m_size=size;
    T m_data[size];

public:
    marray() {};
    marray(marray& other) 
    {
        for (int i=0; i<other.getSize(); i++)
        {
            m_data[i] = other[i];
        }
    }
    T& operator[](unsigned int i) {return m_data[i];}
    T* begin() {return &m_data[0];}
    T* end()   {return &m_data[m_size];}
    const int& getSize() const { return m_size;}
    void print() {
        for (int i=0; i<m_size; i++)
        {
            std::cout << m_data[i] << " ,";
        }
        std::cout << "\n";
    }

};



// does all the computation at compile time
constexpr double timestwo(double x)
{
    return x*2;
}

int main()
{
    double a, b;
    a = timestwo(2);
    b = timestwo(3);

    marray<int, 4> aarr;
    aarr[0] = 1;
    aarr.print();
    marray<int, 4> barr = aarr;
    barr.print();

    std::cout << a + b << "\n";
}