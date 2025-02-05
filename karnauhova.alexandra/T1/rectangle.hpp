#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace karnauhova
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t& x4, const point_t& x2);
    void move(double x, double y) override;
    void move(const point_t& t) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scale(double k) override;
    Shape* clone() const override;
  private:
    point_t x2_;
    point_t x4_;
  };
}

#endif
