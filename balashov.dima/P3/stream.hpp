#ifndef STREAM_HPP
#define STREAM_HPP

#include <iostream>
#include <fstream>

namespace balashov
{
 std::istream & inputMatrix(std::istream & in, int * matrix, size_t column, size_t row, size_t & read);
 void outputMtx(std::ostream & out, const int * matrix, size_t column, size_t row);
}

#endif
