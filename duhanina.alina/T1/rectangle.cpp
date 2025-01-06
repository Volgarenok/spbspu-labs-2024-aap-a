#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>
#include "destroy.hpp"
#include "printResult.hpp"
#include "ellipse.hpp"
#include "movingPoint.hpp"

duhanina::Rectangle::Rectangle(const point_t& lt, const point_t& rt):
  cuts_(1),
  ellipses_(nullptr),
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
  double width = ellWidth_ * cuts_;
  double height = ellHeight_ * cuts_;
  return width * height;
}

duhanina::rectangle_t duhanina::Rectangle::getFrameRect() const
{
  double width = ellWidth_ * cuts_;
  double height = ellHeight_ * cuts_;
  double sumX = 0;
  double sumY = 0;
  for (size_t i = 0; i < (cuts_ * cuts_); ++i)
  {
    sumX += ellipses_[i]->getFrameRect().pos.x;
    sumY += ellipses_[i]->getFrameRect().pos.y;
  }
  return { { sumX / (cuts_ * cuts_), sumY / (cuts_ * cuts_) }, width, height };
}

void duhanina::Rectangle::move(const point_t& newPos)
{
  point_t pos = this->getFrameRect().pos;
  point_t offset = calculateOffset(pos, newPos);
  move(offset.x, offset.y);
}

void duhanina::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < (cuts_ * cuts_); ++i)
  {
    ellipses_[i]->move(dx, dy);
  }
}

void duhanina::Rectangle::scale(double k)
{
  for (size_t i = 0; i < (cuts_ * cuts_); ++i)
  {
    ellipses_[i]->scale(k);
  }
  ellWidth_ *= k;
  ellHeight_ *= k;
}

duhanina::Shape** duhanina::Rectangle::fillWithEllipses(const point_t& lt, const point_t& rt)
{
  double rectArea = (rt.x - lt.x) * (rt.y - lt.y);
  double ellipsesArea = 0.0;
  Shape** ell = nullptr;
  while (std::fabs(rectArea - ellipsesArea) > 1)
  {
    size_t ellCount = cuts_ * cuts_;
    ellWidth_ = (rt.x - lt.x) / cuts_;
    ellHeight_ = (rt.y - lt.y) / cuts_;
    Shape** ellipses = nullptr;
    ellipses = new Shape*[ellCount] {};
    for (size_t i = 0; i < cuts_; ++i)
    {
      for (size_t j = 0; j < cuts_; ++j)
      {
        point_t center = { lt.x + (i + 0.5) * ellWidth_, lt.y + (j + 0.5) * ellHeight_ };
        ellipses[i * cuts_ + j] = new Ellipse(center, ellWidth_ / 2, ellHeight_ / 2);
      }
    }
    ellipsesArea = calcArea(ellipses, ellCount);
    if (std::fabs(rectArea - ellipsesArea) > 1)
    {
      cuts_++;
    }
    if (cuts_ > 100)
    {
      destroy(ellipses, ellCount);
      delete[] ellipses;
      throw std::invalid_argument("Maximum number of ellipses");
    }
    if (std::fabs(rectArea - ellipsesArea) <= 1)
    {
        ell = ellipses;
        break;
    }
    destroy(ellipses, ellCount);
    delete[] ellipses;
  }
  return ell;
}
