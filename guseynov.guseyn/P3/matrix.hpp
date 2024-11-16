#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <iosfwd>

namespace guseynov
{
  std::istream & inputMtx(std::istream &in, int *arr, size_t generalLength, size_t & read);
  size_t searchNumLocMin(const int *arr, size_t generalLength);
}

#endif
