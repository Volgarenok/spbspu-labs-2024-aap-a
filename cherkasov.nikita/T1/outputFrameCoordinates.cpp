#include  "outputFrameCoordinates.h"
void cherkasov::outputFrameCoordinates(Shape* shapes[], size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shapes[i]->getFrameRect();
  }
}
