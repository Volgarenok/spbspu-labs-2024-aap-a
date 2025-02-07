#ifndef POINT_HPP
#define POINT_HPP
#include <cstddef>
#include "shape.hpp"
namespace karnauhova
{
  double getDistance(const point_t& a,const point_t& b);
  bool isEqual(const point_t& a, const point_t& b);
  rectangle_t frameRect(Shape** shapes, size_t count);
}
#endif
