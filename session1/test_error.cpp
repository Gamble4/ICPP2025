#include "../mytools.hpp"
#include<iostream>

void raiseError(char* msg)
{
    MY_ERROR(msg);
}

void ok()
{
}

int main()
{
    int a=5, b=6;
    std::string msg = "a is greater";
    char* msg_ptr = &msg[0];
    MY_ERROR("test");
    (b > a) ?
    ok():
    raiseError(msg_ptr);
}