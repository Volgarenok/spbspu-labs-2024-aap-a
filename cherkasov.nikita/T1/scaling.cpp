#include "scaling.h"
void cherkasov::scaling(Shape* shapes[], size_t shapeCount, double factor)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shapes[i]->scale(factor);
  }
}
