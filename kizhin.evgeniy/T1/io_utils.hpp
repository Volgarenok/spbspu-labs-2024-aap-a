#ifndef IO_UTILS_HPP
#define IO_UTILS_HPP

#include <iosfwd>
#include "shape.hpp"

namespace kizhin {
  double* processInput(std::istream&, std::ostream&, size_t&, Shape**);
  void parseInputString(std::istream&, char**, double**);
  std::ostream& outputShapeFrame(std::ostream&, const Shape*);
  std::ostream& outputShapesInfo(std::ostream&, const Shape* const*, size_t);
  std::ostream& outputShapeError(std::ostream&, const char*, const double*);
}

#endif

