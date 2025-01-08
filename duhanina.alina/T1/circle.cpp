#include "circle.hpp"
#include <stdexcept>

duhanina::Circle::Circle(const point_t& pos, double radius):
  ellipses_{}
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Error in parameters");
  }
  double cutRad = radius / NUM_PARTS;
  for (size_t i = 0; i < NUM_PARTS; ++i)
  {
    ellipses_[i] = Ellipse(pos, cutRad * (i + 1), cutRad * (i + 1));
  }
}

double duhanina::Circle::getArea() const
{
  return ellipses_[NUM_PARTS - 1].getArea();
}

duhanina::rectangle_t duhanina::Circle::getFrameRect() const
{
  return ellipses_[NUM_PARTS - 1].getFrameRect();
}

void duhanina::Circle::move(const point_t& newPos)
{
  for (size_t i = 0; i < NUM_PARTS; ++i)
  {
    ellipses_[i].move(newPos);
  }
}

void duhanina::Circle::move(double dx, double dy)
{
  for (size_t i = 0; i < NUM_PARTS; ++i)
  {
    ellipses_[i].move(dx, dy);
  }
}

void duhanina::Circle::scale(double k)
{
  for (size_t i = 0; i < NUM_PARTS; ++i)
  {
    ellipses_[i].scale(k);
  }
}
