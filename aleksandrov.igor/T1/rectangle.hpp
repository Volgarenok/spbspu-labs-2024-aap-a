#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& a, const point_t& b);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& centerPoint) override;
  void move(const double dx, const double dy) override;
  void scale(size_t k) override;
private:
  point_t a_;
  point_t b_;
};

#endif

