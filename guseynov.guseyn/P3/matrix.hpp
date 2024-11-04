#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <iosfwd>

namespace guseynov
{
std::istream & inputMtx(std::istream &in, int *arr, size_t general, size_t & read);
size_t searchNumLogMin(const int *arr, size_t general);
}

#endif
