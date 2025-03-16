#ifndef OUTPUTFIGURES_HPP
#define OUTPUTFIGURES_HPP
#include <ostream>
#include "shape.hpp"

namespace dirti
{
  std::ostream& outputFigures(const Shape* const* shapes, std::ostream& out);
}

#endif
