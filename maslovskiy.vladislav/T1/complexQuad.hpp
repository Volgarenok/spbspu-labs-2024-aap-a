#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace maslovskiy
{
  class ComplexQuad : public Shape
  {
  public:
    ComplexQuad(point_t vertexA, point_t vertexB, point_t vertexC, point_t vertexD);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    point_t getCenterComplexQuad() const;

  private:
    point_t vertexA_;
    point_t vertexB_;
    point_t vertexC_;
    point_t vertexD_;
  };
}

#endif
