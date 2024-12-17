#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace alymova
{
  struct Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double shift_x, double shift_y) = 0;
    virtual void scale(double ratio) = 0;
    virtual ~Shape() = default;
  };
  void scale(Shape** shapes, point_t s, double ratio);
  bool getRectanglurTriangle(point_t p1, point_t& p2, point_t& p3);
  double getVector(point_t p1, point_t p2);
}
#endif
