#include <iostream>

template<typename T>
class simpleArr
{
private:
    T m_arr[3];
public:
    simpleArr(T a, T b, T c)
    {
        m_arr[0] = a;
        m_arr[1] = b;
        m_arr[2] = c;
    };

    int *begin()
    {
        return &m_arr[0];
    }

    int *end()
    {
        return &m_arr[3];
    }

    T& operator[](size_t n)
    {
        return m_arr[n];
    }
};

int main()
{
    //h1::testfunc();
    simpleArr<int> a1 {1, 2, 3};
    

    //for (int *it = a1.begin(); it != a1.end(); it++)
    //{
    //    std::cout << *it << "\n";
    //}

    for (int i : a1)
    {
        std::cout << i << "\n";
    }

}


