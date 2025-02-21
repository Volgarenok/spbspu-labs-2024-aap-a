#ifndef SHAPE_ACTIONS
#define SHAPE_ACTIONS

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace evstyunichev
{
  void destroy_shapes(Shape **, size_t);
  void makeScale(Shape **, std::istream &, size_t, double &);
}

#endif