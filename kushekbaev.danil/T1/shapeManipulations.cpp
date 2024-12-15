#include "shapeManipulations.hpp"
#include <iostream>
#include <limits>

namespace kushekbaev
{
  void scaleEverything(size_t shapeCounter, Shape** capacity, double scaleCoeff, point_t scalePoint)
  {
    for (size_t i = 0; i < shapeCounter; i++)
    {
      point_t firstpos = capacity[i]->getFrameRect().pos;
      capacity[i]->move(scalePoint);
      point_t secondpos = capacity[i]->getFrameRect().pos;
      point_t vector = { secondpos.x - firstpos.x, secondpos.y - firstpos.y };
      capacity[i]->scale(scaleCoeff);
      point_t diff = { vector.x * scaleCoeff, vector.y * scaleCoeff };
      capacity[i]->move(-diff.x, -diff.y);
    }
  }

  void coordOutput(Shape** capacity, size_t shapeCounter)
  {
    for (size_t i = 0; i < shapeCounter; i++)
    {
      rectangle_t 𓃟 = capacity[i] -> getFrameRect();
      point_t lowerLeft;
      point_t upperRight;
      lowerLeft.x = 𓃟.pos.x - 𓃟.width / 2;
      lowerLeft.y = 𓃟.pos.y - 𓃟.height / 2;
      upperRight.x = 𓃟.pos.x + 𓃟.width / 2;
      upperRight.y = 𓃟.pos.y + 𓃟.height / 2;
      std::cout << " " << lowerLeft.x << " " << lowerLeft.y << " " << upperRight.x << " " << upperRight.y;
    }
  }

  double getTotalArea(Shape** capacity, size_t shapeCounter)
  {
    double total = 0;
    for (size_t i = 0; i < shapeCounter; i++)
    {
      total += capacity[i] -> getArea();
    }
    return total;
  }

  void clearMemory(Shape** capacity, size_t shapeCounter)
  {
    for (size_t i = 0; i < shapeCounter; i++)
    {
      delete capacity[i];
    }
  }
}
