﻿#include <string>
#include <iostream>
#include "outputFunctions.hpp"

int main()
{
  asafov::Shape** shapes = new asafov::Shape*[10000];
  size_t count = 0;
  std::string name;
  while (name != "SCALE")
  {
    name = asafov::getName(std::cin);
    if (name[0] == '\0')
    {
      asafov::deleteShapes(shapes, count);
      std::cerr << "in err\n";
      return 1;
    }
    else if (name == "SCALE")
    {
      break;
    }
    else
    {
      try
      {
        shapes[count] = asafov::makeShape(name, std::cin);
      }
      catch (const std::logic_error &)
      {
        std::cerr << "shape err\n";
        count--;
      }
      count++;
    }
  }

  double scale = 0;
  double x = 0;
  double y = 0;
  std::cin >> x >> y >> scale;
  asafov::point_t pos = { x, y };
  if (scale <= 0)
  {
    asafov::deleteShapes(shapes, count);
    return 1;
  }
  try
  {
    scaleShapes(shapes, count, pos, scale, std::cout);
    std::cout << '\n';
  }
  catch (const std::logic_error &)
  {
    asafov::deleteShapes(shapes, count);
    return 1;
  }
  asafov::deleteShapes(shapes, count);
  return 0;
}
