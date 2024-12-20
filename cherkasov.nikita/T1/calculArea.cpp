#include "calculArea.h"

double cherkasov::calculArea(Shape* shapes[], size_t shapeCount)
{
  double totalArea = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalArea += shapes[i]->area();
  }
  return totalArea;
}
