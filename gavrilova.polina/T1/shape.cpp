#include "shape.hpp"
void gavrilova::Shape::scale(double k)
{
  if (k <= 0) {
    throw std::logic_error("Коэффицент должен быть положительным");
  }
  scaleWithoutCheck(k);
}
