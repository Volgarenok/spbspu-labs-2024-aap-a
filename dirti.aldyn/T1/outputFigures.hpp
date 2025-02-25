#ifndef OUTPUTFIGURES_HPP
#define OUTPUTFIGURES_HPP
#include <ostream>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

namespace dirti
{
  std::ostream& outputFigures(Shape** shapes, std::ostream& out);
}

#endif
