#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include "rectangle.hpp"
#include <cstddef>

namespace kushekbaev
{
  void scaleEverything(size_t shapeCounter, Shape** capacity, double scaleCoeff, point_t scalePoint);
  double getTotalArea(Shape** capacity, size_t shapeCounter);
  void coordOutput(Shape** capacity, size_t shapeCounter);
  void clearMemory(Shape** capacity, size_t shapeCounter);
}

#endif
