#include "shape.hpp"

void dirti::Shape::scale(double koef)
{
  if (koef <= 0.0)
  {
    throw std::invalid_argument("Wrong koef");
  }
  unsafeScale(koef);
}