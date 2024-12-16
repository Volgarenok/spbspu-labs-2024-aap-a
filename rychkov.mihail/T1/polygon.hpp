#ifndef POLYGON_HPP
#define POLYGON_HPP

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
    point_t* vertexes_;
    size_t size_;
    point_t getCenter() const noexcept;
  };
}

#endif
