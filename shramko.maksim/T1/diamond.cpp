#include "diamond.hpp"
#include <stdexcept>
#include <cmath>

shramko::Diamond::Diamond(point_t one, point_t two, point_t three): one_({0.0, 0.0}), two_({0.0, 0.0}), three_({0.0, 0.0})
{
  if ((one.x == two.x && one.y == three.y) || (one.y == two.y && one.x == three.x))
  {
    one_ = one;
    if (one_.x == two.x)
    {
      two_ = two;
      three_ = three;
    }
    else
    {
      two_ = three;
      three_ = two;
    }
  }

  else if ((two.x == one.x && two.y == three.y) || (two.y == one.y && two.x == three.x))
  {
    one_ = two;
    if (one_.x == one.x)
    {
      two_ = one;
      three_ = three;
    }
    else
    {
      two_ = three;
      three_ = one;
    }
  }

  else if ((three.x == two.x && three.y == one.y) || (three.y == two.y && three.x == one.x))
  {
    one_ = three;
    if (one_.x == two.x)
    {
      two_ = two;
      three_ = one;
    }
    else
    {
      two_ = one;
      three_ = two;
    }
  }

  else
  {
    throw std::invalid_argument("Diamond size err\n");
  }
}

double shramko::Diamond::getArea() const
{
  return std::abs(one_.x - two_.x + one_.x - three_.x) * std::abs(one_.y - two_.y + one_.y - three_.y) * 2.0L;
}

shramko::rectangle_t shramko::Diamond::getFrameRect() const
{
  rectangle_t rectFrame;
  rectFrame.pos = one_;

  rectFrame.width = std::abs(three_.x - one_.x) * 2;
  rectFrame.height = std::abs(two_.y - one_.y) * 2;

  return rectFrame;
}

void shramko::Diamond::move(double x, double y)
{
  one_.x += x;
  one_.y += y;

  two_.x += x;
  two_.y += y;

  three_.x += x;
  three_.y += y;
}

void shramko::Diamond::move(point_t point)
{
  double xMove = point.x - one_.x;
  double yMove = point.y - one_.y;

  move(xMove, yMove);
}

void shramko::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Diamond scale err\n");
  }

  two_.y = (one_.y - two_.y) * k + one_.y;
  three_.x = (one_.x - three_.x) * k + one_.x;
}
