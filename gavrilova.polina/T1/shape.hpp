#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace gavrilova {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(const point_t& p) noexcept = 0;
    virtual void move(double x, double y) noexcept = 0;
    virtual void scale(double k) = 0;
    virtual Shape* clone() const = 0;
    
  };
}
#endif
