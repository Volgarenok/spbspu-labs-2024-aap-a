#ifndef MAKE_SHAPE_HPP
#define MAKE_SAHPE_HPP
#include "shape.hpp"
#include <iostream>
namespace petrov
{
  Shape * makeShape(std::istream & in);
  Shape * makeRectangle(std::istream & in);
  Shape * makeTriangle(std::istream & in);
  Shape * makeConcave(std::istream & in);
}
#endif