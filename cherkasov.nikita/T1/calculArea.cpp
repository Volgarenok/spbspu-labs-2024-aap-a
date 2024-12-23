#include "calculArea.hpp"
#include <cstddef>
double cherkasov::calculArea(Shape* shapes[], size_t shapeCount)
{
  double totalArea = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalArea += shapes[i]->getArea();
  }
  return totalArea;
}
