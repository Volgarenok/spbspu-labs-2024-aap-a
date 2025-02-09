#include "point.hpp"
#include <cmath>
double karnauhova::getDistance(const point_t& a, const point_t& b)
{
  return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

bool karnauhova::isEqual(const point_t& a, const point_t& b)
{
  return ((a.x == b.x) && (a.y == b.y));
}

karnauhova::rectangle_t karnauhova::frameRect(const Shape* const* shapes, size_t count)
{
  double min_x = shapes[0]->getFrameRect().pos.x - shapes[0]->getFrameRect().width / 2;
  double max_x = shapes[0]->getFrameRect().pos.x + shapes[0]->getFrameRect().width / 2;
  double min_y = shapes[0]->getFrameRect().pos.y - shapes[0]->getFrameRect().height / 2;
  double max_y = shapes[0]->getFrameRect().pos.y + shapes[0]->getFrameRect().height / 2;
  for (size_t i = 1; i < count; i++)
  {
    rectangle_t rectangl = shapes[i]->getFrameRect();
    min_x = std::fmin(min_x, rectangl.pos.x - (rectangl.width / 2));
    min_y = std::fmin(min_y, rectangl.pos.y - (rectangl.height / 2));
    max_x = std::fmax(max_x, rectangl.pos.x + (rectangl.width / 2));
    max_y = std::fmax(max_y, rectangl.pos.y + (rectangl.height / 2));
  }
  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos{min_x + (width / 2), min_y + (height / 2)};
  rectangle_t rect{width, height, pos};
  return rect;
}


