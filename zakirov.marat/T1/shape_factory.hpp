#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP
#include <istream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "polygon.hpp"
#include "shape.hpp"

namespace zakirov
{
  Rectangle * make_rectangle(std::istream & in);
  Circle * make_circle(std::istream & in);
  Ring * make_ring(std::istream & in);
  Polygon * make_polygon(std::istream & in);
  Shape * make_shape(std::istream & in, char * shape_name);
}

#endif
