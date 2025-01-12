#ifndef ADDITIONAL_UTILITIES_HPP
#define ADDITIONAL_UTILITIES_HPP
#include <cstdlib>
#include <istream>
#include <ostream>
#include "composite-shape.hpp"
#include "shape.hpp"
namespace nikonov
{
  void fillShapeCollection(std::istream &input, std::ostream &out, CompositeShape &collection);
  void destoy(CompositeShape &collection);
  void ispScale(Shape *shp, double x, double y, double k);
  void scaleCollection(CompositeShape &collection, double x, double y, double k);
  void outputCollection(std::ostream &out, CompositeShape &collection);
  void processCollection(std::istream &input, std::ostream &out, CompositeShape &collection);
  double getSegmentLength(const point_t &a, const point_t &b);
  void scalePoint(point_t &pt, point_t &center, double k);
}
#endif
