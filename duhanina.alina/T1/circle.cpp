#include "circle.hpp"
#include <stdexcept>
#include <cmath>
#include "destroy.hpp"
#include "ellipse.hpp"
#include "movingPoint.hpp"

namespace
{
  duhanina::Shape** createArray(const duhanina::point_t& pos, double radius, size_t count)
  {
    if (radius <= 0)
    {
      throw std::invalid_argument("Error in parameters");
    }
    duhanina::Shape** ellipses = new duhanina::Shape*[count];
    double r1 = std::sqrt(radius * radius / count);
    for (size_t i = 0; i < count; ++i)
    {
      ellipses[i] = new duhanina::Ellipse(pos, r1 * std::sqrt(i + 1), r1 * std::sqrt(i + 1));
    }
    return ellipses;
  }
}

duhanina::Circle::Circle(const point_t& pos, double radius, size_t count):
  count_(count),
  ellipses_(createArray(pos, radius, count))
{}

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
  point_t pos = ellipses_[0]->getCenter();
  movePoint(pos, dx, dy);
  move(pos);
}

void duhanina::Circle::unsafeScale(double k) noexcept
{
  for (size_t i = 0; i < count_; ++i)
  {
    ellipses_[i]->unsafeScale(k);
  }
}

duhanina::point_t duhanina::Circle::getCenter() const
{
  return ellipses_[0]->getCenter();
}
