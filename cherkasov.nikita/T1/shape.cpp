#include "shape.hpp"
#include <stdexcept>

void cherkasov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("k must be positive");
  }
  scalingFactor(k);
}