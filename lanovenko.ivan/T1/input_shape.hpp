#ifndef INPUT_SHAPE_HPP
#define INPUT_SHAPE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace lanovenko
{
  void getPoints(size_t, double*, point_t*);
  Shape* inputRectangle(const char str[]);
  Shape* inputTriangle(const char str[]);
  Shape* inputDiamond(const char str[]);
  Shape* inputParallelogram(const char str[]);
}

#endif
