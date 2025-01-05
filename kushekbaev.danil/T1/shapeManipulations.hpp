#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace kushekbaev
{
  double getTotalArea(Shape** capacity, size_t shapeCounter);
  void scaleEverything(Shape** capacity, size_t shapeCounter, point_t scalePoint, double scaleCoeff, std::ostream& output);
  void coordOutput(Shape** capacity, size_t shapeCounter);
  void clearMemory(Shape** capacity, size_t shapeCounter);
}

#endif
