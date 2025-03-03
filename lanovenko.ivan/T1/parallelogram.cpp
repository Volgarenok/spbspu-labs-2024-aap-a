#include "parallelogram.hpp"
#include <stdexcept>

lanovenko::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  first_(p1),
  second_(p2),
  third_(p3)
{
  double orientedArea = this->getArea();
  if (orientedArea == 0)
  {
    throw std::invalid_argument("Wrong parallelogram parametrs!\n");
  }
  if (!((first_.y == second_.y) || (first_.y == third_.y) || (second_.y == third_.y)))
  {
    throw std::invalid_argument("Wrong parallelogram parametrs!\n");
  }
}

double lanovenko::Parallelogram::getArea() const
{
  return std::abs((first_.x * (second_.y - third_.y) + second_.x * (third_.y - first_.y) + third_.x * (first_.y - second_.y)));
}

lanovenko::rectangle_t lanovenko::Parallelogram::getFrameRect() const
{
  double up = std::max(first_.y, std::max(second_.y, third_.y));
  double down = std::min(first_.y, std::min(second_.y, third_.y));
  double right = std::max(first_.x, std::max(second_.x, third_.x));
  double left = std::min(first_.x, std::min(second_.x, third_.x));
  point_t rectFirst = { left, down };
  point_t rectSecond = { left, up };
  point_t rectThird = { right, up };
  point_t rectFourth = { right, down };
  double centerGravityX = (rectFirst.x + rectSecond.x + rectThird.x + rectFourth.x) / 4.0;
  double centerGravityY = (rectFirst.y + rectSecond.y + rectThird.y + rectFourth.y) / 4.0;
  point_t gravityCenter = { centerGravityX, centerGravityY };
  double width = right - left;
  double height = up - down;
  return { width, height, gravityCenter };
}

void lanovenko::Parallelogram::move(point_t p)
{
  double centerX = (first_.x + second_.x + third_.x) / 3.0;
  double centerY = (first_.y + second_.y + third_.y) / 3.0;
  point_t center = { centerX, centerY };
  double deltaX = p.x - center.x;
  double deltaY = p.y - center.y;
  move(deltaX, deltaY);
}

void lanovenko::Parallelogram::move(double dx, double dy)
{
  point_t* points[3] = { &first_, &second_, &third_ };
  for (size_t i = 0; i < 3; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void lanovenko::Parallelogram::unsafeScale(double k)
{
  double centerX = (first_.x + second_.x + third_.x) / 3.0;
  double centerY = (first_.y + second_.y + third_.y) / 3.0;
  point_t center = { centerX, centerY };
  point_t* points[3] = { &first_, &second_, &third_ };
  for (size_t i = 0; i < 3; i++)
  {
    points[i]->x = center.x + (points[i]->x - center.x) * k;
    points[i]->y = center.y + (points[i]->y - center.y) * k;
  }
}
