#ifndef UNIFIED_SHAPES_HPP
#define UNIFIED_SHAPES_HPP
#include <istream>
#include <ostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "polygon.hpp"
#include "composite-shape.hpp"

namespace zakirov
{
  double * get_data(std::istream & in);
}

#endif
