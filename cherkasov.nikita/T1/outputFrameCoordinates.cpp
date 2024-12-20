#include  "outputFrameCoordinates.h"
#include <iostream>
void cherkasov::outputFrameCoordinates(Shape* shapes[], size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << "Width: " << frame.width;
    std::cout << " Height: " << frame.height;
    std::cout << " Position: (" << frame.pos.x << " " << frame.pos.y << ")\n";
  }
}
