#include "diamond.hpp"
#include <cmath>
#include <stdexcept>


ivanova::Diamond::Diamond(point_t topPoint, point_t bottomPoint, point_t center)
    : topPoint_(topPoint), bottomPoint_(bottomPoint), center_(center)
{
    if (topPoint.x == bottomPoint.x)
    {
        if (topPoint.y == bottomPoint.y)
        {
            throw std::invalid_argument("All points are the same");
        }
        else if (topPoint.y == center.y)
        {
            *this = Diamond(bottomPoint, center, topPoint);
        }
        else if (bottomPoint.y == center.y)
        {
            *this = Diamond(topPoint, center, bottomPoint);
        }
        else
        {
            throw std::invalid_argument("Invalid configuration of points");
        }
    }
    else if (topPoint.x == center.x)
    {
        if (topPoint.y == bottomPoint.y)
        {
            *this = Diamond(center, bottomPoint, topPoint);
        }
        else if (topPoint.y == center.y)
        {
            throw std::invalid_argument("Two points are the same");
        }
        else if (bottomPoint.y == center.y)
        {
            *this = Diamond(topPoint, bottomPoint, center);
        }
        else
        {
            throw std::invalid_argument("Invalid configuration of points");
        }
    }
    else if (bottomPoint.x == center.x)
    {
        if (topPoint.y == bottomPoint.y)
        {
            *this = Diamond(center, topPoint, bottomPoint);
        }
        else if (topPoint.y == center.y)
        {
            *this = Diamond(bottomPoint, topPoint, center);
        }
        else if (bottomPoint.y == center.y)
        {
            throw std::invalid_argument("Two points are the same");
        }
        else
        {
            throw std::invalid_argument("Invalid configuration of points");
        }
    }
    else
    {
        throw std::invalid_argument("Invalid configuration of points");
    }
}

double ivanova::Diamond::getArea() const
{
  double d1 = std::fabs(topPoint_.y - bottomPoint_.y);
  double d2 = std::fabs(bottomPoint_.x - center_.x) * 2;
  return (d1 * d2) / 2;
}

ivanova::rectangle_t ivanova::Diamond::getFrameRect() const
{
  double width = std::fabs(bottomPoint_.x - center_.x) * 2;
  double height = std::fabs(topPoint_.y - center_.y) * 2;
  return { width, height, center_ };
}

void ivanova::Diamond::move(point_t point)
{
  double moveX = point.x - center_.x;
  double moveY = point.y - center_.y;
  center_ = point;
  topPoint_ = {topPoint_.x + moveX, topPoint_.y + moveY};
  bottomPoint_ = {bottomPoint_.x + moveX, bottomPoint_.y + moveY};
}

void ivanova::Diamond::move(double x, double y)
{
  center_ = {center_.x + x, center_.y + y};
  topPoint_ = {topPoint_.x + x, topPoint_.y + y};
  bottomPoint_ = {bottomPoint_.x + x, bottomPoint_.y + y};
}

void ivanova::Diamond::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Scale ratio must be positive.");
  }
  topPoint_.x = center_.x + (topPoint_.x - center_.x) * ratio;
  topPoint_.y = center_.y + (topPoint_.y - center_.y) * ratio;
  bottomPoint_.x = center_.x + (bottomPoint_.x - center_.x) * ratio;
  bottomPoint_.y = center_.y + (bottomPoint_.y - center_.y) * ratio;
}
