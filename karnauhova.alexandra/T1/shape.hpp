#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
#include <string>

class Shape{
public:
  virtual ~Shape() {}
  virtual double getArea();
  virtual void getFrameRect();
  virtual void move(double x, double y);
  virtual void move(point_t t);
private:
  std::string name_;
  rectangle_t rect_;
};
#endif
