#include <iostream>
#include <../P4/inputString.hpp>
#include "isExpression.hpp"

int main()
{
    unsigned long long length = 0;
    char* string = asafov::inputString(length);
    std::cout << asafov::isExpression(string, 0, length) << std::endl;
}
