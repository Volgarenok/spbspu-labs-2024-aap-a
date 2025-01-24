#include "shape.hpp"
#include <stdexcept>

void demehin::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("incorrect_scale");
  }

  scaleUnsafely(k);
}
