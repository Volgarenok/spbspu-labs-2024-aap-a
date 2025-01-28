#include <iostream>
#include <iomanip>
#include <string>
#include "dynamicinput.h"
#include "makeshape.hpp"
#include "rectanglepoints.hpp"
#include "listCommand.hpp"

int main()
{
  averenkov::Shape* shapes[10000];
  size_t shapeCount = 0;
  bool hasErrors = false;
  std::string command;
  while (shapeCount < 10000 && std::cin >> command && command != "SCALE")
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
    }
    catch (const std::invalid_argument&)
    {
      hasErrors = true;
    }
  }
  if (std::cin.eof())
  {
    std::cerr << "No scale\n";
    averenkov::destroy(shapes, shapeCount);
    return 1;
  }
  if (shapeCount == 0)
  {
    std::cerr << "Nothing to scale\n";
    return 1;
  }
  averenkov::point_t scaling_center = { 0.0, 0.0 };
  double factor = 0.0;
  try
  {
    averenkov::makeScale(factor, scaling_center, std::cin);
  }
  catch(...)
  {
    averenkov::destroy(shapes, shapeCount);
    std::cerr << "Invalid scale\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  averenkov::printList(shapes, shapeCount);
  averenkov::scaleList(shapes, shapeCount, scaling_center, factor);
  averenkov::printList(shapes, shapeCount);
  averenkov::destroy(shapes, shapeCount);
  if (hasErrors)
  {
    std::cerr << "Errors descriptions\n";
  }
  return 0;
}
