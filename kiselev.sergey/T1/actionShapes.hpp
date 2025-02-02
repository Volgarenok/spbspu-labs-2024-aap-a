#ifndef ACTIONSHAPES_HPP
#define ACTIONSHAPES_HPP
#include <ostream>
#include "composite-shape.hpp"
namespace kiselev
{
  std::ostream& printInfo(std::ostream& output, const CompositeShape& cmp);
}
#endif
