#ifndef OUTPUTRES_HPP
#define OUTPUTRES_HPP
#include <iostream>
#include "shape.hpp"
namespace bocharov
{
  void outputRes(std::ostream & output, const Shape * const * shapes, size_t shapeSize);
}
#endif
