#ifndef CREATECOMMAND_HPP
#define CREATECOMMAND_HPP
#include <cstddef>
#include <iostream>
#include "shape.hpp"

namespace duhanina
{
  void createScale(std::istream& in, Shape** shapes, size_t shapeCount);
  void createShape(const std::string& shapeType, Shape** shapes, size_t& shapeCount);
}

#endif
