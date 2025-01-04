#ifndef CREATECOMMAND_HPP
#define CREATECOMMAND_HPP
#include <cstddef>
#include <iostream>
#include "shape.hpp"

namespace duhanina
{
  void createScale(std::istream& in, size_t shapeCount, double& scalingFactor, point_t& point);
  void createShape(const std::string& shapeType, Shape** shapes, size_t& shapeCount);
}

#endif
