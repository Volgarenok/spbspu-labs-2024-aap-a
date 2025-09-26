#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace maslovskiy
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t vertexA, point_t vertexB, point_t vertexC);
    double getArea() const override;
    point_t getCentroid() const;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t vertexA_;
    point_t vertexB_;
    point_t vertexC_;
  };
}

#endif
