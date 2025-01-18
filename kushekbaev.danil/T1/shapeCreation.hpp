#ifndef SHAPECREATION_HPP
#define SHAPECREATION_HPP

#include <iostream>
#include "shape.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& input);
  Concave* makeConcave(std::istream& input);
  Parallelogram* makeParallelogram(std::istream& input);
  Diamond* makeDiamond(std::istream& input);
  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff);
}

#endif
