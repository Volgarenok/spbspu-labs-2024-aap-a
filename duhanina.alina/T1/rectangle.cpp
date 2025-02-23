#include "rectangle.hpp"
#include <stdexcept>
#include "movingPoint.hpp"

duhanina::Rectangle::Rectangle(const point_t& lt, const point_t& rt):
  lt_(lt),
  rt_(rt)
{
  if (lt.x >= rt.x || lt.y >= rt.y)
  {
    throw std::invalid_argument("Error in parameters");
  }
}

double duhanina::Rectangle::getArea() const
{
  return (rt_.x - lt_.x) * (rt_.y - lt_.y);
}

duhanina::rectangle_t duhanina::Rectangle::getFrameRect() const
{
  double width = rt_.x - lt_.x;
  double height = rt_.y - lt_.y;
  double posX = lt_.x + (width / 2.0);
  double posY = lt_.y + (height / 2.0);
  return { { posX, posY }, width, height };
}

void duhanina::Rectangle::move(const point_t& newPos)
{
  point_t pos = getFrameRect().pos;
  point_t offset = calculateOffset(pos, newPos);
  move(offset.x, offset.y);
}

void duhanina::Rectangle::move(double dx, double dy)
{
  movePoint(lt_, dx, dy);
  movePoint(rt_, dx, dy);
}

void duhanina::Rectangle::scaleUnsafe(double k) noexcept
{
  point_t pos = getFrameRect().pos;
  lt_ = scalePoint(lt_, pos, k);
  rt_ = scalePoint(rt_, pos, k);
}
