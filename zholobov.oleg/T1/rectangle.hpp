#ifndef RECTANGLE_HPP 
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape {
  rectangle_t rect_;

public:
  Rectangle();
  Rectangle(const point_t& a, const point_t& c);

  float getArea() override;
  rectangle_t getFrameRect() override;
  void move(point_t p) override;
  void move(float dx, float dy) override;
  void scale(float k) override;
};

#endif
