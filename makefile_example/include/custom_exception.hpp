#include <exception>
#include <stdexcept>
#include <iostream>

class myexcpt : public std::runtime_error
{
public:
    myexcpt(std::string file, unsigned int line, std::string msg="") :
    std::runtime_error(msg)
    {    
        std::cout << "in File: " << file << " \n"
        << "in Line: " << line << std::endl;
    };
};
