#include "deleteShapes.h"

void cherkasov::deleteShapes(Shape* shapes[], size_t& shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
  shapeCount = 0;
}
