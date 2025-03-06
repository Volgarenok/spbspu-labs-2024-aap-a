#include "diamond.hpp"
#include "triangle.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

shramko::Diamond::Diamond(point_t one, point_t two, point_t three):
  triangles(8),
  one_(one),
  two_(two),
  three_(three)
{
  point_t mid1 = {(one.x + two.x)/2, (one.y + two.y)/2};
  point_t mid2 = {(one.x + three.x)/2, (one.y + three.y)/2};
  point_t mid3 = {(two.x + three.x)/2, (two.y + three.y)/2};
  point_t midCent = {(mid1.x + mid2.x + mid3.x)/3, (mid1.y + mid2.y + mid3.y)/3};

  triangles[0] = Triangle(one, mid1, midCent);
  triangles[1] = Triangle(mid1, two, midCent);
  triangles[2] = Triangle(two, mid3, midCent);
  triangles[3] = Triangle(mid3, one, midCent);
  triangles[4] = Triangle(one, mid1, mid2);
  triangles[5] = Triangle(mid1, two, mid2);
  triangles[6] = Triangle(two, mid3, mid2);
  triangles[7] = Triangle(mid3, one, mid2);
}

double shramko::Diamond::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < 8; ++i)
  {
    area += triangles[i].getArea();
  }

  return area;
}

shramko::rectangle_t shramko::Diamond::getFrameRect() const
{
  rectangle_t rectFrame;

  double xMin = std::min({one_.x, two_.x, three_.x});
  double xMax = std::max({one_.x, two_.x, three_.x});
  double yMin = std::min({one_.y, two_.y, three_.y});
  double yMax = std::max({one_.y, two_.y, three_.y});

  rectFrame.width = xMax - xMin;
  rectFrame.height = yMax - yMin;

  rectFrame.pos.x = (xMin + xMax) / 2.0;
  rectFrame.pos.y = (yMin + yMax) / 2.0;

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

  point_t cent = {(one_.x + two_.x + three_.x)/3, (one_.y + two_.y + three_.y)/3};

  one_.x = cent.x + (one_.x - cent.x) * k;
  one_.y = cent.y + (one_.y - cent.y) * k;

  two_.x = cent.x + (two_.x - cent.x) * k;
  two_.y = cent.y + (two_.y - cent.y) * k;

  three_.x = cent.x + (three_.x - cent.x) * k;
  three_.y = cent.y + (three_.y - cent.y) * k;
}
