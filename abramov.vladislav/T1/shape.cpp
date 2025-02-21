#include "shape.hpp"
#include <stdexcept>

void abramov::Shape::scaleSafe(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Wrong scale coef\n");
  }
  scale(k);
}
