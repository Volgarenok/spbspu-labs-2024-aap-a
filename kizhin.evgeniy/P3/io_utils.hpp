#ifndef IO_UTILS_HPP
#define IO_UTILS_HPP

#include <iostream>

namespace kizhin {
  std::istream& readMatrixDimensions(std::istream&, size_t*, size_t*);
  std::istream& readArrayValues(std::istream&, int*, size_t);
  std::ostream& writeResultToFile(std::ostream&, size_t);
}

#endif
