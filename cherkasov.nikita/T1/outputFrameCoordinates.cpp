#include  "outputFrameCoordinates.h"
#include <iostream>
/*void cherkasov::outputFrameCoordinates(Shape* shapes[], size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; i++)
  {
    rectangle_t rectangle = shapes[i]->getFrameRect();
    double x1 = rectangle.pos.x - rectangle.width / 2.0;
    double y1 = rectangle.pos.y - rectangle.height / 2.0;
    double x2 = rectangle.pos.x + rectangle.width / 2.0;
    double y2 = rectangle.pos.y + rectangle.height / 2.0;
    std::cout << " " << x1 << " " << y1 << " " << x2 << " " << y2;
  }
  std::cout << "\n";
}*/
void cherkasov::outputFrameCoordinates(Shape* shapes[], size_t shapeCount)
{
    for (size_t i = 0; i < shapeCount; ++i)
    {
        rectangle_t rectangle = shapes[i]->getFrameRect();
        std::cout << rectangle.width << " " << rectangle.height << " " << rectangle.pos.x << " " << rectangle.pos.y << "\n";
    }
}
