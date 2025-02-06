#ifndef PROCESSLINE_HPP
#define PROCESSLINE_HPP

#include <iostream>

namespace belobrov
{
    char* inputString(std::istream& input);
    char* resizeBuffer(const char* oldBuffer, size_t newSize);
}

#endif
