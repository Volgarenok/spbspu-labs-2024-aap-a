#include "shapeManipulations.hpp"
#include <iostream>

namespace kushekbaev
{
  double getTotalArea(Shape** capacity, size_t shapeCounter)
  {
    double total = 0;
    for (size_t i = 0; i < shapeCounter; i++)
    {
      if (capacity[i])
      {
        total += capacity[i] -> getArea();
      }
    }
    return total;
  }

  void totalScaling(Shape** capacity, size_t shapeCounter, point_t scalePoint, double scaleCoeff)
  {
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      if (capacity[i])
      {
        capacity[i]->scaleEverything(scalePoint, scaleCoeff);
      }
    }
  }

  void coordOutput(Shape** capacity, size_t shapeCounter, std::ostream& output)
  {
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      if (capacity[i])
      {
        rectangle_t rect = capacity[i]->getFrameRect();
        double leftDownX = rect.pos.x - rect.width / 2;
        double leftDownY = rect.pos.y - rect.height / 2;
        double rightUpX = rect.pos.x + rect.width / 2;
        double rightUpY = rect.pos.y + rect.height / 2;
        output << " " << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
      }
    }
  }

  void clearMemory(Shape** capacity, size_t shapeCounter)
  {
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      delete capacity[i];
      capacity[i] = nullptr;
    }
  }
}
