#include  "outputFrameCoordinates.h"
#include <iostream>
void cherkasov::outputFrameCoordinates(Shape* shapes[], size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << frame.width << " " << frame.height << " " << frame.pos.x << " " << frame.pos.y << "\n";
  }
}
