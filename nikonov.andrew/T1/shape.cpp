#include "shape.hpp"
#include <stdexcept>
void nikonov::Shape::scaleWithCheck(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Scale denied: k must be more than zero");
  }
  scale(k);
}
