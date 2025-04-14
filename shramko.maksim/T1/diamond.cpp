#include "diamond.hpp"
#include "triangle.hpp"
#include <stdexcept>

shramko::Diamond::Diamond(point_t one, point_t two, point_t three):
  triangle_(one, two, three)
{
  double A = distance(one, two);
  double B = distance(two, three);
  double C = distance(three, one);

  double max_side = std::max(A, std::max(B, C));
  if (A == max_side)
  {
    center_ = three;
    if (std::abs((one.x - center_.x) * (two.x - center_.x)) > 10e-6)
    {
      throw std::invalid_argument("invalid diamond\n");
    }
  }
  else if (B == max_side)
  {
    center_ = one;
    if (std::abs((three.x - center_.x) * (two.x - center_.x)) > 10e-6)
    {
      throw std::invalid_argument("invalid diamond\n");
    }
  }
  else if (C == max_side)
  {
    center_ = two;
    if (std::abs((one.y - center_.y) * (three.y - center_.y)) > 10e-6)
    {
      throw std::invalid_argument("invalid diamond\n");
    }
  }
}

double shramko::Diamond::getArea() const
{
  return triangle_.getArea() * 4;
}

shramko::rectangle_t shramko::Diamond::getFrameRect() const
{
  double x_max = std::max(triangle_.one_.x, std::max(triangle_.two_.x,triangle_.three_.x));
  double x_min = std::min(triangle_.one_.x, std::min(triangle_.two_.x,triangle_.three_.x));
  double y_max = std::max(triangle_.one_.y, std::max(triangle_.two_.y,triangle_.three_.y));
  double y_min = std::min(triangle_.one_.y, std::min(triangle_.two_.y,triangle_.three_.y));

  rectangle_t rectFrame;
  rectFrame.pos = center_;
  if (x_max != center_.x)
  {
    rectFrame.width = (x_max - center_.x) * 2;
  }
  else
  {
    rectFrame.width = (center_.x - x_min) * 2;
  }
  if (y_max != center_.y)
  {
    rectFrame.height = (y_max - center_.y) * 2;
  }
  else
  {
    rectFrame.height = (center_.y - y_min) * 2;
  }

  return rectFrame;
}

void shramko::Diamond::move(double x, double y)
{
  triangle_.move(x, y);
  center_.x += x;
  center_.y += y;
}

void shramko::Diamond::scale(double k)
{
  triangle_.scale(k);
}
