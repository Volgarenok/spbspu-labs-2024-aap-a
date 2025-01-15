#ifndef KIZHIN_T1_IO_UTILS_HPP
#define KIZHIN_T1_IO_UTILS_HPP

#include <iosfwd>
#include "composite_shape.hpp"

namespace kizhin {
  std::ostream& outputShapesInfo(std::ostream&, const CompositeShape&);
  double* processInput(std::istream&, std::ostream&, CompositeShape&);
}

#endif

