#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <stdexcept>

namespace gavrilova {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(const point_t& p) noexcept = 0;
    virtual void move(double x, double y) noexcept = 0;
    virtual void scale_without_check(double k) = 0;
    void scale(double k) {
      if (k <= 0) {
        throw std::logic_error("Коэффицент должен быть положительным");
      }
      scale_without_check(k);
    }
    virtual Shape* clone() const = 0;
  };
}
#endif
