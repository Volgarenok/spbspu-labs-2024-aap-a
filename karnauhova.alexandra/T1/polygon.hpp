#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>
class Polygon: public Shape
{
public:
  Polygon(point_t* points, size_t count): points_(points), count_(count)
  {}
  void move(double x, double y);
  void move(point_t t);
  double getArea();
  rectangle_t getFrameRect();
  void scale(point_t t, double k);
  ~Polygon() {}
private:
  point_t* points_;
  size_t count_;
};

#endif
