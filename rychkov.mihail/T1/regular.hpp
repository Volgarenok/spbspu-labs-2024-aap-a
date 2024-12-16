#ifndef REGULAR_HPP
#define REGULAR_HPP

#include <cstddef>
#include "shape.hpp"

namespace rychkov
{
  class Regular: public Shape
  {
  public:
    Regular() = delete;
    Regular(point_t center, size_t nSides, double sideLength);
    Regular(point_t p1, point_t p2, point_t p3);

    virtual double getArea() const noexcept override;
    virtual rectangle_t getFrameRect() const noexcept override;
    virtual void move(point_t destination) noexcept override;
    virtual void move(double deltaX, double deltaY) noexcept override;
    virtual void scale(double coef) override;
  private:
    point_t center_;
    size_t nSides_;
    double sideLength_;
  };
}

#endif
