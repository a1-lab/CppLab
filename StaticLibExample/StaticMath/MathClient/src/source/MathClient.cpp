#include <iostream>
#include "MathLibrary.h"

using namespace MathLibrary;

int main()
{
    std::cout << "Hello World!\n";

    double a = 7.4;
    int b = 2;

    std::cout << "a+b=" << Arithmetic::Add(a, b) << std::endl;
    std::cout << "a-b=" << Arithmetic::Subtract(a, b) << std::endl;
}
