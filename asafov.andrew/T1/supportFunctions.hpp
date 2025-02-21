#ifndef SUPPORT_FUNCTIONS_HPP
#define SUPPORT_FUNCTIONS_HPP
#include "shape.hpp"
#include <iostream>
namespace asafov
{
  void scalePoint(asafov::point_t& point, asafov::point_t fpoint, double scale);
  point_t getPoint(std::istream& in);
  void isotropicScale(Shape* sh, point_t pos, double scale);
  void outputFrameRect(Shape* shape, std::ostream& out);
}
#endif
