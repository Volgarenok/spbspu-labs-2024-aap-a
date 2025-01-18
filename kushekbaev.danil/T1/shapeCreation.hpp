#ifndef SHAPECREATION_HPP
#define SHAPECREATION_HPP

#include <iostream>
#include "shape.hpp"

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& input);
  Concave* makeConcave(std::istream& input);
  Parallelogram* makeParallelogram(std::istream& input);
  Diamond* makeDiamond(std::istream& input);
  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff);
}

#endif
