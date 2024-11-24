#include <iostream>
#include <arrays_input.hpp>
#include "recursion.hpp"

int main()
{
    size_t size1 = 0;
    size_t max = 10;
    std::cin >> size1;
    if (size1 == 0)
    {
      std::cerr << "Dry run";
      return 1;
    }
    char * s1 = kushekbaev::readInputArray(size1, max);
    std::cout << kushekbaev::isValidExpression(s1) << "\n";
    delete[] s1;
    return 0;
}
