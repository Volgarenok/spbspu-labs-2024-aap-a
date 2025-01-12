#include "circle.hpp"
#include <stdexcept>
#include <cmath>
#include "destroy.hpp"
#include "ellipse.hpp"

duhanina::Circle::Circle(const point_t& pos, double radius):
  count_(9),
  ellipses_(new Shape*[count_])
{
  if (radius <= 0)
  {
    delete[] ellipses_;
    throw std::invalid_argument("Error in parameters");
  }
  double r1 = std::sqrt(radius * radius / count_);
  for (size_t i = 0; i < count_; ++i)
  {
    ellipses_[i] = new Ellipse(pos, r1 * std::sqrt(i + 1), r1 * std::sqrt(i + 1));
  }
}

duhanina::Circle::~Circle()
{
  destroy(ellipses_, count_);
  delete[] ellipses_;
}

double duhanina::Circle::getArea() const
{
  return ellipses_[count_ - 1]->getArea();
}

duhanina::rectangle_t duhanina::Circle::getFrameRect() const
{
  return ellipses_[count_ - 1]->getFrameRect();
}

void duhanina::Circle::move(const point_t& newPos)
{
  for (size_t i = 0; i < count_; ++i)
  {
    ellipses_[i]->move(newPos);
  }
}

void duhanina::Circle::move(double dx, double dy)
{
  for (size_t i = 0; i < count_; ++i)
  {
    ellipses_[i]->move(dx, dy);
  }
}

void duhanina::Circle::scale(double k)
{
  for (size_t i = 0; i < count_; ++i)
  {
    ellipses_[i]->scale(k);
  }
}
