#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
#include <cstddef>
namespace alymova
{
  struct Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double shift_x, double shift_y) = 0;
    void scale(double ratio);
    virtual void unsafeScale(double ratio) = 0;
    virtual Shape* clone() const = 0;
  };
  void scale(Shape** shapes, size_t size, point_t s, double ratio);
  void unsafeScale(Shape** shapes, size_t size, point_t s, double ratio);
  void checkRatioScale(double ratio);

  bool isRectanglurTriangle(point_t p1, point_t p2, point_t p3) noexcept;
  double getVector(point_t p1, point_t p2) noexcept;
}
#endif
