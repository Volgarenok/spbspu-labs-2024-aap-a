#include <iostream>
#include <cstddef>
#include <getLine.hpp>
#include "mergeStrs.hpp"

int main()
{
    size_t capacity = 10;
    char* firstLine = maslovskiy::getLine(std::cin, capacity);
    if (!firstLine)
    {
        std::cerr << "ERROR: Unable to read input string\n";
        return 1;
    }
    if (*firstLine == '\0')
    {
        std::cerr << "ERROR: Input string is empty\n";
        free(firstLine);
        return 2;
    }
    const char secondLine[] = "def_";
    char* resultLine = maslovskiy::mergeStrs(firstLine, secondLine);
    if (!resultLine)
    {
        free(firstLine);
        std::cerr << "ERROR: Memory allocation failed for the result string\n";
        return 1;
    }
    std::cout << resultLine << '\n';
    free(resultLine);
    free(firstLine);
    return 0;
}
