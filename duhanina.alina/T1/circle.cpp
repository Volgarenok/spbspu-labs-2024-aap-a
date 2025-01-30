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

duhanina::Circle::Circle(const point_t& pos, double radius):
  Circle(pos, radius, defaultNumParts_)
{}

duhanina::Circle::Circle(const point_t& pos, double radius, size_t numParts):
  numParts_(numParts),
  ellipses_(createArray(pos, radius, numParts))
{}

duhanina::Circle::~Circle()
{
  destroy(ellipses_, numParts_);
  delete[] ellipses_;
}

double duhanina::Circle::getArea() const
{
  return ellipses_[0]->getArea() * numParts_;
}

duhanina::rectangle_t duhanina::Circle::getFrameRect() const
{
  return ellipses_[numParts_ - 1]->getFrameRect();
}

void duhanina::Circle::move(const point_t& newPos)
{
  for (size_t i = 0; i < numParts_; ++i)
  {
    ellipses_[i]->move(newPos);
  }
}

void duhanina::Circle::move(double dx, double dy)
{
  point_t pos = ellipses_[0]->getFrameRect().pos;
  movePoint(pos, dx, dy);
  move(pos);
}

void duhanina::Circle::scaleUnsafe(double k) noexcept
{
  for (size_t i = 0; i < numParts_; ++i)
  {
    ellipses_[i]->scaleUnsafe(k);
  }
}
