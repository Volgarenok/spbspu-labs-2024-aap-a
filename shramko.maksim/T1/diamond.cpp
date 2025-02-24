#include "diamond.hpp"
#include "triangle.hpp"
#include <stdexcept>
#include <cmath>

shramko::Diamond::Diamond(point_t one, point_t two, point_t three):
  triangles(new Triangle[8])
{
  triangles[0] = Triangle(one, {(one.x + two.x)/2, (one.y + two.y)/2}, three);
  triangles[1] = Triangle(one, two, three);
  triangles[2] = Triangle(one, two, three);
  triangles[3] = Triangle(one, two, three);
  triangles[4] = Triangle(one, two, three);
  triangles[5] = Triangle(one, two, three);
  triangles[6] = Triangle(one, two, three);
  triangles[7] = Triangle(one, two, three);
  triangles[8] = Triangle(one, two, three);
}

double shramko::Diamond::getArea() const
{
  return std::abs(one_.x - two_.x + one_.x - three_.x) * std::abs(one_.y - two_.y + one_.y - three_.y) * 2.0L;
}

shramko::rectangle_t shramko::Diamond::getFrameRect() const
{
  rectangle_t rectFrame;
  rectFrame.pos = one_;

  rectFrame.width = std::abs(three_.x - one_.x) * 2;
  rectFrame.height = std::abs(two_.y - one_.y) * 2;

  return rectFrame;
}

void shramko::Diamond::move(double x, double y)
{
  one_.x += x;
  one_.y += y;

  two_.x += x;
  two_.y += y;

  three_.x += x;
  three_.y += y;
}

void shramko::Diamond::move(point_t point)
{
  double xMove = point.x - one_.x;
  double yMove = point.y - one_.y;

  move(xMove, yMove);
}

void shramko::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Diamond scale err\n");
  }

  two_.y = (one_.y - two_.y) * k + one_.y;
  three_.x = (one_.x - three_.x) * k + one_.x;
}
