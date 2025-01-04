#ifndef PRINTRESULT_HPP
#define PRINTRESULT_HPP
#include <ostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace duhanina
{
  void outFigures(std::ostream& out, const Shape* const* shapes, size_t i);

  template <typename T>
  double calcArea(const T* const* shapes, size_t shapeCount)
  {
    double totalArea = 0;
    for (size_t i = 0; i < shapeCount; ++i)
    {
      totalArea += shapes[i]->getArea();
    }
    return totalArea;
  }

  void printFiguresInfo(std::ostream& out, const Shape* const* shapes, size_t shapeCount);
  void processScaling(Shape* const* shapes, size_t shapeCount, point_t point, double scalingFactor);
}

#endif
