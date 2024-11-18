#include <iostream>
#include <arrays_input>
#include "recursion.hpp"

int main()
{
    size_t size1 = 0;
    size_t max = 10;
    std::cin >> size1;
    char * s1 = kushekbaev::readInputArray(size1, max);
    std::cout << kushekbaev::isValidExpression(s1) << "\n";
    return 0;
}
