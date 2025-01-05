#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace kushekbaev
{
  double getTotalArea(const Shape** capacity, const size_t shapeCounter);
  void scaleEverything(Shape** capacity, size_t shapeCounter, point_t scalePoint, double scaleCoeff);
  void coordOutput(const Shape** capacity, const size_t shapeCounter, std::ostream& output);
  void clearMemory(Shape** capacity, size_t shapeCounter);
}

#endif
