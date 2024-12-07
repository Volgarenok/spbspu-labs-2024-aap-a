#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "Shape.hpp"
#include <cmath>
struct Rectangle: public Shape
{
  Rectangle(const point_t& ll, const point_t& ur):
    low_left_(ll),
    upp_right_(ur),
    width_(upp_right_.getX() - low_left_.getX()),
    height_(upp_right_.getY() - low_left_.getY()),
    pos_(point_t((low_left_.getX() + width_ / 2), (upp_right_.getY() - height_ / 2)))
  {}
  double getArea() override
  {
    return width_ * height_;
  }
  rectangle_t getFrameRect() override
  {
    return rectangle_t(width_, height_);
  }
  void move(double shift_x, double shift_y) override
  {
    point_t shift_point(shift_x, shift_y);
    pos_ += shift_point;
    low_left_ += shift_point;
    upp_right_ += shift_point;
  }
  void move(point_t point) override
  {
    double shift_x = point.getX() - pos_.getX();
    double shift_y = point.getY() - pos_.getY();
    move(shift_x, shift_y);
  }
//private:
  point_t low_left_, upp_right_;
  double width_, height_;
  point_t pos_;
};
#endif