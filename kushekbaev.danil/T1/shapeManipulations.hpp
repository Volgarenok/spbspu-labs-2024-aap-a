#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace kushekbaev
{
  double getTotalArea(Shape** capacity, const size_t shapeCounter);
  void scaleTotal(Shape** capacity, const size_t shapeCounter, point_t scalePoint, double scaleCoeff);
  void scaleSafe(Shape** capacity, const size_t shapeCounter, point_t scalePoint, double scaleCoeff);
  void outputCoord(Shape** capacity, const size_t shapeCounter, std::ostream& output);
  void clearMemory(Shape** capacity, size_t shapeCounter);
}

#endif
