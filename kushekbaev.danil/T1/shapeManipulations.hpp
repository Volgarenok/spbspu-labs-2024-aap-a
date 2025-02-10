#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

namespace kushekbaev
{
  double getTotalArea(const size_t shapeCounter, CompositeShape** compShape);
  void scaleAll(const size_t shapeCounter, point_t scalePoint, double scaleCoeff, CompositeShape** compShape);
  void scaleSafe(const size_t shapeCounter, point_t scalePoint, double scaleCoeff, CompositeShape** compShape);
  void outputCoord(std::ostream& output, CompositeShape** compShape);
  void clearMemory(const size_t shapeCounter, CompositeShape** compShape);
  void printFrameCoordinates(std::ostream& out, const CompositeShape* compShape);
}

#endif
