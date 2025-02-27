#include "square.hpp"
#include <stdexcept>

abramov::Square::Square(const point_t &p, double len):
  rect_({ p, { p.x + len, p.y + len } })
{
  if (len <= 0)
  {
    throw std::logic_error("It is impossible to build square\n");
  }
}

double abramov::Square::getArea() const noexcept
{
  return rect_.getArea();
}

abramov::rectangle_t abramov::Square::getFrameRect() const noexcept
{
  return rect_.getFrameRect();
}

void abramov::Square::move(double dx, double dy)
{
  rect_.move(dx, dy);
}

void abramov::Square::move(const point_t &p)
{
  rect_.move(p);
}

void abramov::Square::scale(double k)
{
  rect_.scale(k);
}

abramov::Square *abramov::Square::clone() const
{
  return new Square(*this);
}

