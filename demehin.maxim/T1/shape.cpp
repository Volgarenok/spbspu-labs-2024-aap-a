#include "shape.hpp"
#include <stdexcept>

void demehin::Shape::defaultScale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("incorrect_scale");
  }

  scale(k);
}
