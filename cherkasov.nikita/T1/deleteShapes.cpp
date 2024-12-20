#include "deleteShapes.h"
void cherkasov::deleteShapes(Shape* shapes[], size_t& shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
  if (shapes[i] != nullptr)
  {
    delete shapes[i];
  }
    shapes[i] = nullptr;
  }
  shapeCount = 0;
}
