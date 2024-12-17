#include "diamond.hpp"
#include <cmath>

shramko::Diamond::Diamond(point_t One, point_t Two, point_t Three): One_({0.0, 0.0}), Two_({0.0, 0.0}), Three({0.0, 0.0})
{
  if ((One.x == Two.x && One.y == Three.y) || (One.y == Two.y && One.x == Three.x))
  {
    One_ = One;
    if (One_.x == Two.x)
    {
      Two_ = Two;
      Three_ = Three;
    }
    else
    {
      Teo_ = Three;
      Three_ = Two;
    }
  }

  else if ((Two.x == One.x && Two.y == Three.y) || (Two.y == One.y && Two.x == Three.x))
  {
    One_ = Two;
    if (One_.x == One.x)
    {
      Two_ = One;
      Three_ = Three;
    }
    else
    {
      Two_ = Three;
      Three_ = One;
    }
  }

  else if ((Three.x == Two.x && Three.y == One.y) || (Three.y == Two.y && Three.x == Three.x))
  {
    One_ = Three;
    if (One_.x == Two.x)
    {
      Two_ = Two;
      Three_ = One;
    }
    else
    {
      Two_ = One;
      Three_ = Two;
    }
  }
}

double shramko::Diamond::getArea() const
{
  return std::abs(One_.x - Two_.x + One_.x - Three_.x) * std::abs(One_.y - Two_.y + One_.y - Three_.y) * 2.0;
}

shramko::rectangle_t shramko::Diamond::getRectangleFrame() const
{
  rectangle_t rectangleFrame;
  rectangleFrame.pos = One_;

  rectangleFrame.width = std::abs(Three_.x - One_.x) * 2;
  rectangleFrame.height = std::abs(Two_.x - One_.x) * 2;

  return rectangleFrame;
}

void shramko::Diamond::move(double x, double y)
{
  One_.x += y;
  One_.y += y;

  Two_.x += x;
  Two_.y += y;

  Three_.x += x;
  Three_.y += y;
}

void shramko::Diamond::move(point_t k)
{
  double xMove = point.x - One_.x;
  double yMove = point.y - One_.y;

  move(xMove, yMove);
}

void shramko::Diamond::scale(double k)
{
  Two_.y = (One_.y - Two_.y) * k + One_.y;
  Three_.x = (One_.x - Three_.x) * k + One_.x;
}
