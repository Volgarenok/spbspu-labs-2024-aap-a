#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

namespace
{
  bool isCorrectDiamond(guseynov::point_t a, guseynov::point_t b, guseynov::point_t c)
  {
    if ((a.x == b.x && a.y == b.y) || (a.x == c.x && a.y == c.y) || (b.x == c.x && b.y == c.y))
    {
      return false;
    }
    if ((a.x != b.x && a.x != c.x && b.x != c.x) || (a.y != b.y && a.y != c.y && b.y != c.y))
    {
      return false;
    }
    return true;
  }

  guseynov::point_t getCenter(guseynov::point_t a, guseynov::point_t b, guseynov::point_t c)
  {
    if ((a.x == b.x && a.y == c.y) || (a.y == b.y && a.x == c.x))
    {
      return a;
    }
    if ((b.x == a.x && b.y == c.y) || (b.y == a.y && b.x == c.x))
    {
      return b;
    }
    return c;
  }

  guseynov::point_t getHorizontal(guseynov::point_t center, guseynov::point_t a, guseynov::point_t b, guseynov::point_t c)
  {
    if (center.x != a.x && center.y == a.y)
    {
      return a;
    }
    if (center.x != b.x && center.y == b.y)
    {
      return b;
    }
    return c;
  }

  guseynov::point_t getVertical(guseynov::point_t center, guseynov::point_t horizontal,
    guseynov::point_t a, guseynov::point_t b, guseynov::point_t c)
  {
    if ((a.x != center.x || a.y != center.y) && (a.x != horizontal.x || a.y != horizontal.y))
    {
      return a;
    }
    if ((b.x != center.x || b.y != center.y) && (b.x != horizontal.x || b.y != horizontal.y))
    {
      return b;
    }
    return c;
  }
}

guseynov::Diamond::Diamond(point_t a, point_t b, point_t c):
  center_(getCenter(a, b, c)),
  horizontal_(getHorizontal(center_, a, b, c)),
  vertical_(getVertical(center_, horizontal_, a, b, c))
{
  if (!isCorrectDiamond(a, b, c))
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }
}

double guseynov::Diamond::getArea() const noexcept
{
  return std::fabs((horizontal_.x - center_.x) * (vertical_.y - center_.y) * 2);
}

guseynov::rectangle_t guseynov::Diamond::getFrameRect() const noexcept
{
  double width = std::fabs(horizontal_.x - center_.x) * 2;
  double height = std::fabs(vertical_.y - center_.y) * 2;
  return {width, height, center_};
}

void guseynov::Diamond::move(point_t new_center) noexcept
{
  double xOffset = horizontal_.x - center_.x;
  double yOffset = vertical_.y - center_.y;
  center_ = new_center;
  horizontal_ = {center_.x + xOffset, center_.y};
  vertical_ = {center_.x, center_.y + yOffset};
}

void guseynov::Diamond::move(double dx, double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
  horizontal_.x += dx;
  horizontal_.y += dy;
  vertical_.x += dx;
  vertical_.y += dy;
}

void guseynov::Diamond::scaleWithoutCheck(double n)
{
  horizontal_.x = center_.x + (horizontal_.x - center_.x) * n;
  vertical_.y = center_.y + (vertical_.y - center_.y) * n;
}

guseynov::Shape * guseynov::Diamond::clone() const
{
  return new Diamond(center_, horizontal_, vertical_);
}
