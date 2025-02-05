#ifndef BIG_RECTANGLE_HPP
#define BIG_RECTANGLE_HPP
#include "base-types.hpp"
#include "ellipse.hpp"
namespace brevnov
{
  class BigRectangle final: public Shape
  {
  public:
    BigRectangle(point_t left, point_t right);
    ~BigRectangle();
    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    void move(point_t new_centre) noexcept;
    void move(double dx, double dy) noexcept;
    void scale(double n);
  private:
    Ellipse ** shapes_;
    point_t left_;
    point_t right_;
  };
}
#endif
