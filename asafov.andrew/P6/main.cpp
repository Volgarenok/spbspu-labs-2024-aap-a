#include <iostream>
#include <../../asafov.andrew/P4/pull.h>
#include "isExpression.hpp"

int main()
{
    unsigned long long length = 0;
    char* string = asafov::inputString(length);
    int res = asafov::isExpression(string, 0, length, 0);
    std::cout<<res<<'\n';
    return 0;
}
