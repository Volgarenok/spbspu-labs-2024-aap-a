#ifndef SPECIFIC_OUTPUT_HPP
#define SPECIFIC_OUTPUT_HPP
#include <iostream>
#include "base-types.hpp"
#include "composite_shape.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  void frameOutput(rectangle_t a, std::ostream &out = std::cout);
  std::ostream & framesOut(CompositeShape &cmp, std::ostream &out = std::cout);
}
#endif
