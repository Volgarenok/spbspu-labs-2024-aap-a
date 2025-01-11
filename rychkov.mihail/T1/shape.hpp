#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace rychkov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(point_t destination) noexcept = 0;
    virtual void move(double deltaX, double deltaY) noexcept = 0;
    void scale(double coef);
    virtual Shape* clone() const = 0;
  private:
    virtual void unsafeScale(double coef) noexcept = 0;
    friend void unsafeScale(Shape* shape, double coef, point_t scaleCenter) noexcept;
  };
  void scale(Shape* shape, double coef, point_t scaleCenter);
  void unsafeScale(Shape* shape, double coef, point_t scaleCenter) noexcept;
  void validateScaleCoefficient(double coef);
}

#endif
