#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace brevnov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t left, point_t right);
    ~Rectangle();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t new_centre) override;
    void move(double dx, double dy) override;
    void scale(double n) override;
  private:
    point_t left;
    point_t right;
  };
}
#endif
