#ifndef OUTPUTRES_HPP
#define OUTPUTRES_HPP

#include <iostream>
#include "shape.hpp"

namespace dribas
{
  void outputRes(std::ostream & output, const Shape* const* Shape, const size_t shapeSize);
}

#endif
