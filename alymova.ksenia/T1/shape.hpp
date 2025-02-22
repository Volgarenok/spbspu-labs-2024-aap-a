#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "composite-shape.hpp"
namespace alymova
{
  struct Shape
  {
    virtual ~Shape() = default;
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(const point_t& point) noexcept = 0;
    virtual void move(double shift_x, double shift_y) noexcept = 0;
    void scale(double ratio);
    virtual void unsafeScale(double ratio) noexcept = 0;
    virtual Shape* clone() const = 0;
  };
  void scale(CompositeShape& shapes, const point_t& s, double ratio);
  void unsafeScale(CompositeShape& shapes, const point_t& s, double ratio) noexcept;
  void checkRatioScale(double ratio);

  bool isRectanglurTriangle(const point_t& p1, const point_t& p2, const point_t& p3) noexcept;
  double getVector(const point_t& p1, const point_t& p2) noexcept;

  void changeFrameRect(rectangle_t& rect, double low_left_x_new, double low_left_y_new,
    double upp_right_x_new, double upp_right_y_new);
  rectangle_t getMaxFrameRect();
  rectangle_t getFrameRectByAngles(double low_left_x, double low_left_y,
    double upp_right_x, double upp_right_y);
}
#endif
