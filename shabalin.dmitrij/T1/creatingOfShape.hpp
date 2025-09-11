#ifndef CREATINGOFSHAPE_HPP
#define CREATINGOFSHAPE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>


namespace shabalin
{
  void defineAndCreateShape(Shape **myShapes, size_t shapesCount, const char *sting);
  Shape * createParallelogram(const char *string);
  Shape * createRectangle(const char *string);
  Shape * createDiamond(const char *string);
  void extractDataForShape(const char *string, double *coordStorage, size_t pointsCount, size_t wordLen);
  void freeMem(Shape **myShapes, size_t shapesCount);
  void scaleForParAndDiam(rectangle_t dataOfFameRect, point_t &p1_, point_t &p2_, point_t &p3_, const double k);
}
#endif
