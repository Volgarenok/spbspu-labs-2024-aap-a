#include <iostream>
#include <string>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "square.hpp"
#include "processShapes.hpp"
#include "createShapes.hpp"

int main()
{
  smirnov::Shape * shapes[1000] = {};
  size_t shapeCount = 0;
  std::string nameShape = "";
  bool flag = false;
  double k = 0.0;
  smirnov::point_t scaleCenter = {0.0, 0.0};
  while (true)
  {
    if (std::cin.eof())
    {
      std::cerr << "Incorrect scale\n";
      smirnov::destroyShape(shapes, shapeCount);
      return 1;
    }
    std::cin >> nameShape;
    if (nameShape == "RECTANGLE")
    {
      try
      {
        shapes[shapeCount] = smirnov::createRectangle(std::cin);
        shapeCount++;
      }
      catch (const std::invalid_argument & e)
      {
        flag = true;
      }
    }
    else if (nameShape == "DIAMOND")
    {
      try
      {
        shapes[shapeCount] = smirnov::createDiamond(std::cin);
        shapeCount++;
      }
      catch (const std::invalid_argument & e)
      {
        flag = true;
      }
    }
    else if (nameShape == "SQUARE")
    {
      try
      {
        shapes[shapeCount] = smirnov::createSquare(std::cin);
        shapeCount++;
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << "Out of memory\n";
        smirnov::destroyShape(shapes, shapeCount);
        return 1;
      }
      catch (const std::invalid_argument & e)
      {
        flag = true;
      }
    }
    else if (nameShape == "SCALE")
    {
      double p1 = 0.0;
      double p2 = 0.0;
      std::cin >> p1 >> p2;
      scaleCenter = {p1, p2};
      std::cin >> k;
      break;
    }
  }
  if (k <= 0)
  {
    std::cerr << "Incorrect scale\n";
    smirnov::destroyShape(shapes, shapeCount);
    return 1;
  }
  if (shapeCount == 0)
  {
    std::cerr << "There are no shapes\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << smirnov::sumArea(shapes, shapeCount);
  smirnov::printFrameRect(shapes, shapeCount);
  smirnov::scaleShape(shapes, shapeCount, scaleCenter, k);
  std::cout << smirnov::sumArea(shapes, shapeCount);
  smirnov::printFrameRect(shapes, shapeCount);
  smirnov::destroyShape(shapes, shapeCount);
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}
