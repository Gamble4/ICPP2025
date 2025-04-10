#include <iostream>
#include <fstream>
#include <iomanip>

template<typename TT>
void write_2col(std::basic_ofstream<char>& s, TT& e1, TT& e2, int pad_len=20)
{

    s << std::setw(pad_len) << std::setfill(' ') << e1
      << std::setw(pad_len) << std::setfill(' ') << e2
      << "\n";
}


int main()
{
   
    const std::string fname = "test.txt";
    std::string c1 = "# num points";
    std::string c2 = "pi approximation";
    std::ofstream File(fname);
    if (!File.is_open())
    {
        throw -1;
    }
    int a = 1, b=2;

    write_2col(File, c1, c2);
    write_2col<int>(File, a, b);
    File.close();
   
    
}
