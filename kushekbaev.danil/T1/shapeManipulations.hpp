#ifndef SHAPEMANIPULATIONS_HPP
#define SHAPEMANIPULATIONS_HPP

#include <istream>
#include "rectangle.hpp"

namespace kushekbaev
{
  Rectangle* createRectangle(std::istream& input);
  void scaleEverything(size_t shapeCounter, Shape** capacity, point_t scaler, double V);
  double getTotalArea(Shape** capacity, size_t shapeCounter);
  void coordOutput(Shape** capacity, size_t shapeCounter);
  void clearMemory(Shape** capacity, size_t shapeCounter);
}

#endif
