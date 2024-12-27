#ifndef SHAPECREATION_HPP
#define SHAPECREATION_HPP

#include <iostream>
#include "shape.hpp"

namespace kushekbaev
{
  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff);
}

#endif
