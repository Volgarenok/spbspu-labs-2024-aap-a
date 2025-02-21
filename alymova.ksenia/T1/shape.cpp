#include "shape.hpp"
#include <stdexcept>
#include <cmath>
#include <cstddef>
#include <limits>
void alymova::Shape::scale(double ratio)
{
  checkRatioScale(ratio);
  unsafeScale(ratio);
}
void alymova::scale(CompositeShape& shapes, const point_t& s, double ratio)
{
  checkRatioScale(ratio);
  unsafeScale(shapes, s, ratio);
}
void alymova::unsafeScale(CompositeShape& shapes, const point_t& s, double ratio) noexcept
{
  for (size_t i = 0; i < shapes.size(); i++)
  {
    rectangle_t old_rectangle = shapes[i]->getFrameRect();
    shapes[i]->move(s);
    point_t shift_point = {getShiftFrameRect(old_rectangle, shapes[i]->getFrameRect())};
    shapes[i]->unsafeScale(ratio);
    shift_point *= ratio;
    shapes[i]->move(-shift_point.x, -shift_point.y);
  }
}
void alymova::checkRatioScale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  return;
}

constexpr double inaccuracy = 0.0000000001;
double alymova::getVector(const point_t& p1, const point_t& p2) noexcept
{
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}
bool alymova::isRectanglurTriangle(const point_t& p1, const point_t& p2, const point_t& p3) noexcept
{
  return (std::abs(std::pow(getVector(p2, p3), 2) + std::pow(getVector(p1, p3), 2)
    - std::pow(getVector(p1, p2), 2)) < inaccuracy);
}
void alymova::changeFrameRect(rectangle_t& rect, double low_left_x_new, double low_left_y_new,
  double upp_right_x_new, double upp_right_y_new)
{
  double low_left_x = std::min(getLowLeftFrameRect(rect).x, low_left_x_new);
  double low_left_y = std::min(getLowLeftFrameRect(rect).y, low_left_y_new);
  double upp_right_x = std::max(getUppRightFrameRect(rect).x, upp_right_x_new);
  double upp_right_y = std::max(getUppRightFrameRect(rect).y, upp_right_y_new);
  rect = getFrameRectByAngles(low_left_x, low_left_y, upp_right_x, upp_right_y);
}
alymova::rectangle_t alymova::getMaxFrameRect()
{
  double low_left_x = std::numeric_limits< double >::max();
  double low_left_y = std::numeric_limits< double >::max();
  double upp_right_x = std::numeric_limits< double >::min();
  double upp_right_y = std::numeric_limits< double >::min();
  return getFrameRectByAngles(low_left_x, low_left_y, upp_right_x, upp_right_y);
}
alymova::rectangle_t alymova::getFrameRectByAngles(double low_left_x, double low_left_y,
  double upp_right_x, double upp_right_y)
{
  double width = upp_right_x - low_left_x;
  double height = upp_right_y - low_left_y;
  point_t pos = {(upp_right_x - width / 2.0), (upp_right_y - height / 2.0)};
  return {width, height, pos};
}
