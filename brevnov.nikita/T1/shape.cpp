#include "shape.hpp"
#include <iomanip>
#include <stdexcept>

void brevnov::move_point(double dx, double dy, brevnov::point_t &point)
{
  point.x += dx;
  point.y += dy;
}

void brevnov::Shape::check_scale(double n)
{
  if (n <= 0.0)
  {
    throw std::invalid_argument("Not  positive number");
  }
  scale(n);
}

void brevnov::destroy_shapes(brevnov::Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

double brevnov::get_sum_areas(const brevnov::Shape * const * shapes, size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}

void brevnov::scale_shapes(brevnov::Shape * const * shapes, size_t count, brevnov::point_t scale_p, double ratio)
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

void brevnov::find_frame_coordinates(brevnov::rectangle_t frame, std::ostream& out)
{
  double leftx = frame.pos.x - frame.width / 2.0;
  double lefty = frame.pos.y - frame.height / 2.0;
  double rightx = frame.pos.x + frame.width / 2.0;
  double righty = frame.pos.y + frame.height / 2.0;
  out << leftx << " " << lefty << " " <<  rightx << " " << righty;
}

void brevnov::print_frame_coordinates(const brevnov::Shape * const * shapes, size_t count, std::ostream & out)
{
  find_frame_coordinates(shapes[0]->getFrameRect(), out);
  for (size_t i = 1; i < count; ++i)
  {
    out << " ";
    find_frame_coordinates(shapes[i]->getFrameRect(), out);
  }
}
