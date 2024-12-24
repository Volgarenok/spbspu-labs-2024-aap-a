#include "procesShape.hpp"
#include "base-types.hpp"
#include <iostream>

double cherkasov::calculArea(Shape* shapes[], size_t shapeCount)
{
  double totalArea = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalArea += shapes[i]->getArea();
  }
  return totalArea;
}
void cherkasov::deleteShapes(Shape* shapes[], size_t& shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i] != nullptr)
    {
      delete shapes[i];
      shapes[i] = nullptr;
    }
  }
}
void cherkasov::outputFrameCoordinates(Shape* shapes[], size_t shapeCount)
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
}
void cherkasov::scaling(Shape* shapes[], size_t shapeCount, point_t p, double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    std::cerr << "Error: scalingFactor must be positive.\n";
    return;
  }
  for (size_t i = 0; i < shapeCount; i++)
  {
    point_t startPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t newPoint = shapes[i]->getFrameRect().pos;
    point_t newVector;
    newVector.x = (newPoint.x - startPoint.x) * scalingFactor;
    newVector.y = (newPoint.y - startPoint.y) * scalingFactor;
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(-newVector.x, -newVector.y);
  }
}
