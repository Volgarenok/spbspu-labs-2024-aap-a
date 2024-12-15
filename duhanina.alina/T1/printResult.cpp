#include "printResult.hpp"
#include <iostream>
#include <iomanip>
#include <cstddef>

void duhanina::printFiguresInfo(Shape** shapes, size_t shapeCount)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      totalArea += shapes[i]->getArea();
    }
  }

  std::cout << std::fixed << std::setprecision(1) << totalArea << " ";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      rectangle_t frame = shapes[i]->getFrameRect();
      std::cout << frame.pos.x - frame.width / 2.0 << " ";
      std::cout << frame.pos.y - frame.height / 2.0 << " ";
      std::cout << frame.pos.x + frame.width / 2.0 << " ";
      std::cout << frame.pos.y + frame.height / 2.0 << "\n";
    }
  }
}

void duhanina::processScaling(Shape** shapes, size_t shapeCount, point_t point, double scalingFactor)
{
  printFiguresInfo(shapes, shapeCount);
  for (size_t i = 0; i < shapeCount; ++i)
  {
    duhanina::point_t pos = shapes[i]->getFrameRect().pos;
    shapes[i]->move(point);
    duhanina::point_t newPos = shapes[i]->getFrameRect().pos;
    duhanina::point_t vect;
    vect.x = (newPos.x - pos.x) * scalingFactor;
    vect.y = (newPos.y - pos.y) * scalingFactor;
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(vect.x * -1, vect.y * -1);
  }
  printFiguresInfo(shapes, shapeCount);
}
