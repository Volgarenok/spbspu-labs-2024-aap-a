#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

ivanova::point_t ivanova::Diamond::findTop(point_t a, point_t b, point_t c)
{
  if (!(center_ == a))
  {
    return findTop(b, c, a);
  }
  if (b.x != center_.x)
  {
    return findTop(a, c, b);
  }
  if (b.y > center_.y)
  {
    return b;
  }
  return {center_.x, center_.y + (center_.y - b.y)};
}

ivanova::point_t ivanova::Diamond::findLeft(point_t a, point_t b, point_t c)
{
  if (!(center_ == a))
  {
    return findLeft(b, c, a);
  }
  if (b.y != center_.y)
  {
    return findLeft(a, c, b);
  }
  if (b.x < center_.x)
  {
    return b;
  }
  return {center_.x - (b.x - center_.x), center_.y};
}

bool ivanova::Diamond::isCenter(point_t check, point_t a, point_t b)
{
  return (check.x == a.x && check.y == b.y) || (check.x == b.x && check.y == a.y);
}

ivanova::point_t ivanova::Diamond::findCenter(point_t a, point_t b, point_t c)
{
  if (isCenter(a, b, c))
  {
    return a;
  }
  if (isCenter(b, a, c))
  {
    return b;
  }
  if (isCenter(c, a, b))
  {
    return c;
  }
  throw std::invalid_argument("Wrong format");
}

ivanova::Diamond::Diamond(point_t a, point_t b, point_t c)
{
  if (a == b || a == c || b == c)
  {
    throw std::invalid_argument("Some points are same");
  }
  center_ = findCenter(a, b, c);
  left_ = findLeft(a, b, c);
  top_ = findTop(a, b , c);
}

double ivanova::Diamond::getArea() const
{
  double d1 = std::fabs(top_.y - center_.y) * 2;
  double d2 = std::fabs(left_.x - center_.x) * 2;
  return (d1 * d2) / 2;
}

ivanova::rectangle_t ivanova::Diamond::getFrameRect() const
{
  double height = std::fabs(top_.y - center_.y) * 2;
  double width = std::fabs(left_.x - center_.x) * 2;
  return { width, height, center_ };
}

void ivanova::Diamond::move(point_t point)
{
  double moveX = point.x - center_.x;
  double moveY = point.y - center_.y;
  move(moveX, moveY);
}

void ivanova::Diamond::move(double x, double y)
{
  center_ = {center_.x + x, center_.y + y};
  top_ = {top_.x + x, top_.y + y};
  left_ = {left_.x + x, left_.y + y};
}

void ivanova::Diamond::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Scale ratio must be positive.");
  }
  point_t cur_center = center_;
  move({0, 0});
  top_.y *= ratio;
  left_.x *= ratio;
  move(cur_center);
}
