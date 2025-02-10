#ifndef COUNTFINALRESULTS_HPP
#define COUNTFINALRESULTS_HPP

#include "shape.hpp"
#include <fstream>

namespace finaev
{
  double getSumArea(Shape** shapes, const size_t size);
  void printFrameRect(std::ostream& out, Shape** shapes, const size_t size);
}

#endif
