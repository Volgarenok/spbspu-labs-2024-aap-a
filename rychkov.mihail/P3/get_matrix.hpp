#ifndef GET_MATRIX_HPP
#define GET_MATRIX_HPP

#include <cstddef>
#include <iosfwd>

namespace rychkov
{
  int getMatrix(std::istream& inpStream, int* matrix, size_t height, size_t width);
}

#endif
