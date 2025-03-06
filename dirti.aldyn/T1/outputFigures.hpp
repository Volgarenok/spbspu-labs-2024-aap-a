#ifndef OUTPUTFIGURES_HPP
#define OUTPUTFIGURES_HPP
#include <ostream>
#include "shape.hpp"

namespace dirti
{
  std::ostream& outputFigures(Shape** shapes, std::ostream& out);
}

#endif
