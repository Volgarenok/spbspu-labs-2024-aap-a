#ifndef GET_MATRIX_HPP
#define GET_MATRIX_HPP

#include <cstddef>
#include <iosfwd>

namespace rychkov
{
  std::istream& getMatrix(std::istream& inpStream, int* matrix,
      size_t height, size_t width, size_t& wereRead);
}

#endif
