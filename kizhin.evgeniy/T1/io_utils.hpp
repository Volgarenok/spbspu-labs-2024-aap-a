#ifndef KIZHIN_T1_IO_UTILS_HPP
#define KIZHIN_T1_IO_UTILS_HPP

#include <iosfwd>
#include "shape.hpp"

namespace kizhin {
  double* processInput(std::istream&, std::ostream&, Shape**);
  double* parseInputShape(std::istream&, std::string&);
  std::ostream& outputShapeFrame(std::ostream&, const Shape*);
  std::ostream& outputShapesInfo(std::ostream&, const Shape* const*);
}

#endif
