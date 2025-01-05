#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>
#include "destroy.hpp"
#include "printResult.hpp"
#include "ellipse.hpp"
#include "movingPoint.hpp"

duhanina::Rectangle::Rectangle(const point_t& lt, const point_t& rt):
  cuts_(1),
  ellWidth_(1),
  ellHeight_(1)
{
  if (lt.x >= rt.x || lt.y >= rt.y)
  {
    throw std::invalid_argument("Error in parameters");
  }
  ellipses_ = fillWithEllipses(lt, rt);
}

double duhanina::Rectangle::getArea() const
{
  double width = ellWidth_ * std::sqrt(cuts_);
  double height = ellHeight_ * std::sqrt(cuts_);
  return width * height;
}

duhanina::rectangle_t duhanina::Rectangle::getFrameRect() const
{
  double width = ellWidth_ * std::sqrt(cuts_);
  double height = ellHeight_ * std::sqrt(cuts_);
  double sumX = 0;
  double sumY = 0;
  for (size_t i = 0; i < cuts_; ++i)
  {
    sumX += ellipses_[i]->getFrameRect().pos.x;
    sumY += ellipses_[i]->getFrameRect().pos.y;
  }
  return { { sumX / cuts_, sumY / cuts_ }, width, height };
}

void duhanina::Rectangle::move(const point_t& newPos)
{
  point_t pos = this->getFrameRect().pos;
  point_t offset = calculateOffset(pos, newPos);
  move(offset.x, offset.y);
}

void duhanina::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < cuts_; ++i)
  {
    ellipses_[i]->move(dx, dy);
  }
}

void duhanina::Rectangle::scale(double k)
{
  for (size_t i = 0; i < cuts_; ++i)
  {
    ellipses_[i]->scale(k);
  }
  ellWidth_ *= k;
  ellHeight_ *= k;
}

duhanina::Shape** duhanina::Rectangle::fillWithEllipses(const point_t& lt, const point_t& rt)
{
  double rectArea = getArea();
  double ellipsesArea = 0.0;
  Shape** ellipses = nullptr;
  ellWidth_ = (rt.x - lt.x) / std::sqrt(cuts_);
  ellHeight_ = (rt.y - lt.y) / std::sqrt(cuts_);
  while (std::fabs(rectArea - ellipsesArea) >= 0.5)
  {
    if (cuts_ > 10000)
    {
      throw std::runtime_error("Maximum number of ellipses");
    }
    ellipses = new Shape*[cuts_] {};
    for (size_t i = 0; i < cuts_; ++i)
    {
      point_t center = { lt.x + (i + 0.5) * ellWidth_, lt.y + (i + 0.5) * ellHeight_ };
      ellipses[i] = new Ellipse(center, ellWidth_ / 2, ellHeight_ / 2);
    }
    ellipsesArea = calcArea(ellipses, cuts_);
    if (std::fabs(rectArea - ellipsesArea) >= 0.5)
    {
      destroy(ellipses, cuts_);
      delete[] ellipses;
      cuts_ = (std::sqrt(cuts_) + 1) * (std::sqrt(cuts_) + 1);
    }
  }
  return ellipses;
}
