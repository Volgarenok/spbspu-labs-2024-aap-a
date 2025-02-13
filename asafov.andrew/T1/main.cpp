#include <string>
#include <iostream>
#include "outputFunctions.hpp"

using asafov::getName;
using asafov::ShapeFactory;
using asafov::scaleShapes;
using asafov::Shape;

int main()
{
  Shape** shapes = new Shape*[10000];
  size_t count = 0;
  std::string name = {};
  while (name != "SCALE")
  {
    name = getName(std::cin);
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
        shapes[count] = ShapeFactory(name, std::cin);
      }
      catch (const std::logic_error &)
      {
        std::cerr << "shape err\n";
        count--;
      }
      count++;
    }
  }

  point_t pos;
  double scale = 0;
  std::cin >> pos.x >> pos.y >> scale;
  if (scale <= 0)
  {
    asafov::deleteShapes(shapes, count);
    return 1;
  }
  try
  {
    scaleShapes(shapes, count, pos, scale, std::cout);
  }
  catch (const std::logic_error & e)
  {
    asafov::deleteShapes(shapes, count);
    return 1;
  }
  asafov::deleteShapes(shapes, count);
  return 0;
}
