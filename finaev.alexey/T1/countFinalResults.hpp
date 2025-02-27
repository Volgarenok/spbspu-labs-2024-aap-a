#ifndef COUNTFINALRESULTS_HPP
#define COUNTFINALRESULTS_HPP

#include "shape.hpp"
#include <fstream>

namespace finaev
{
  double getSumArea(const Shape* const* shapes, size_t size);
  void printFrameRect(std::ostream& out, const Shape* const* shapes, size_t size);
}

#endif
