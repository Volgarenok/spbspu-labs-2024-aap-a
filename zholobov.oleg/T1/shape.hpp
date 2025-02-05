#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>
#include <stdexcept>

#include "base-types.hpp"

namespace zholobov {

  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double k)
    {
      if (k <= 0.0) {
        throw std::out_of_range("Invalid scale factor");
      }
      scale_no_check(k);
    }
    virtual void scale_no_check(double k) = 0;
    virtual Shape* clone() const = 0;
  };

}

#endif
