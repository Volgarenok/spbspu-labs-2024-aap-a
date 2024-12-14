#include "shapeManipulations.hpp"
#include <iostream>
#include <limits>

namespace kushekbaev
{
  Rectangle* createRectangle(std::istream& input)
  {
    point_t lowerLeft;
    point_t upperRight;
    input >> lowerLeft.x >> lowerLeft.y >> upperRight.x >> upperRight.y;
    if (!(input >> lowerLeft.x >> lowerLeft.y >> upperRight.x >> upperRight.y))
    {
      input.clear();
      input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    Rectangle* 𓃟 = new Rectangle(lowerLeft, upperRight);
    return 𓃟;
  }

  void scaleEverything(size_t shapeCounter, Shape** capacity, double scaleCoeff)
  {
    for (size_t i = 0; i < shapeCounter; i++)
    {
      point_t pos = capacity[i] -> getFrameRect().pos;
      capacity[i] -> move(-pos.x, -pos.y);
      capacity[i] -> scale(scaleCoeff);
      capacity[i] -> move(pos.x, pos.y);
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
      lowerLeft.y = 𓃟.pos.y - 𓃟.length / 2;
      upperRight.x = 𓃟.pos.x + 𓃟.width / 2;
      upperRight.y = 𓃟.pos.y + 𓃟.width / 2;
      std::cout << " " << lowerLeft.x << " " << lowerLeft.y << " " << upperRight.x << " " << upperRight.y << "\n";
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
