#include "shape.hpp"
#include <iomanip>

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
    result += shapes[i]->getArea();
  }
  return result;
}

void brevnov::scale_shape(Shape** shapes, size_t count, point_t scale_p, double ratio)
{
  for (size_t i = 0; i < count; ++i)
  {
    point_t before_scale = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scale_p);
    point_t after_scale = shapes[i]->getFrameRect().pos;
    point_t movement = {(after_scale.x - before_scale.x) * ratio, (after_scale.y - before_scale.y) * ratio};
    shapes[i]->scale(ratio);
    shapes[i]->move(-movement.x, -movement.y);
  }
}

void brevnov::print_frame_coordinates(Shape** shapes, size_t count, std::ostream & out)
{
  for (size_t i = 0; i < count; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    double leftx = frame.pos.x - frame.width / 2.0;
    double lefty = frame.pos.y - frame.height / 2.0;
    double rightx = frame.pos.x + frame.width / 2.0;
    double righty = frame.pos.y + frame.height / 2.0;
    out << " " << leftx << " " << lefty << " " <<  rightx << " " << righty;
  }
  out << "\n";
}


