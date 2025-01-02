#include "shape.hpp"

void savintsev::Shape::scale(double k)
{
  if (k <= 0)
  {
    return;
  }
  this->doScale(k);
}
