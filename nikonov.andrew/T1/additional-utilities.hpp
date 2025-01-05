#ifndef ADDITIONAL_UTILITIES_HPP
#define ADDITIONAL_UTILITIES_HPP
#include <cstdlib>
#include <istream>
#include <ostream>
#include "shape.hpp"
namespace nikonov
{
  void fillShapeCollection(std::istream &input, std::ostream &out, Shape **collection, size_t &cnt);
  void destoy(Shape **collection, size_t cnt);
  void ispScale(Shape *shp, double x, double y, double k);
  void scaleCollection(Shape **collection, size_t cnt, double x, double y, double k);
  double getCollectionArea(Shape **collection, size_t cnt);
  void outputCollection(std::ostream &out, Shape **collection, size_t cnt);
  void processCollection(std::istream &input, std::ostream &out, Shape **collection, size_t cnt);
  double getSegmentLength(const point_t &a, const point_t &b);
  void scalePoint(point_t &pt, point_t &center, double k);
}
#endif
