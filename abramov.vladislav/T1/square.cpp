#include "square.hpp"
#include <stdexcept>

namespace abramov
{
  Square::Square(point_t p, double len):
    rect_(Rectangle(p, {p.x + len, p.y + len}))
  {
    if (len <= 0)
    {
      throw std::logic_error("It is impossible to build square\n");
    }
  }

  Square::Square(Rectangle rect):
   rect_(rect)
  {}

  double Square::getArea() const noexcept
  {
    return rect_.getArea();
  }

  rectangle_t Square::getFrameRect() const noexcept
  {
    return rect_.getFrameRect();
  }

  void Square::move(double dx, double dy)
  {
    rect_.move(dx, dy);
  }

  void Square::move(point_t p)
  {
    rect_.move(p);
  }

  void Square::scale(double k)
  {
    rect_.scale(k);
  }

  Square *Square::clone() const
  {
    return new Square(*this);
  }

  Rectangle Square::getRect() const
  {
    return rect_;
  }
}
