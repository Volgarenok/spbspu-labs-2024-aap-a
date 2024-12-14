#ifndef GETSHAPEINFO_HPP
#define GETSHAPEINFO_HPP
#include <iostream>
#include <cstddef>
#include "shape.hpp"
namespace dribas
{
  size_t getShapeInfo(std::istream & input, Shape ** myShapes);
  void clear(Shape ** myshape);
}
#endif