#include "shapeChanger.hpp"
#include <iomanip>

void balashov::printShapeInfo(Shape** shapes, size_t shapeCount)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      totalArea += shapes[i]->getArea();
    }
  }

  std::cout << std::fixed << std::setprecision(1) << totalArea;

  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      rectangle_t frame = shapes[i]->getFrameRect();
      std::cout << " " << frame.pos.x - frame.width / 2.0 << " ";
      std::cout << frame.pos.y - frame.height / 2.0 << " ";
      std::cout << frame.pos.x + frame.width / 2.0 << " ";
      std::cout << frame.pos.y + frame.height / 2.0;
    }
  }
  std::cout << "\n";
}

void balashov::scaling(Shape** shapes, size_t shapeCount, point_t point, double scalingFactor)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    point_t pos = shapes[i]->getFrameRect().pos;
    shapes[i]->move(point);
    point_t newPos = shapes[i]->getFrameRect().pos;
    point_t vectorToMove = {};
    vectorToMove.x = (newPos.x - pos.x) * scalingFactor;
    vectorToMove.y = (newPos.y - pos.y) * scalingFactor;
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(vectorToMove.x * -1, vectorToMove.y * -1);
  }
}
