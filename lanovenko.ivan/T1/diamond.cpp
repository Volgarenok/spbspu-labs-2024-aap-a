#include "diamond.hpp"
#include <stdexcept>

bool validTriangle(lanovenko::point_t center, lanovenko::point_t vertical, lanovenko::point_t horizontal)
{
  bool valid = false;
  lanovenko::point_t points[3] = { center, vertical, horizontal };
  for (size_t i = 0; i < 3; i++)
  {
    lanovenko::point_t candidate = points[i];
    lanovenko::point_t other1 = points[(i + 1) % 3];
    lanovenko::point_t other2 = points[(i + 2) % 3];
    if (candidate.x == other1.x && candidate.y == other2.y)
    {
      valid = true;
      center = candidate;
      vertical = other1;
      horizontal = other2;
      break;
    }
    if (candidate.x == other2.x && candidate.y == other1.y)
    {
      valid = true;
      center = candidate;
      vertical = other2;
      horizontal = other1;
      break;
    }
  }
  if (!valid)
  {
    return false;
  }
  return true;
}

lanovenko::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  first_(p1, p2, p3),
  second_(p1, p2, p3)
{
  bool valid = validTriangle(p1, p2, p3);
  if (!valid)
  {
    throw std::invalid_argument("Wrond Diamond parametrs!\n");
  }
}

double lanovenko::Diamond::getArea() const
{
  return (first_.getArea() + second_.getArea()) * 2;
}

lanovenko::rectangle_t lanovenko::Diamond::getFrameRect() const
{
  double width = first_.getFrameRect().width + second_.getFrameRect().width;
  double heigth = first_.getFrameRect().height + second_.getFrameRect().height;
  point_t triangleCenter = first_.getFrameRect().pos;
  point_t diamondCenter = { triangleCenter.x + width / 4.0, triangleCenter.y - heigth / 4.0 };
  return { width, heigth, diamondCenter };
}

void lanovenko::Diamond::move(point_t p)
{
  first_.move(p);
  second_.move(p);
}

void lanovenko::Diamond::move(double dx, double dy)
{
  first_.move(dx, dy);
  second_.move(dx, dy);
}

void lanovenko::Diamond::unsafeScale(double k)
{
  first_.scale(k);
  second_.scale(k);
}

