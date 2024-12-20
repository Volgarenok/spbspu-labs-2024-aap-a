#include "regular.hpp"
#include <cmath>
#include <stdexcept>

void balashov::Regular::move(double x, double y)
{
  firstPoint_.x_ += x;
  firstPoint_.y_ += y;
  secondPoint_.x_ += x;
  secondPoint_.y_ += y;
  thirdPoint_.x_ += x;
  thirdPoint_.y_ += y;
}
void balashov::Regular::move(const point_t pointRoute)
{
  secondPoint_.x_ += pointRoute.x_ - firstPoint_.x_;
  secondPoint_.y_ += pointRoute.y_ - firstPoint_.y_;
  thirdPoint_.x_ += pointRoute.x_ - firstPoint_.x_;
  thirdPoint_.y_ += pointRoute.y_ - firstPoint_.y_;
  firstPoint_ = pointRoute;
}

