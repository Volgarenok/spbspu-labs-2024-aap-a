#ifndef SPECIFIC_OUTPUT_HPP
#define SPECIFIC_OUTPUT_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  void frameOutput(rectangle_t a, std::ostream &out = std::cout);
  std::ostream & framesOut(Shape **shapes, size_t size, std::ostream &out = std::cout);
}
#endif
