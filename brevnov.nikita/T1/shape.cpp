#include "shape.hpp"
#include <iomanip>

void brevnov::destroy_shape(const Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
  delete shapes;
}

double brevnov::get_sum_area(const Shape ** shapes, size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}

void brevnov::scale_shape(const Shape** shapes, size_t count, point_t scale_p, double ratio)
{
  for (size_t i = 0; i < count; ++i)
  {
    point_t before_scale = shapes[i]->getFrameRect().pos_;
    shapes[i]->move(scale_p);
    point_t after_scale = shapes[i]->getFrameRect().pos_;
    point_t movement = {(after_scale.x_ - before_scale.x_) * ratio, (after_scale.y_ - before_scale.y_) * ratio};
    shapes[i]->scale(ratio);
    shapes[i]->move(-movement.x_, -movement.y_);
  }
}

void brevnov::print_frame_coordinates(const Shape** shapes, size_t count, std::ostream & out)
{
  for (size_t i = 0; i < count; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    double leftx = frame.pos_.x_ - frame.width_ / 2.0;
    double lefty = frame.pos_.y_ - frame.height_ / 2.0;
    double rightx = frame.pos_.x_ + frame.width_ / 2.0;
    double righty = frame.pos_.y_ + frame.height_ / 2.0;
    out << leftx << " " << lefty << " " <<  rightx << " " << righty;
  }
}
