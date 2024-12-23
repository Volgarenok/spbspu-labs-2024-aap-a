#include "regular.hpp"
#include <cmath>
#include <stdexcept>

void balashov::Regular::move(double x, double y)
{
  firstPoint_.x += x;
  firstPoint_.y += y;
  secondPoint_.x += x;
  secondPoint_.y += y;
  thirdPoint_.x += x;
  thirdPoint_.y += y;
}
void balashov::Regular::move(const point_t pointRoute)
{
  secondPoint_.x += pointRoute.x - firstPoint_.x;
  secondPoint_.y += pointRoute.y - firstPoint_.y;
  thirdPoint_.x += pointRoute.x - firstPoint_.x;
  thirdPoint_.y += pointRoute.y - firstPoint_.y;
  firstPoint_ = pointRoute;
}

