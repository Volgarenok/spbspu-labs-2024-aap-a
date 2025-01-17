#include <iostream>
#include <memory>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "rectangle.hpp"
#include "rectanglepoints.hpp"
#include "dynamicinput.h"
#include "ellipse.hpp"
#include "diamond.hpp"
#include "getline.hpp"
#include "shapeScale.hpp"
#include "makeshape.hpp"

int main()
{
  averenkov::Shape* shapes[10000];
  size_t shapeCount = 0;
  bool hasErrors = false;
  bool hasScale = false;
  averenkov::point_t scale_center;
  double factor;
  std::string command;
  while (shapeCount < 10000 && std::cin >> command)
  {
    try
    {
      if (command.empty())
      {
        continue;
      }
      else if (command == "RECTANGLE")
      {
        averenkov::makeRectangle(shapes, shapeCount, std::cin, hasErrors);
      }
      else if (command == "ELLIPSE")
      {
        averenkov::makeEllipse(shapes, shapeCount, std::cin, hasErrors);
      }
      else if (command == "DIAMOND")
      {
        averenkov::makeDiamond(shapes, shapeCount, std::cin, hasErrors);
      }
      else if (command == "SCALE")
      {
        hasScale = true;
        if (shapeCount == 0)
        {
          std::cerr << "Nothing to scale\n";
          return 1;
        }
        if (!(std::cin >> scale_center.x >> scale_center.y >> factor) || factor <= 0)
        {
          for (size_t i = 0; i < shapeCount; ++i)
          {
            delete shapes[i];
          }
          std::cerr << "Invalid scale\n";
          return 1;
        }
        break;
      }
    }
    catch (const std::invalid_argument&)
    {
      hasErrors = true;
    }
  }
  if (std::cin.eof() && !hasScale)
  {
    std::cerr << "No scale\n";
    for(size_t i = 0; i < shapeCount; ++i)
    {
      delete shapes[i];
    }
    return 1;
  }
  double sum = 0;
  std::cout << std::fixed << std::setprecision(1);
  for (size_t i = 0; i < shapeCount; ++i)
  {
    sum += shapes[i]->getArea();
  }
  std::cout << sum;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    std::cout << " " << averenkov::getLeftBot(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).y << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).y;
    shapes[i]->scale(factor);
    averenkov::shapeScale(shapes[i], scale_center, factor);
    sum += shapes[i]->getArea();
  }
  std::cout << "\n";
  sum = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    sum += shapes[i]->getArea();
  }
  std::cout << sum;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    std::cout << " " << averenkov::getLeftBot(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).y << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).y;
    delete shapes[i];
  }
  std::cout << "\n";
  if (hasErrors)
  {
    std::cerr << "Errors descriptions\n";
  }
  return 0;
}
