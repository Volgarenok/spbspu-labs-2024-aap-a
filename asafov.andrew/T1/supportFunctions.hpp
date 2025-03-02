#ifndef SUPPORT_FUNCTIONS_HPP
#define SUPPORT_FUNCTIONS_HPP
#include "shape.hpp"
#include <iostream>
namespace asafov
{
  void scalePoint(asafov::point_t& point, asafov::point_t fpoint, double scale);
  point_t getPoint(std::istream& in);
  double getTotalArea(asafov::Shape** shapes, size_t count);
  void getPoints(point_t* points, size_t size, std::istream& in);
  void isotropicScale(Shape* sh, point_t pos, double scale);
  void doUnsafeIsotropicScale(Shape* sh, point_t pos, double scale);
  void outputFrameRect(Shape* shape, std::ostream& out);
  double getPi();
  void increaseDelta(point_t& point, double dx, double dy);
  double getCenterDelta(double one, double two, double three);
  double getCenterDelta(double one, double two, double three, double four);
  double getLength(point_t one, point_t two);
}
#endif
