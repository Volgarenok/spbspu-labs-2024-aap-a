#include "shape.hpp"

void brevnov::destroy_shape(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}

double  brevnov::get_sum_area(Shape ** shapes, size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shapes[i].getArea();
  }
  return result;
}

void brevnov::scale_shape(Shape** shapes, size_t count, point_t scale_p, double ratio)
{
  for (size_t i = 0; i < count; ++i)
  {
    point_t before_scale = shapes[i].getFrameRect().pos;
    shapes[i].move(scale_p);
    point_t after_scale = shapes[i].getFrameRect().pos;
    point_t movement = {(after_scale.x - before_scale.x) * retio, (after_scale.y - before_scale.y) * retio};
    shapes[i].scale(ratio);
    shapes[i].move(-vector.x, -vector.y);
  }
}

void brevnov::print_frame_coordinates(Shape** shapes, size_t count, std::ostream & out)
{
  for (size_t i = 0; i < count; ++i)
  {
    rectangle_t frame = shapes[i].getFrameRect();
    double leftx = frame.pos.x - frame.width / 2;
    double lefty = frame.pos.y - frame.height / 2;
    double rightx = frame.pos.x + frame.width / 2;
    double righty = frame.pos.y + frame.height / 2;
    out << " " << leftx << " " << lefty << " " <<  rightx << " " << righty;
  }
  out << "\n";
}


